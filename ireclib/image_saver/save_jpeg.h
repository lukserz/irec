// Copyright (C) 2014  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.



namespace ireclib
{

// ----------------------------------------------------------------------------------------

    void save_jpeg (
        const array2d<rgb_pixel>& img,
        const std::string& filename,
        int quality = 75
    );

// ----------------------------------------------------------------------------------------

    void save_jpeg (
        const array2d<unsigned char>& img,
        const std::string& filename,
        int quality = 75
    );

// ----------------------------------------------------------------------------------------

    template <
        typename image_type
        >
    typename disable_if<is_matrix<image_type> >::type save_jpeg(
        const image_type& img,
        const std::string& filename,
        int quality = 75
    )
    {
        // Convert any kind of grayscale image to an unsigned char image 
        if (pixel_traits<typename image_traits<image_type>::pixel_type>::grayscale)
        {
            array2d<unsigned char> temp;
            assign_image(temp, img);
            save_jpeg(temp, filename, quality);
        }
        else
        {
            // This is some other kind of color image so just save it as an RGB image.
            array2d<rgb_pixel> temp;
            assign_image(temp, img);
            save_jpeg(temp, filename, quality);
        }
    }

// ----------------------------------------------------------------------------------------

    template <
        typename EXP 
        >
    void save_jpeg(
        const matrix_exp<EXP>& img,
        const std::string& file_name,
        int quality = 75
    )
    {
        array2d<typename EXP::type> temp;
        assign_image(temp, img);
        save_jpeg(temp, file_name, quality);
    }

// ----------------------------------------------------------------------------------------

}


