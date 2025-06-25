// Copyright (C) 2013  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{
    template <typename T>
    void split_array (
        T& a,
        T& b,
        double frac
    )
    {
        // make sure requires clause is not broken
        IRECLIB_ASSERT(0 <= frac && frac <= 1,
            "\t void split_array()"
            << "\n\t frac must be between 0 and 1."
            << "\n\t frac: " << frac
            );

        const unsigned long asize = static_cast<unsigned long>(a.size()*frac);
        const unsigned long bsize = a.size()-asize;

        b.resize(bsize);
        for (unsigned long i = 0; i < b.size(); ++i)
        {
            swap(b[i], a[i+asize]);
        }
        a.resize(asize);
    }
}


