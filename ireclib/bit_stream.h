// Copyright (C) 2003  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.



namespace ireclib
{


    class bit_stream
    {
        bit_stream() {}
    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef     bit_stream_kernel_1    
                    kernel_1a;
        typedef     bit_stream_kernel_c<kernel_1a >
                    kernel_1a_c;

        //---------- extensions ------------

        
        // multi_1 extend kernel_1a
        typedef     bit_stream_multi_1<kernel_1a>
                    multi_1a;
        typedef     bit_stream_multi_c<bit_stream_multi_1<kernel_1a_c> >
                    multi_1a_c;

    };
}


