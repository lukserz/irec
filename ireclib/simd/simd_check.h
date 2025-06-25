// Copyright (C) 2013  Davis E. King (davis@ireclib.net)
// License: Boost Software License   See LICENSE.txt for the full license.


//#define IRECLIB_DO_NOT_USE_SIMD

// figure out which SIMD instructions we can use.

 
// ----------------------------------------------------------------------------------------



//    #include <avx2intrin.h>

// ----------------------------------------------------------------------------------------
// Define functions to check, at runtime, what instructions are available


    inline std::array<unsigned int,4> cpuid(int function_id) 
    { 
        std::array<unsigned int,4> info;
        // Load EAX, EBX, ECX, EDX into info
        __cpuid((int*)info.data(), function_id);
        return info;
    }


    inline std::array<unsigned int,4> cpuid(int function_id) 
    { 
        std::array<unsigned int,4> info;
        // Load EAX, EBX, ECX, EDX into info
        __cpuid_count(function_id, 0, info[0], info[1], info[2], info[3]);
        return info;
    }


    inline std::array<unsigned int,4> cpuid(int) 
    {
        std::array<unsigned int,4> info = { 0 };
        return info;
    }


    inline bool cpu_has_sse2_instructions()   { return 0!=(cpuid(1)[3]&(1<<26)); }
    inline bool cpu_has_sse3_instructions()   { return 0!=(cpuid(1)[2]&(1<<0));  }
    inline bool cpu_has_sse41_instructions()  { return 0!=(cpuid(1)[2]&(1<<19)); }
    inline bool cpu_has_sse42_instructions()  { return 0!=(cpuid(1)[2]&(1<<20)); }
    inline bool cpu_has_avx_instructions()    { return 0!=(cpuid(1)[2]&(1<<28)); }
    inline bool cpu_has_avx2_instructions()   { return 0!=(cpuid(7)[1]&(1<<5));  }
    inline bool cpu_has_avx512_instructions() { return 0!=(cpuid(7)[1]&(1<<16)); }

    inline void warn_about_unavailable_but_used_cpu_instructions()
    {
        if (!cpu_has_avx2_instructions())
            std::cerr << "IRECLIB was compiled to use AVX2 instructions, but these aren't available on your machine." << std::endl;
        if (!cpu_has_avx_instructions())
            std::cerr << "IRECLIB was compiled to use AVX instructions, but these aren't available on your machine." << std::endl;
        if (!cpu_has_sse41_instructions())
            std::cerr << "IRECLIB was compiled to use SSE41 instructions, but these aren't available on your machine." << std::endl;
        if (!cpu_has_sse3_instructions())
            std::cerr << "IRECLIB was compiled to use SSE3 instructions, but these aren't available on your machine." << std::endl;
        if (!cpu_has_sse2_instructions())
            std::cerr << "IRECLIB was compiled to use SSE2 instructions, but these aren't available on your machine." << std::endl;
    }

// ----------------------------------------------------------------------------------------



