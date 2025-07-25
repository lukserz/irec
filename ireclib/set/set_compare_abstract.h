// Copyright (C) 2005  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.




namespace ireclib
{

    template <
        typename set_base
        >
    class set_compare : public set_base
    {

        /*!
            REQUIREMENTS ON set_base
                must be an implementation of set/set_kernel_abstract.h

            POINTERS AND REFERENCES TO INTERNAL DATA
                operator== and operator< invalidate pointers or references to 
                data members.

            WHAT THIS EXTENSION DOES FOR set
                This gives a set the ability to compare itself to other 
                sets using the < and == operators. 

                The < operator is conceptually weird for sets.  It is useful 
                though because it allows you to make sets of sets since
                sets require that their containing type implement operator<.

                Also note that it is the case that for any two sets a and b 
                if (a<b) == false and (b<a) == false then a == b. 

                Also note that unless specified otherwise, no member functions
                of this object throw exceptions.
               

            NOTATION
                For the purposes of defining what these operators do I will 
                use the operator[] to reference the elements of the sets.
                operator[] is defined to access the elements of the set in 
                the same order they would be enumerated by the enumerable 
                interface.
        !*/

        public:

            bool operator< (
                const set_compare& rhs
            ) const;
            /*!
                ensures
                    - #at_start() == true
                    - if (size() < rhs.size()) then
                        - returns true
                    - else if (size() > rhs.size()) then
                        - returns false
                    - else
                        - returns true if there exists an integer j such that 0 <= j < size() 
                          and for all integers i such that 0 <= i < j where it is true that
                          (*this)[i] == rhs[i] and (*this)[j] < rhs[j] 
                        - returns false if there is no j that will satisfy the above conditions.                    
            !*/

            bool operator== (
                const set_compare& rhs
            ) const;
            /*!
                ensures
                    - #at_start() == true
                    - returns true if *this and rhs contain the same elements.
                      returns false otherwise.
            !*/
    };


    template <
        typename set_base
        >
    inline void swap (
        set_compare<set_base>& a, 
        set_compare<set_base>& b 
    ) { a.swap(b); } 
    /*!
        provides a global swap function
    !*/

}


