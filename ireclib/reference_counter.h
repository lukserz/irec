// Copyright (C) 2003  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

    template <
        typename T,
        typename copy = copy_functor<T>
        >
    class reference_counter
    {
        reference_counter() {}
    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef     reference_counter_kernel_1<T,copy>    
                    kernel_1a;

    };
}


