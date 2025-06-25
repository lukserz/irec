// Copyright (C) 2003  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.




namespace ireclib
{

    template <
        unsigned long alphabet_size
        >
    class conditioning_class
    {
        conditioning_class() {}

        typedef memory_manager<char>::kernel_2b mm;

    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef      conditioning_class_kernel_1<alphabet_size>
                     kernel_1a;
        typedef      conditioning_class_kernel_c<kernel_1a>
                     kernel_1a_c;

        // kernel_2a        
        typedef      conditioning_class_kernel_2<alphabet_size>
                     kernel_2a;
        typedef      conditioning_class_kernel_c<kernel_2a>
                     kernel_2a_c;
          
        // kernel_3a        
        typedef      conditioning_class_kernel_3<alphabet_size>
                     kernel_3a;
        typedef      conditioning_class_kernel_c<kernel_3a>
                     kernel_3a_c;
          

        // -------- kernel_4 ---------

        // kernel_4a        
        typedef      conditioning_class_kernel_4<alphabet_size,10000,mm>
                     kernel_4a;
        typedef      conditioning_class_kernel_c<kernel_4a>
                     kernel_4a_c;

        // kernel_4b        
        typedef      conditioning_class_kernel_4<alphabet_size,100000,mm>
                     kernel_4b;
        typedef      conditioning_class_kernel_c<kernel_4b>
                     kernel_4b_c;

        // kernel_4c        
        typedef      conditioning_class_kernel_4<alphabet_size,1000000,mm>
                     kernel_4c;
        typedef      conditioning_class_kernel_c<kernel_4c>
                     kernel_4c_c;

        // kernel_4d        
        typedef      conditioning_class_kernel_4<alphabet_size,10000000,mm>
                     kernel_4d;
        typedef      conditioning_class_kernel_c<kernel_4d>
                     kernel_4d_c;

    };
}


