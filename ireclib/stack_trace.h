// Copyright (C) 2008  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.

/*!
    This file defines 3 things.  Two of them are preprocessor macros that
    enable you to tag functions with the ireclib stack trace watcher.  The
    third thing is a function named get_stack_trace() which returns the
    current stack trace in std::string form.

    To enable the stack trace you must #define IRECLIB_ENABLE_STACK_TRACE.
    When this #define isn't set then the 3 things described above
    still exist but they don't do anything.

    Also note that when the stack trace is enabled it changes the IRECLIB_ASSERT
    and IRECLIB_CASSERT macros so that they print stack traces when 
    an assert fails.

    See the following example program for details:


    void funct2()
    {
        // put this macro at the top of each function you would
        // like to appear in stack traces
        IRECLIB_STACK_TRACE;

        // you may print the current stack trace as follows. 
        std::cout << ireclib::get_stack_trace() << endl;
    }

    void funct()
    {
        // This alternate form of IRECLIB_STACK_TRACE allows you to specify
        // the string used to name the current function.  The other form
        // will usually output an appropriate function name automatically
        // so this may not be needed.
        IRECLIB_STACK_TRACE_NAMED("funct");
        funct2();
    }

    int main()
    {
        funct();
    }
!*/



// only setup the stack trace stuff if the asserts are enabled (which happens in debug mode
// basically).  Also, this stuff doesn't work if you use NO_MAKEFILE

namespace ireclib
{
    const std::string get_stack_trace();
}

// redefine the IRECLIB_CASSERT macro to include the stack trace
    {if ( !(_exp) )                                                         \
    {                                                                       \
        std::ostringstream ireclib_o_out;                                       \
        ireclib_o_out << "\n\nError occurred at line " << __LINE__ << ".\n";    \
        ireclib_o_out << "Error occurred in file " << __FILE__ << ".\n";      \
        ireclib_o_out << "Error occurred in function " << IRECLIB_FUNCTION_NAME << ".\n\n";      \
        ireclib_o_out << "Failing expression was " << #_exp << ".\n";           \
        ireclib_o_out << _message << "\n\n";                                      \
        ireclib_o_out << "Stack Trace: \n" << ireclib::get_stack_trace() << "\n";        \
        ireclib_assert_breakpoint();                                           \
        throw ireclib::fatal_error(ireclib::EBROKEN_ASSERT,ireclib_o_out.str());      \
    }}                                                                      



namespace ireclib
{

    class stack_tracer
    {
    public:
        stack_tracer (
            const char* funct_name,
            const char* file_name,
            const int line_number
        );

        ~stack_tracer();

    };
}



namespace ireclib
{
    inline const std::string get_stack_trace() { return std::string("stack trace not enabled");}
}




