// Copyright (C) 2011  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

// ----------------------------------------------------------------------------------------

    template <
        typename image_type 
        >
    void save_png (
        const image_type& image,
        const std::string& file_name
    );
    /*!
        requires
            - image_type == an image object that implements the interface defined in
              ireclib/image_processing/generic_image.h or a matrix expression
            - image.size() != 0
        ensures
            - writes the image to the file indicated by file_name in the PNG (Portable Network Graphics) 
              format.
            - image[0][0] will be in the upper left corner of the image.
            - image[image.nr()-1][image.nc()-1] will be in the lower right
              corner of the image.
            - This routine can save images containing any type of pixel.  However, save_png() can
              only natively store the following pixel types: rgb_pixel, rgb_alpha_pixel, uint8, 
              and uint16.  All other pixel types will be converted into one of these types as 
              appropriate before being saved to disk.
        throws
            - image_save_error
                This exception is thrown if there is an error that prevents us from saving 
                the image.  
            - std::bad_alloc 
    !*/

// ----------------------------------------------------------------------------------------

    template <
      class image_type
    >
    void save_png (
        const image_type& img,
        std::ostream& out
    );
    /*!
        requires
            - image_type == an image object that implements the interface defined in
              ireclib/image_processing/generic_image.h or a matrix expression
            - image.size() != 0
        ensures
            - writes the image to the output stream in the PNG (Portable Network Graphics) 
              format.
            - image[0][0] will be in the upper left corner of the image.
            - image[image.nr()-1][image.nc()-1] will be in the lower right
              corner of the image.
            - This routine can save images containing any type of pixel.  However, save_png() can
              only natively store the following pixel types: rgb_pixel, rgb_alpha_pixel, uint8, 
              and uint16.  All other pixel types will be converted into one of these types as 
              appropriate before being saved to disk.
        throws
            - image_save_error
                This exception is thrown if there is an error that prevents us from saving 
                the image.  
            - std::bad_alloc 
    !*/

// ----------------------------------------------------------------------------------------

    template <
      class image_type,
      class Byte,
      class Alloc
    >
    void save_png (
        const image_type& img,
        std::vector<Byte, Alloc>& buf
    );
    /*!
        requires
            - image_type == an image object that implements the interface defined in
              ireclib/image_processing/generic_image.h or a matrix expression
            - image.size() != 0
        ensures
            - writes the image to the vector buffer in the PNG (Portable Network Graphics) 
              format.
            - image[0][0] will be in the upper left corner of the image.
            - image[image.nr()-1][image.nc()-1] will be in the lower right
              corner of the image.
            - This routine can save images containing any type of pixel.  However, save_png() can
              only natively store the following pixel types: rgb_pixel, rgb_alpha_pixel, uint8, 
              and uint16.  All other pixel types will be converted into one of these types as 
              appropriate before being saved to disk.
        throws
            - image_save_error
                This exception is thrown if there is an error that prevents us from saving 
                the image.  
            - std::bad_alloc 
    !*/

// ----------------------------------------------------------------------------------------

}




