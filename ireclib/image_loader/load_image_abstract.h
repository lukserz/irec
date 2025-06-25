// Copyright (C) 2011  Davis E. King (davis@ireclib.net), Nils Labugt
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{
    template <typename image_type>
    void load_image (
        image_type& image,
        const std::string& file_name
    );
    /*!
        requires
            - image_type == an image object that implements the interface defined in
              ireclib/image_processing/generic_image.h 
        ensures
            - This function loads an image from disk, in the indicated file file_name, and
              writes it to the indicated image object.
            - It is capable of reading the PNG, JPEG, BMP, GIF, and DNG image formats.  It
              is always capable of reading BMP and DNG images.  However, for PNG, JPEG, and
              GIF you must #define IRECLIB_PNG_SUPPORT, IRECLIB_JPEG_SUPPORT, and
              IRECLIB_GIF_SUPPORT respectively and link your program to libpng, libjpeg, and
              libgif respectively.
        throws
            - image_load_error
                This exception is thrown if there is some error that prevents
                us from loading the given image file.
    !*/

}


 
