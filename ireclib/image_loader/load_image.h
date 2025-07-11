// Copyright (C) 2011  Davis E. King (davis@ireclib.net), Nils Labugt, Changjiang Yang (yangcha@leidos.com)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{
    namespace image_file_type
    {
        enum type
        {
            BMP,
            JPG,
            PNG,
            DNG,
            GIF,
            WEBP,
            JXL,
            UNKNOWN
        };

        inline type read_type(const std::string& file_name) 
        {
            std::ifstream file(file_name.c_str(), std::ios::in|std::ios::binary);
            if (!file)
                throw image_load_error("Unable to open file: " + file_name);

            char buffer[13];
            file.read((char*)buffer, 12);
            buffer[12] = 0;

            // Determine the true image type using link:
            // http://en.wikipedia.org/wiki/List_of_file_signatures
            static const char *pngHeader = "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A";
            static const char *jxlHeader = "\x00\x00\x00\x0C\x4A\x58\x4C\x20\x0D\x0A\x87\x0A";

            if (buffer[0]=='\xff' && buffer[1]=='\xd8' && buffer[2]=='\xff') 
                return JPG;
            else if (memcmp(buffer, pngHeader, strlen(pngHeader)) == 0)
                return PNG;
            else if (buffer[0]=='B' && buffer[1]=='M') 
                return BMP;
            else if (buffer[0]=='D' && buffer[1]=='N' && buffer[2] == 'G') 
                return DNG;
            else if (buffer[0]=='G' && buffer[1]=='I' && buffer[2] == 'F') 
                return GIF;
            else if ((buffer[0] == '\xff' && buffer[1] == '\x0a') ||
                      memcmp(buffer, jxlHeader, 12) == 0)  // we can't use strlen because the header starts with \x00.
                return JXL;
            else if (buffer[0]=='R' && buffer[1]=='I' && buffer[2] == 'F' && buffer[3] == 'F' &&
                    buffer[8]=='W' && buffer[9]=='E' && buffer[10] == 'B' && buffer[11] == 'P')
                return WEBP;

            return UNKNOWN;
        }
    }

// ----------------------------------------------------------------------------------------

// handle the differences in API between libgif v5 and older.

    template <typename image_type>
    void load_image (
        image_type& image,
        const std::string& file_name
    )
    {
        const image_file_type::type im_type = image_file_type::read_type(file_name);
        switch (im_type)
        {
            case image_file_type::BMP: load_bmp(image, file_name); return;
            case image_file_type::DNG: load_dng(image, file_name); return;
            case image_file_type::PNG: load_png(image, file_name); return;
            case image_file_type::JPG: load_jpeg(image, file_name); return;
            case image_file_type::WEBP: load_webp(image, file_name); return;
            case image_file_type::JXL: load_jxl(image, file_name); return;
            case image_file_type::GIF: 
            {
                image_view<image_type> img(image);
                GifFileType* gif = DGifOpenFileName(file_name.c_str() IRECLIB_GIFLIB_HANDLE_DIFF_VERSIONS);
                try
                {
                    if (gif == 0) throw image_load_error("Couldn't open file " + file_name);
                    if (DGifSlurp(gif) != GIF_OK)
                        throw image_load_error("Error reading from " + file_name);

                    if (gif->ImageCount != 1)   throw image_load_error("IRECLIB only supports reading GIF files containing one image.");
                    if (gif->SavedImages == 0)  throw image_load_error("Unsupported GIF format 1.");

                    ColorMapObject* cmo=gif->SColorMap?gif->SColorMap:gif->SavedImages->ImageDesc.ColorMap;

                    if (cmo==0)                                             throw image_load_error("Unsupported GIF format 2.");
                    if (cmo->Colors == 0)                                   throw image_load_error("Unsupported GIF format 3.");
                    if (gif->SavedImages->ImageDesc.Width != gif->SWidth)   throw image_load_error("Unsupported GIF format 4.");
                    if (gif->SavedImages->ImageDesc.Height != gif->SHeight) throw image_load_error("Unsupported GIF format 5.");
                    if (gif->SavedImages->RasterBits == 0)                  throw image_load_error("Unsupported GIF format 6.");
                    if (gif->Image.Top != 0)                                throw image_load_error("Unsupported GIF format 7.");
                    if (gif->Image.Left != 0)                               throw image_load_error("Unsupported GIF format 8.");

                    img.set_size(gif->SHeight, gif->SWidth);
                    unsigned char* raster = gif->SavedImages->RasterBits;
                    GifColorType* colormap = cmo->Colors;
                    if (gif->Image.Interlace) 
                    {
                        const long interlaced_offset[] = { 0, 4, 2, 1 }; 
                        const long interlaced_jumps[] = { 8, 8, 4, 2 }; 
                        for (int i = 0; i < 4; ++i)
                        {
                            for (long r = interlaced_offset[i]; r < img.nr(); r += interlaced_jumps[i]) 
                            {
                                for (long c = 0; c < img.nc(); ++c)
                                {
                                    if (*raster >= cmo->ColorCount)
                                        throw image_load_error("Invalid GIF color value");
                                    rgb_pixel p;
                                    p.red = colormap[*raster].Red;
                                    p.green = colormap[*raster].Green;
                                    p.blue = colormap[*raster].Blue;
                                    assign_pixel(img[r][c], p);
                                    ++raster;
                                }
                            }
                        }
                    }
                    else 
                    {
                        for (long r = 0; r < img.nr(); ++r)
                        {
                            for (long c = 0; c < img.nc(); ++c)
                            {
                                if (*raster >= cmo->ColorCount)
                                    throw image_load_error("Invalid GIF color value");
                                rgb_pixel p;
                                p.red = colormap[*raster].Red;
                                p.green = colormap[*raster].Green;
                                p.blue = colormap[*raster].Blue;
                                assign_pixel(img[r][c], p);
                                ++raster;
                            }
                        }
                    }
                    DGifCloseFile(gif IRECLIB_GIFLIB_HANDLE_DIFF_VERSIONS);
                }
                catch(...)
                {
                    if (gif)
                        DGifCloseFile(gif IRECLIB_GIFLIB_HANDLE_DIFF_VERSIONS);
                    throw;
                }
                return;
            }
            default:  ;
        }

        if (im_type == image_file_type::JPG)
        {
            std::ostringstream sout;
            sout << "Unable to load image in file " + file_name + ".\n" +
                    "You must #define IRECLIB_JPEG_SUPPORT and link to libjpeg to read JPEG files.\n" +
                    "Do this by following the instructions at http://ireclib.net/compile.html.\n\n";
            sout << "Note that you must cause IRECLIB_JPEG_SUPPORT to be defined for your entire project.\n";
            sout << "So don't #define it in one file. Instead, add it to the C/C++->Preprocessor->Preprocessor Definitions\n";
            sout << "field in Visual Studio's Property Pages window so it takes effect for your entire application.";
            sout << "Note that you must cause IRECLIB_JPEG_SUPPORT to be defined for your entire project.\n";
            sout << "So don't #define it in one file. Instead, use a compiler switch like -DIRECLIB_JPEG_SUPPORT\n";
            sout << "so it takes effect for your entire application.";
            throw image_load_error(sout.str());
        }
        else if (im_type == image_file_type::PNG)
        {
            std::ostringstream sout;
            sout << "Unable to load image in file " + file_name + ".\n" +
                    "You must #define IRECLIB_PNG_SUPPORT and link to libpng to read PNG files.\n" +
                    "Do this by following the instructions at http://ireclib.net/compile.html.\n\n";
            sout << "Note that you must cause IRECLIB_PNG_SUPPORT to be defined for your entire project.\n";
            sout << "So don't #define it in one file. Instead, add it to the C/C++->Preprocessor->Preprocessor Definitions\n";
            sout << "field in Visual Studio's Property Pages window so it takes effect for your entire application.\n";
            sout << "Note that you must cause IRECLIB_PNG_SUPPORT to be defined for your entire project.\n";
            sout << "So don't #define it in one file. Instead, use a compiler switch like -DIRECLIB_PNG_SUPPORT\n";
            sout << "so it takes effect for your entire application.";
            throw image_load_error(sout.str());
        }
        else if (im_type == image_file_type::GIF)
        {
            std::ostringstream sout;
            sout << "Unable to load image in file " + file_name + ".\n" +
                    "You must #define IRECLIB_GIF_SUPPORT and link to libgif to read GIF files.\n\n";
            sout << "Note that you must cause IRECLIB_GIF_SUPPORT to be defined for your entire project.\n";
            sout << "So don't #define it in one file. Instead, add it to the C/C++->Preprocessor->Preprocessor Definitions\n";
            sout << "field in Visual Studio's Property Pages window so it takes effect for your entire application.\n";
            sout << "Note that you must cause IRECLIB_GIF_SUPPORT to be defined for your entire project.\n";
            sout << "So don't #define it in one file. Instead, use a compiler switch like -DIRECLIB_GIF_SUPPORT\n";
            sout << "so it takes effect for your entire application.";
            throw image_load_error(sout.str());
        }
        else if (im_type == image_file_type::WEBP)
        {
            std::ostringstream sout;
            sout << "Unable to load image in file " + file_name + ".\n" +
                    "You must #define IRECLIB_WEBP_SUPPORT and link to libwebp to read WebP files.\n" +
                    "Do this by following the instructions at http://ireclib.net/compile.html.\n\n";
            sout << "Note that you must cause IRECLIB_WEBP_SUPPORT to be defined for your entire project.\n";
            sout << "So don't #define it in one file. Instead, add it to the C/C++->Preprocessor->Preprocessor Definitions\n";
            sout << "field in Visual Studio's Property Pages window so it takes effect for your entire application.";
            sout << "Note that you must cause IRECLIB_WEBP_SUPPORT to be defined for your entire project.\n";
            sout << "So don't #define it in one file. Instead, use a compiler switch like -DIRECLIB_WEBP_SUPPORT\n";
            sout << "so it takes effect for your entire application.";
            throw image_load_error(sout.str());
        }
        else if (im_type == image_file_type::JXL)
        {
            std::ostringstream sout;
            sout << "Unable to load image in file " + file_name + ".\n" +
                    "You must #define IRECLIB_JXL_SUPPORT and link to libjxl to read JPEG XL files.\n" +
                    "Do this by following the instructions at http://ireclib.net/compile.html.\n\n";
            sout << "Note that you must cause IRECLIB_JXL_SUPPORT to be defined for your entire project.\n";
            sout << "So don't #define it in one file. Instead, add it to the C/C++->Preprocessor->Preprocessor Definitions\n";
            sout << "field in Visual Studio's Property Pages window so it takes effect for your entire application.";
            sout << "Note that you must cause IRECLIB_JXL_SUPPORT to be defined for your entire project.\n";
            sout << "So don't #define it in one file. Instead, use a compiler switch like -DIRECLIB_JXL_SUPPORT\n";
            sout << "so it takes effect for your entire application.";
            throw image_load_error(sout.str());
        }
        else
        {
            throw image_load_error("Unknown image file format: Unable to load image in file " + file_name);
        }
    }

// ----------------------------------------------------------------------------------------

}


