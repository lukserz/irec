// Copyright (C) 2006  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

// ----------------------------------------------------------------------------------------

    template <
        typename T,
        void (T::*funct)()
        >
    bool create_new_thread (
        T& obj
    );
    /*!
        ensures
            - creates a new thread and calls obj.*funct() from it.
            - returns true upon success and false upon failure to create the new thread.
    !*/

// ----------------------------------------------------------------------------------------

}




