// Copyright (C) 2005  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.





namespace ireclib
{


    class lzp_buffer
    {

        lzp_buffer() {}

        typedef sliding_buffer<unsigned char>::kernel_1a sb1;

    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef     lzp_buffer_kernel_1<sb1>   
                    kernel_1a;
        typedef     lzp_buffer_kernel_c<kernel_1a>
                    kernel_1a_c;

        // kernel_2a        
        typedef     lzp_buffer_kernel_2<sb1>   
                    kernel_2a;
        typedef     lzp_buffer_kernel_c<kernel_2a>
                    kernel_2a_c;
  

    };
}


