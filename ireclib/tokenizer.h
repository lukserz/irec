// Copyright (C) 2005  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

    class tokenizer
    {
        tokenizer() {}


    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef     tokenizer_kernel_1
                    kernel_1a;
        typedef     tokenizer_kernel_c<kernel_1a>
                    kernel_1a_c;
          

    };
}


