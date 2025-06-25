// Copyright (C) 2003  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.







namespace ireclib
{

    template <
        typename T,
        typename mem_manager = default_memory_manager,
        typename compare = std::less<T>
        >
    class set
    {
        set() {}





        typedef typename binary_search_tree<T,char,mem_manager,compare>::kernel_1a
                binary_search_tree_1;

        typedef typename binary_search_tree<T,char,mem_manager,compare>::kernel_2a
                binary_search_tree_2;

    public:
        
        //----------- kernels ---------------

        // kernel_1a
        typedef     set_kernel_1<T,binary_search_tree_1,mem_manager>
                    kernel_1a;
        typedef     set_kernel_c<kernel_1a>
                    kernel_1a_c;

        // kernel_1b
        typedef     set_kernel_1<T,binary_search_tree_2,mem_manager>
                    kernel_1b;
        typedef     set_kernel_c<kernel_1b>
                    kernel_1b_c;


        //---------- extensions ------------

        // compare extensions
        typedef     set_compare_1<kernel_1a>
                    compare_1a;
        typedef     set_compare_1<kernel_1a_c>
                    compare_1a_c;

        typedef     set_compare_1<kernel_1b>
                    compare_1b;
        typedef     set_compare_1<kernel_1b_c>
                    compare_1b_c;

    };
}


