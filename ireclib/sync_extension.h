// Copyright (C) 2003  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.




namespace ireclib
{

    template <
        typename base
        >
    class sync_extension
    {
        sync_extension() {}
    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef     sync_extension_kernel_1<base>    
                    kernel_1a;
 
    };
}


