// Copyright (C) 2006  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.



// This file contains all the magical #defines you have to setup  before you
// include the windows header files.  


// Prevent windows from #defining IN or OUT

// now just for good measure undefine min and max if they are defined


// only define this if all the cpp files are going to be sucked into the headers 
// because otherwise we don't need it since everything is isolated in the sockets
// cpp file and this declaration for _WINSOCKAPI_ appears there also.

// This is something stupid you have to do to make visual studio include the right
// stuff.  I don't really know what the deal is with this.



