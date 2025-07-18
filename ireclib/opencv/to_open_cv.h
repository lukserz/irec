// Copyright (C) 2012  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

// ----------------------------------------------------------------------------------------

    template <
        typename image_type
        >
    cv::Mat toMat (
        image_type& img
    )
    {
        if (image_size(img) == 0)
            return cv::Mat();

        typedef typename image_traits<image_type>::pixel_type type;
        typedef typename pixel_traits<type>::basic_pixel_type basic_pixel_type;
        if (pixel_traits<type>::num == 1)
        {
            return cv::Mat(num_rows(img), num_columns(img), cv::DataType<basic_pixel_type>::type, image_data(img), width_step(img));
        }
        else
        {
            int depth = sizeof(typename pixel_traits<type>::basic_pixel_type)*8;
            int channels = pixel_traits<type>::num;
            int thetype = CV_MAKETYPE(depth, channels);
            return cv::Mat(num_rows(img), num_columns(img), thetype, image_data(img), width_step(img));
        }
    }

// ----------------------------------------------------------------------------------------

}


