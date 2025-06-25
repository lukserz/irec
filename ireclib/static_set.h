// Copyright (C) 2005  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.



namespace ireclib
{

    template <
        typename T,
        typename compare = std::less<T>
        >
    class static_set
    {
        static_set() {}


    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef     static_set_kernel_1<T,compare>
                    kernel_1a;
        typedef     static_set_kernel_c<kernel_1a>
                    kernel_1a_c;
        
   
        //----------- extensions -------------

        typedef     static_set_compare_1<kernel_1a>
                    compare_1a;
        typedef     static_set_compare_1<kernel_1a_c>
                    compare_1a_c;




    };
}


