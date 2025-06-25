// Copyright (C) 2004  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.





namespace ireclib
{

    template <
        typename T
        >
    class sliding_buffer
    {

        sliding_buffer() {}
    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef     sliding_buffer_kernel_1<T>    
                    kernel_1a;
        typedef     sliding_buffer_kernel_c<kernel_1a>
                    kernel_1a_c;
   

    };
}


