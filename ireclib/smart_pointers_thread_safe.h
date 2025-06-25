// Copyright (C) 2008  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.

// This is legacy smart pointer code that will likely to stop working under default
// compiler flags when C++17 becomes the default standard in the compilers.
// Please consider migrating your code to contemporary smart pointers from C++
// standard library. The warning below will help to detect if the deprecated code
// was included from library's clients.
  (defined(__clang__) && ((__clang_major__ >= 3 && __clang_minor__ >= 4)))





