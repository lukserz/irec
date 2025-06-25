// Copyright (C) 2020  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


// ----------------------------------------------------------------------------------------

namespace ireclib
{
    void load_cifar_10_dataset (
        const std::string& folder_name,
        std::vector<matrix<rgb_pixel>>& training_images,
        std::vector<unsigned long>& training_labels,
        std::vector<matrix<rgb_pixel>>& testing_images,
        std::vector<unsigned long>& testing_labels
    );
}

// ----------------------------------------------------------------------------------------


