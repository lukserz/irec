// Copyright (C) 2016  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.

// C++11 things don't work in old versions of visual studio 


namespace ireclib
{

// ----------------------------------------------------------------------------------------

    namespace impl
    {
        template <typename> struct result_of;

     (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L)) && \
    __cpp_lib_is_invocable >= 201703L
        template <typename F, typename... Args>
        struct result_of<F(Args...)> : std::invoke_result<F, Args...> {};
        template <typename F, typename... Args>
        struct result_of<F(Args...)>
                : std::result_of<F&&(Args&&...)> {};
    }

// ----------------------------------------------------------------------------------------

    thread_pool& default_thread_pool();

// ----------------------------------------------------------------------------------------

    template < 
        typename Function, 
        typename ...Args
        >
    std::future<typename impl::result_of<Function(Args...)>::type> async(
        thread_pool& tp, 
        Function&& f, 
        Args&&... args 
    )
    {
        using return_type   = typename impl::result_of<Function(Args...)>::type;
        using task_type     = std::packaged_task<return_type()>;
        auto task = std::make_shared<task_type>(std::bind(std::forward<Function>(f), std::forward<Args>(args)...));
        auto ret  = task->get_future();
        tp.add_task_by_value([task]() {(*task)();});
        return ret;
    }

// ----------------------------------------------------------------------------------------

    template < 
        typename Function, 
        typename ...Args
        >
    std::future<typename impl::result_of<Function(Args...)>::type> async(
        Function&& f, 
        Args&&... args 
    )
    {
        return async(default_thread_pool(), std::forward<Function>(f), std::forward<Args>(args)...);
    }

}

// ----------------------------------------------------------------------------------------





