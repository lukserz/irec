// Copyright (C) 2014  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


extern "C"
{
// =========================>>> WHY YOU ARE GETTING AN ERROR HERE <<<=========================
// The point of this block of code is to cause a link time error that will prevent a user
// from compiling part of their application with IRECLIB_ASSERT enabled and part with it
// disabled since doing that would be a violation of C++'s one definition rule.  So if you
// are getting an error here then you are either not enabling IRECLIB_ASSERT consistently
// (e.g. by compiling part of your program in a debug mode and part in a release mode) or
// you have simply forgotten to compile ireclib/all/source.cpp into your application.
// =========================>>> WHY YOU ARE GETTING AN ERROR HERE <<<=========================
    const extern int USER_ERROR__inconsistent_build_configuration__see_ireclib_faq_1;
    const int IRECLIB_NO_WARN_UNUSED ireclib_check_assert_helper_variable = USER_ERROR__inconsistent_build_configuration__see_ireclib_faq_1;
    const extern int USER_ERROR__inconsistent_build_configuration__see_ireclib_faq_1_;
    const int IRECLIB_NO_WARN_UNUSED ireclib_check_assert_helper_variable = USER_ERROR__inconsistent_build_configuration__see_ireclib_faq_1_;



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
    const extern int USER_ERROR__inconsistent_build_configuration__see_ireclib_faq_2;
    const int IRECLIB_NO_WARN_UNUSED ireclib_check_not_configured_helper_variable = USER_ERROR__inconsistent_build_configuration__see_ireclib_faq_2;



// Cause the user to get a linker error if they try to use header files from one version of
// ireclib with the compiled binary from a different version of ireclib.
    const extern int IRECLIB_CHECK_FOR_VERSION_MISMATCH;
    const int IRECLIB_NO_WARN_UNUSED ireclib_check_for_version_mismatch = IRECLIB_CHECK_FOR_VERSION_MISMATCH;

}


