// Copyright (C) 2012  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{
    template <
        typename image_type
        >
    cv::Mat toMat (
        image_type& img
    );
    /*!
        requires
            - image_type == an image object that implements the interface defined in
              ireclib/image_processing/generic_image.h or a ireclib::matrix object which uses a
              row_major_layout.
            - pixel_traits is defined for the contents of img.
        ensures
            - returns an OpenCV Mat object which represents the same image as img.  This
              is done by setting up the Mat object to point to the same memory as img.
              Therefore, the returned Mat object is valid only as long as pointers
              to the pixels in img remain valid.
    !*/
}




