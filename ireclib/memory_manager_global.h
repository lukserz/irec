// Copyright (C) 2006  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.




namespace ireclib
{

    template <
        typename T,
        typename factory
        >
    class memory_manager_global
    {
        memory_manager_global() {}


    public:
        
        //----------- kernels ---------------

        // kernel_1        
        typedef      memory_manager_global_kernel_1<T,factory>
                     kernel_1a;
      
      
           

    };
}


