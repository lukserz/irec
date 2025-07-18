// Copyright (C) 2016  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.

// C++11 things don't work in old versions of visual studio 


namespace ireclib
{

// ----------------------------------------------------------------------------------------

    namespace impl
    {
        unsigned long default_num_threads()
        {
            try
            {
                char* nt = getenv("IRECLIB_NUM_THREADS");
                if (nt)
                    return string_cast<unsigned long>(nt);
            } catch(string_cast_error&) {}
            return std::thread::hardware_concurrency();
        }
    }

// ----------------------------------------------------------------------------------------

    thread_pool& default_thread_pool()
    {
        static thread_pool tp(impl::default_num_threads());
        return tp;
    }
}

// ----------------------------------------------------------------------------------------




