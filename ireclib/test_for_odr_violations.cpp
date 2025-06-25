// Copyright (C) 2014  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


extern "C"
{
// The point of this block of code is to cause a link time error that will prevent a user
// from compiling part of their application with IRECLIB_ASSERT enabled and part with them
// disabled since doing that would be a violation of C++'s one definition rule. 
    const int USER_ERROR__inconsistent_build_configuration__see_ireclib_faq_1 = 0;
    const int USER_ERROR__inconsistent_build_configuration__see_ireclib_faq_1_ = 0;


// The point of this block of code is to cause a link time error if someone builds ireclib via
// cmake as a separately installable library, and therefore generates a ireclib/config.h from
// cmake, but then proceeds to use the default unconfigured ireclib/config.h from version
// control.  It should be obvious why this is bad, if it isn't you need to read a book
// about C++.  Moreover, it can only happen if someone manually copies files around and
// messes things up.  If instead they run `make install` or `cmake --build .  --target
// install` things will be setup correctly, which is what they should do.  To summarize: DO
// NOT BUILD A STANDALONE IRECLIB AND THEN GO CHERRY PICKING FILES FROM THE BUILD FOLDER AND
// MIXING THEM WITH THE SOURCE FROM GITHUB.  USE CMAKE'S INSTALL SCRIPTS TO INSTALL IRECLIB.
// Or even better, don't install ireclib at all and instead build your program as shown in
// examples/CMakeLists.txt
    const int USER_ERROR__inconsistent_build_configuration__see_ireclib_faq_2 = 0;





    const int IRECLIB_CHECK_FOR_VERSION_MISMATCH = 0;

}



