// Copyright (C) 2005  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


namespace ireclib
{

    template <
        typename set_base
        >
    class static_set_kernel_c : public set_base
    {
        typedef typename set_base::type T;
        public:

            const T& element (
            );

            const T& element (
            ) const;
    };


    template <
        typename set_base
        >
    inline void swap (
        static_set_kernel_c<set_base>& a, 
        static_set_kernel_c<set_base>& b 
    ) { a.swap(b); } 

// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------
    // member function definitions
// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------
 
    template <
        typename set_base
        >
    const typename set_base::type& static_set_kernel_c<set_base>::
    element (
    ) const
    {
        // make sure requires clause is not broken
        IRECLIB_CASSERT(this->current_element_valid() == true,
            "\tconst T& static_set::element() const"
            << "\n\tyou can't access the current element if it doesn't exist"
            << "\n\tthis: " << this
            );

        // call the real function
        return set_base::element();
    }

// ----------------------------------------------------------------------------------------

    template <
        typename set_base
        >
    const typename set_base::type& static_set_kernel_c<set_base>::
    element (
    ) 
    {
        // make sure requires clause is not broken
        IRECLIB_CASSERT(this->current_element_valid() == true,
            "\tconst T& static_set::element"
            << "\n\tyou can't access the current element if it doesn't exist"
            << "\n\tthis: " << this
            );

        // call the real function
        return set_base::element();
    }

// ----------------------------------------------------------------------------------------


}


