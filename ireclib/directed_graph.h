// Copyright (C) 2007  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.



namespace ireclib
{

    template <
        typename T,
        typename E = char,
        typename mem_manager = default_memory_manager
        >
    class directed_graph 
    {
        directed_graph() {}
    public:
                

        //----------- kernels ---------------

        // kernel_1a        
        typedef     directed_graph_kernel_1<T,E,mem_manager,false>    
                    kernel_1a;
        typedef     directed_graph_kernel_1<T,E,mem_manager,true>    
                    kernel_1a_c;
 
    };
}



