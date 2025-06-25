// Copyright (C) 2008  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.



namespace ireclib
{

// ----------------------------------------------------------------------------------------

    namespace 
    {
        struct stack_tracer_data
        {
            stack_tracer_data(
            ) :  funct_name(0),
                 file_name(0),
                 line_number(0)
            {}
            const char* funct_name;
            const char* file_name;
            int line_number;
        };

        using stack_tracer_stack_type = stack<stack_tracer_data,memory_manager<char>::kernel_2a>::kernel_1a;

        stack_tracer_stack_type& get_ireclib_stack_trace_stack()
        {
            thread_local stack_tracer_stack_type a;
            return a;
        }
    }

// ----------------------------------------------------------------------------------------

    stack_tracer::
    stack_tracer (
        const char* funct_name,
        const char* file_name,
        const int line_number
    )
    {
        stack_tracer_data data;
        data.funct_name = funct_name;
        data.file_name = file_name;
        data.line_number = line_number;

        // pop the info onto the function stack trace
        get_ireclib_stack_trace_stack().push(data);
    }

// ----------------------------------------------------------------------------------------

    stack_tracer::
    ~stack_tracer()
    {
        stack_tracer_data temp;
        get_ireclib_stack_trace_stack().pop(temp);
    }

// ----------------------------------------------------------------------------------------

    const std::string get_stack_trace()
    {
        std::ostringstream sout;
        auto& stack = get_ireclib_stack_trace_stack();
        stack.reset();
        while (stack.move_next())
        {
            stack_tracer_data data = stack.element();
            sout << data.file_name << ":" << data.line_number << "\n    " << data.funct_name << "\n";
        }
        return sout.str();
    }

// ----------------------------------------------------------------------------------------

}



