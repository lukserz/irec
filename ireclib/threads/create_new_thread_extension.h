// Copyright (C) 2006  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

// ----------------------------------------------------------------------------------------

    template <
        typename T,
        void (T::*funct)()
        >
    inline void ireclib_create_new_thread_helper (
        void* obj
    )
    {
        T* o = static_cast<T*>(obj);
        (o->*funct)();
    }

// ----------------------------------------------------------------------------------------

    template <
        typename T,
        void (T::*funct)()
        >
    inline bool create_new_thread (
        T& obj
    )
    {
        return create_new_thread(ireclib_create_new_thread_helper<T,funct>,&obj);
    }

// ----------------------------------------------------------------------------------------

}



