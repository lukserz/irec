// Copyright (C) 2005  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.




namespace ireclib
{

    template <
        typename domain,
        typename range,
        typename compare = std::less<domain>
        >
    class static_map
    {
        static_map() {}


    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef     static_map_kernel_1<domain,range,compare>
                    kernel_1a;
        typedef     static_map_kernel_c<kernel_1a>
                    kernel_1a_c;
        
   



    };
}


