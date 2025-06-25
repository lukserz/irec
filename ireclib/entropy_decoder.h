// Copyright (C) 2003  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.





namespace ireclib
{


    class entropy_decoder
    {
        entropy_decoder() {}


    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef     entropy_decoder_kernel_1
                    kernel_1a;
        typedef     entropy_decoder_kernel_c<kernel_1a>
                    kernel_1a_c;
          

        // kernel_2a        
        typedef     entropy_decoder_kernel_2
                    kernel_2a;
        typedef     entropy_decoder_kernel_c<kernel_2a>
                    kernel_2a_c;
          

    };
}


