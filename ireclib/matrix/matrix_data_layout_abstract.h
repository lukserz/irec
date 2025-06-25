// Copyright (C) 2008  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

// ----------------------------------------------------------------------------------------

    struct row_major_layout
    {
        /*!
            This is the default matrix layout.  Any matrix object that uses this
            layout will be laid out in memory in row major order.  Additionally,
            all elements are contiguous (e.g. there isn't any padding at the ends of
            rows or anything like that)
        !*/
    };

// ----------------------------------------------------------------------------------------

    struct column_major_layout
    {
        /*!
            Any matrix object that uses this layout will be laid out in memory in 
            column major order.  Additionally, all elements are contiguous (e.g. 
            there isn't any padding at the ends of rows or anything like that)
        !*/
    };

// ----------------------------------------------------------------------------------------

}



