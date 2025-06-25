// Copyright (C) 2007  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

    class mlp
    {
        mlp() {}

    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef     mlp_kernel_1    
                    kernel_1a;
        typedef     mlp_kernel_c<kernel_1a >
                    kernel_1a_c;   

    };
}


