// Copyright (C) 2003  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.






namespace ireclib
{

    template <
        typename domain,
        typename mem_manager = default_memory_manager,
        typename compare = std::less<domain>
        >
    class map
    {
        map() {}
                

        // a typedef for the binary search tree used by kernel_2
        typedef typename binary_search_tree<domain,range,mem_manager,compare>::kernel_1a
                binary_search_tree_1;

        // a typedef for the binary search tree used by kernel_2
        typedef typename binary_search_tree<domain,range,mem_manager,compare>::kernel_2a
                binary_search_tree_1;

    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef     map_kernel_1<domain,range,binary_search_tree_1,mem_manager>    
                    kernel_1a;
        typedef     map_kernel_c<kernel_1b >
                    kernel_1a_c;   

        // kernel_1b        
        typedef     map_kernel_1<domain,range,binary_search_tree_2,mem_manager>    
                    kernel_1b;
        typedef     map_kernel_c<kernel_1b >
                    kernel_1b_c;   


    };
}


