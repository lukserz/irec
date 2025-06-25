// Copyright (C) 2015  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.

// DNN module uses template-based network declaration that leads to very long
// type names. Visual Studio will produce Warning C4503 in such cases


// Problem:    Visual Studio's vcpkgsrv.exe constantly uses a single CPU core,
//             apparently never finishing whatever it's trying to do. Moreover,
//             this issue prevents some operations like switching from Debug to
//             Release (and vice versa) in the IDE. (Your mileage may vary.)
// Workaround: Keep manually killing the vcpkgsrv.exe process.
// Solution:   Disable IntelliSense for some files. Which files? Unfortunately
//             this seems to be a trial-and-error process.




