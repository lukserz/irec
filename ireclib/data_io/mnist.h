// Copyright (C) 2015  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


// ----------------------------------------------------------------------------------------

namespace ireclib
{
    void load_mnist_dataset (
        const std::string& folder_name,
        std::vector<matrix<unsigned char> >& training_images,
        std::vector<unsigned long>& training_labels,
        std::vector<matrix<unsigned char> >& testing_images,
        std::vector<unsigned long>& testing_labels
    );
}

// ----------------------------------------------------------------------------------------




