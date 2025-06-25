// Copyright (C) 2016  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

// ----------------------------------------------------------------------------------------

    thread_pool& default_thread_pool(
    );
    /*!
        ensures
            - returns a reference to a global thread_pool.  If the IRECLIB_NUM_THREADS
              environment variable is set to an integer then the thread pool will contain
              IRECLIB_NUM_THREADS threads, otherwise it will contain
              std::thread::hardware_concurrency() threads.
    !*/

// ----------------------------------------------------------------------------------------

    template < 
        typename Function, 
        typename ...Args
        >
    std::future<typename std::result_of<Function(Args...)>::type> async(
        thread_pool& tp, 
        Function&& f, 
        Args&&... args 
    );
    /*!
        requires
            - f must be a function and f(args...) must be a valid expression.
        ensures
            - This function behaves just like std::async(std::launch::async, f, args)
              except that instead of spawning a new thread to process each task it submits
              the task to the provided ireclib::thread_pool.  Therefore, ireclib::async() is
              guaranteed to use a bounded number of threads unlike std::async().  This also
              means that calls to ireclib::async() will block if there aren't any free threads
              in the thread pool.
    !*/

// ----------------------------------------------------------------------------------------

    template < 
        typename Function, 
        typename ...Args
        >
    std::future<typename std::result_of<Function(Args...)>::type> async(
        Function&& f, 
        Args&&... args 
    );
    /*!
        ensures
            - Calling this function is equivalent to directly calling async(default_thread_pool(), f, args...)
    !*/
}

// ----------------------------------------------------------------------------------------


