// Copyright (C) 2003  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

    template <
        typename base
        >
    class sync_extension_kernel_1 : public base
    {

        rmutex m;
        rsignaler s;

        public:

        sync_extension_kernel_1 () : s(m) {}

        template < typename T >
        sync_extension_kernel_1 (const T& one) : base(one),s(m) {}
        template < typename T, typename U >
        sync_extension_kernel_1 (const T& one, const U& two) : base(one,two),s(m) {}


        const rmutex& get_mutex(
        ) const { return m; }

        void lock (
        ) const { m.lock(); }

        void unlock (
        ) const { m.unlock(); }

        void wait (
        ) const { s.wait(); }

        bool wait_or_timeout (
            unsigned long milliseconds
        ) const { return s.wait_or_timeout(milliseconds); }
         
        void broadcast (
        ) const { s.broadcast(); }

        void signal (
        ) const { s.signal(); }

    };

    template <
        typename base
        >
    inline void swap (
        sync_extension_kernel_1<base>& a, 
        sync_extension_kernel_1<base>& b 
    ) { a.swap(b); }

}


