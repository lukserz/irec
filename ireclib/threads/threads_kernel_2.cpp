// Copyright (C) 2003  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.





namespace ireclib
{
    namespace threads_kernel_shared_helpers
    {

    // -----------------------------------------------------------------------------------

        struct info
        {
            void* param;
            void (*funct)(void*);
        };

    // -----------------------------------------------------------------------------------

        void* thread_starter (
            void* param
        )
        {
            info* alloc_p = static_cast<info*>(param);
            info p = *alloc_p;
            delete alloc_p;

            // detach self
            pthread_detach(pthread_self());

            p.funct(p.param);
            return 0;
        }

    // -----------------------------------------------------------------------------------

        bool spawn_thread (
            void (*funct)(void*),
            void* param
        )
        {
            info* p;
            try { p = new info; }
            catch (...) { return false; }

            p->funct = funct;
            p->param = param;

            pthread_t thread_id;
            if ( pthread_create (&thread_id, 0, thread_starter, p) )
            {
                delete p;
                return false;
            }
            return true;
        }

    // -----------------------------------------------------------------------------------

    }

}



