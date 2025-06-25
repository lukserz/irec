// Copyright (C) 2010  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.

// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------
//       FORTRAN BINDING STUFF FROM BOOST 
// ----------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------

//  Permission to copy, use, modify, sell and
//  distribute this software is granted provided this copyright notice appears
//  in all copies. This software is provided "as is" without express or implied
//  warranty, and with no claim as to its suitability for any purpose.
//  Copyright (C) 2002, 2003 Si-Lab b.v.b.a., Toon Knapen and Kresimir Fresl 


// First we need to know what the conventions for linking
// C with Fortran is on this platform/toolset

// Next we define macros to convert our symbols to 
// the current convention



namespace ireclib
{
    namespace lapack
    {
            // stuff from f2c used to define what exactly is an integer in fortran
            typedef int integer;
            typedef unsigned int uinteger;
            typedef long int integer;
            typedef unsigned long int uinteger;

    }
}


