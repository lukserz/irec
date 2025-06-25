// Copyright (C) 2006  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

// ----------------------------------------------------------------------------------------

    struct row_major_layout;

// ----------------------------------------------------------------------------------------

    template <
        typename T,
        long num_rows = 0,
        long num_cols = 0,
        typename mem_manager = default_memory_manager,
        typename layout = row_major_layout 
        >
    class matrix; 

// ----------------------------------------------------------------------------------------

}


