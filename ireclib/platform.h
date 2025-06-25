// Copyright (C) 2006  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.




/*!
    This file ensures that:
        - if (we are compiling under a posix platform) then
            - IRECLIB_POSIX will be defined
            - if (this is also Mac OS X) then
                - MACOSX will be defined
            - if (this is also HP-UX) then
                - HPUX will be defined
        - if (we are compiling under an MS Windows platform) then
            - WIN32 will be defined
!*/


/*
    A good reference for this sort of information is
    http://predef.sourceforge.net/
*/

// Define WIN32 if this is MS Windows

    // since this is the only other platform the library currently supports
    // just assume it is IRECLIB_POSIX if it isn't WIN32
 







