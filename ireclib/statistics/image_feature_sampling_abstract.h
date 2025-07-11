// Copyright (C) 2011  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

// ----------------------------------------------------------------------------------------

    template <
        typename image_array_type,
        typename feature_extractor_type,
        typename pyramid_type
        >
    random_subset_selector<typename feature_extractor_type::descriptor_type> randomly_sample_image_features (
        const image_array_type& images,
        const pyramid_type& pyr,
        const feature_extractor_type& fe,
        unsigned long num
    );
    /*!
        requires
            - pyramid_type == a type compatible with the image pyramid objects defined 
              in ireclib/image_transforms/image_pyramid_abstract.h
            - feature_extractor_type == a local image feature extractor type such as the
              ireclib::hog_image
            - image_array_type == an implementation of ireclib/array/array_kernel_abstract.h
              and it must contain image objects which can be passed to pyr() and fe.load()
              and are swappable by global swap().
        ensures
            - creates an image pyramid for each image in images and performs feature
              extraction on each pyramid level.  Then selects a random subsample of at 
              most num local feature vectors and returns it.
    !*/

// ----------------------------------------------------------------------------------------

}



