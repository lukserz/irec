// Copyright (C) 2013  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{
    template <typename T>
    void split_array (
        T& a,
        T& b,
        double frac
    );
    /*!
        requires
            - 0 <= frac <= 1
            - T must be an array type such as ireclib::array or std::vector
        ensures
            - This function takes the elements of a and splits them into two groups.  The
              first group remains in a and the second group is put into b.  The ordering of
              elements in a is preserved.  In particular, concatenating #a with #b will
              reproduce the original contents of a.
            - The elements in a are moved around using global swap().  So they must be
              swappable, but do not need to be copyable.
            - #a.size() == floor(a.size()*frac)
            - #b.size() == a.size()-#a.size()
    !*/
}


