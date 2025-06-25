// Copyright (C) 2005  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.



namespace ireclib
{

    class cpp_pretty_printer
    {
        cpp_pretty_printer() {}


        typedef stack<unsigned long>::kernel_1a stack;
        typedef cpp_tokenizer::kernel_1a tok;

    public:
        
        //----------- kernels ---------------

        // kernel_1a        
        typedef     cpp_pretty_printer_kernel_1<stack,tok>
                    kernel_1a;

        // kernel_2a        
        typedef     cpp_pretty_printer_kernel_2<stack,tok>
                    kernel_2a;

    };
}


