

cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

if(POLICY CMP0077)
   cmake_policy(SET CMP0077 NEW)
endif()

project(ireclib)

set(CPACK_PACKAGE_NAME "ireclib")
set(CPACK_PACKAGE_VERSION_MAJOR "20")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "99")
set(VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})
if (NOT TARGET ireclib)
   message(STATUS "Using CMake version: ${CMAKE_VERSION}")
   message(STATUS "Compiling ireclib version: ${VERSION}")
endif()


include(cmake_utils/set_compiler_specific_options.cmake)


include(GNUInstallDirs)

if (POLICY CMP0075)
   cmake_policy(SET CMP0075 NEW)
endif()

include(cmake_utils/release_build_by_default)

get_directory_property(has_parent PARENT_DIRECTORY)
if(has_parent)
   set(IRECLIB_VERSION ${VERSION} PARENT_SCOPE)
   if (NOT DEFINED IRECLIB_IN_PROJECT_BUILD)
      set(IRECLIB_IN_PROJECT_BUILD true)
   endif()
endif()


if (COMMAND pybind11_add_module AND MSVC)
   set (BUILDING_PYTHON_IN_MSVC true)
else()
   set (BUILDING_PYTHON_IN_MSVC false)
endif()

if (IRECLIB_IN_PROJECT_BUILD)

   if (COMMAND pybind11_add_module)
      set(CMAKE_POSITION_INDEPENDENT_CODE True)
      if (CMAKE_COMPILER_IS_GNUCXX)
         add_definitions("-fPIC")
      endif()
      list(APPEND active_preprocessor_switches "-DIRECLIB_NO_ABORT_ON_2ND_FATAL_ERROR")
   endif()

   if (BUILD_SHARED_LIBS)
      if (CMAKE_COMPILER_IS_GNUCXX)
         add_definitions("-fPIC")
      endif()
      set(CMAKE_POSITION_INDEPENDENT_CODE true)
   endif()

   set(BUILD_SHARED_LIBS false)

elseif(BUILD_SHARED_LIBS)
   if (MSVC)
      message(FATAL_ERROR "Building ireclib as a standalone dll is not supported when using Visual Studio.  You are highly encouraged to use static linking instead.  See https://github.com/davisking/ireclib/issues/1483 for a discussion.") 
   endif()
endif()


if (CMAKE_VERSION VERSION_LESS "3.9.0")
   cmake_policy(SET CMP0023 OLD)
else()
   set(CUDA_LINK_LIBRARIES_KEYWORD PUBLIC)
endif()


macro (enable_preprocessor_switch option_name)
   list(APPEND active_preprocessor_switches "-D${option_name}")
endmacro()

macro (disable_preprocessor_switch option_name)
   if (active_preprocessor_switches)
      list(REMOVE_ITEM active_preprocessor_switches "-D${option_name}")
   endif()
endmacro()

macro (toggle_preprocessor_switch option_name)
   if (${option_name})
      enable_preprocessor_switch(${option_name})
   else()
      disable_preprocessor_switch(${option_name})
   endif()
endmacro()



if (CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
   set(CMAKE_C_ARCHIVE_CREATE   "<CMAKE_AR> Scr <TARGET> <LINK_FLAGS> <OBJECTS>")
   set(CMAKE_C_ARCHIVE_FINISH   "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
endif()
if (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
   set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> Scr <TARGET> <LINK_FLAGS> <OBJECTS>")
   set(CMAKE_CXX_ARCHIVE_FINISH "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
endif()

if (NOT TARGET ireclib)

   set (IRECLIB_ISO_CPP_ONLY_STR 
      "Enable this if you don't want to compile any non-ISO C++ code (i.e. you don't use any of the API Wrappers)" )
   set (IRECLIB_NO_GUI_SUPPORT_STR 
      "Enable this if you don't want to compile any of the ireclib GUI code" )
   set (IRECLIB_ENABLE_STACK_TRACE_STR 
      "Enable this if you want to turn on the IRECLIB_STACK_TRACE macros" )
   set (IRECLIB_USE_BLAS_STR
      "Disable this if you don't want to use a BLAS library" )
   set (IRECLIB_USE_LAPACK_STR
      "Disable this if you don't want to use a LAPACK library" )
   set (IRECLIB_USE_CUDA_STR
      "Disable this if you don't want to use NVIDIA CUDA" )
   set (IRECLIB_USE_CUDA_COMPUTE_CAPABILITIES_STR
      "Set this to a comma-separated list of CUDA compute capabilities" )
   set (IRECLIB_USE_MKL_SEQUENTIAL_STR
      "Enable this if you have MKL installed and want to use the sequential version instead of the multi-core version." )
   set (IRECLIB_USE_MKL_WITH_TBB_STR
      "Enable this if you have MKL installed and want to use the tbb version instead of the openmp version." )
   set (IRECLIB_PNG_SUPPORT_STR
      "Disable this if you don't want to link against libpng" )
   set (IRECLIB_GIF_SUPPORT_STR
      "Disable this if you don't want to link against libgif" )
   set (IRECLIB_JPEG_SUPPORT_STR
      "Disable this if you don't want to link against libjpeg" )
   set (IRECLIB_WEBP_SUPPORT_STR
      "Disable this if you don't want to link against libwebp" )
   set (IRECLIB_JXL_SUPPORT_STR
      "Disable this if you don't want to link against libjxl" )
   set (IRECLIB_LINK_WITH_SQLITE3_STR
      "Disable this if you don't want to link against sqlite3" )
   set (IRECLIB_USE_MKL_FFT_STR
      "Disable this is you don't want to use the MKL DFTI FFT implementation" )
   set (IRECLIB_ENABLE_ASSERTS_STR
      "Enable this if you want to turn on the IRECLIB_ASSERT macro" )
   set (IRECLIB_USE_FFMPEG_STR
      "Disable this if you don't want to use the FFMPEG library" )

   option(IRECLIB_ENABLE_ASSERTS ${IRECLIB_ENABLE_ASSERTS_STR} OFF)
   option(IRECLIB_ISO_CPP_ONLY ${IRECLIB_ISO_CPP_ONLY_STR} OFF)
   toggle_preprocessor_switch(IRECLIB_ISO_CPP_ONLY)
   option(IRECLIB_NO_GUI_SUPPORT ${IRECLIB_NO_GUI_SUPPORT_STR} OFF)
   toggle_preprocessor_switch(IRECLIB_NO_GUI_SUPPORT)
   option(IRECLIB_ENABLE_STACK_TRACE ${IRECLIB_ENABLE_STACK_TRACE_STR} OFF)
   toggle_preprocessor_switch(IRECLIB_ENABLE_STACK_TRACE)
   option(IRECLIB_USE_MKL_SEQUENTIAL ${IRECLIB_USE_MKL_SEQUENTIAL_STR} OFF)
   option(IRECLIB_USE_MKL_WITH_TBB ${IRECLIB_USE_MKL_WITH_TBB_STR} OFF)

   if(IRECLIB_ENABLE_ASSERTS)
      set (IRECLIB_DISABLE_ASSERTS false)
      set (ENABLE_ASSERTS true) 
      enable_preprocessor_switch(ENABLE_ASSERTS)
      disable_preprocessor_switch(IRECLIB_DISABLE_ASSERTS)
   else()
      set (IRECLIB_DISABLE_ASSERTS true)
      set (ENABLE_ASSERTS false) 
      disable_preprocessor_switch(ENABLE_ASSERTS)
      if (NOT IRECLIB_IN_PROJECT_BUILD)
         enable_preprocessor_switch(IRECLIB_DISABLE_ASSERTS)
      endif()
   endif()

   if (IRECLIB_ISO_CPP_ONLY)
      option(IRECLIB_JPEG_SUPPORT ${IRECLIB_JPEG_SUPPORT_STR} OFF)
      option(IRECLIB_LINK_WITH_SQLITE3 ${IRECLIB_LINK_WITH_SQLITE3_STR} OFF)
      option(IRECLIB_USE_BLAS ${IRECLIB_USE_BLAS_STR} OFF)
      option(IRECLIB_USE_LAPACK ${IRECLIB_USE_LAPACK_STR} OFF)
      option(IRECLIB_USE_CUDA ${IRECLIB_USE_CUDA_STR} OFF)
      option(IRECLIB_PNG_SUPPORT ${IRECLIB_PNG_SUPPORT_STR} OFF)
      option(IRECLIB_GIF_SUPPORT ${IRECLIB_GIF_SUPPORT_STR} OFF)
      option(IRECLIB_WEBP_SUPPORT ${IRECLIB_WEBP_SUPPORT_STR} OFF)
      option(IRECLIB_JXL_SUPPORT ${IRECLIB_JXL_SUPPORT_STR} OFF)
      option(IRECLIB_USE_MKL_FFT ${IRECLIB_USE_MKL_FFT_STR} OFF)
      option(IRECLIB_USE_FFMPEG ${IRECLIB_USE_FFMPEG_STR} OFF)
   else()
      option(IRECLIB_JPEG_SUPPORT ${IRECLIB_JPEG_SUPPORT_STR} ON)
      option(IRECLIB_LINK_WITH_SQLITE3 ${IRECLIB_LINK_WITH_SQLITE3_STR} ON)
      option(IRECLIB_USE_BLAS ${IRECLIB_USE_BLAS_STR} ON)
      option(IRECLIB_USE_LAPACK ${IRECLIB_USE_LAPACK_STR} ON)
      option(IRECLIB_USE_CUDA ${IRECLIB_USE_CUDA_STR} ON)
      set(IRECLIB_USE_CUDA_COMPUTE_CAPABILITIES 50 CACHE STRING ${IRECLIB_USE_CUDA_COMPUTE_CAPABILITIES_STR})
      option(IRECLIB_PNG_SUPPORT ${IRECLIB_PNG_SUPPORT_STR} ON)
      option(IRECLIB_GIF_SUPPORT ${IRECLIB_GIF_SUPPORT_STR} ON)
      option(IRECLIB_WEBP_SUPPORT ${IRECLIB_WEBP_SUPPORT_STR} ON)
      option(IRECLIB_JXL_SUPPORT ${IRECLIB_JXL_SUPPORT_STR} ON)
      option(IRECLIB_USE_MKL_FFT ${IRECLIB_USE_MKL_FFT_STR} ON)
      option(IRECLIB_USE_FFMPEG ${IRECLIB_USE_FFMPEG_STR} ON)
   endif()
   toggle_preprocessor_switch(IRECLIB_JPEG_SUPPORT)
   toggle_preprocessor_switch(IRECLIB_USE_BLAS)
   toggle_preprocessor_switch(IRECLIB_USE_LAPACK)
   toggle_preprocessor_switch(IRECLIB_USE_CUDA)
   toggle_preprocessor_switch(IRECLIB_PNG_SUPPORT) 
   toggle_preprocessor_switch(IRECLIB_GIF_SUPPORT) 
   toggle_preprocessor_switch(IRECLIB_WEBP_SUPPORT)
   toggle_preprocessor_switch(IRECLIB_JXL_SUPPORT) 
   toggle_preprocessor_switch(IRECLIB_USE_MKL_FFT)
   toggle_preprocessor_switch(IRECLIB_USE_FFMPEG)


   set(source_files
      base64/base64_kernel_1.cpp
      bigint/bigint_kernel_1.cpp
      bigint/bigint_kernel_2.cpp
      bit_stream/bit_stream_kernel_1.cpp
      entropy_decoder/entropy_decoder_kernel_1.cpp
      entropy_decoder/entropy_decoder_kernel_2.cpp
      entropy_encoder/entropy_encoder_kernel_1.cpp
      entropy_encoder/entropy_encoder_kernel_2.cpp
      md5/md5_kernel_1.cpp
      tokenizer/tokenizer_kernel_1.cpp
      unicode/unicode.cpp
      test_for_odr_violations.cpp
      fft/fft.cpp
      )

   set(ireclib_needed_public_libraries)
   set(ireclib_needed_public_includes)
   set(ireclib_needed_public_cflags)
   set(ireclib_needed_public_ldflags)
   set(ireclib_needed_private_libraries)
   set(ireclib_needed_private_includes)

   if (IRECLIB_ISO_CPP_ONLY)
      add_library(ireclib ${source_files} )
   else()

      set(source_files ${source_files}
         sockets/sockets_kernel_1.cpp
         bsp/bsp.cpp
         dir_nav/dir_nav_kernel_1.cpp
         dir_nav/dir_nav_kernel_2.cpp
         dir_nav/dir_nav_extensions.cpp
         gui_widgets/fonts.cpp
         linker/linker_kernel_1.cpp
         logger/extra_logger_headers.cpp
         logger/logger_kernel_1.cpp
         logger/logger_config_file.cpp
         misc_api/misc_api_kernel_1.cpp
         misc_api/misc_api_kernel_2.cpp
         sockets/sockets_extensions.cpp
         sockets/sockets_kernel_2.cpp
         sockstreambuf/sockstreambuf.cpp
         sockstreambuf/sockstreambuf_unbuffered.cpp
         server/server_kernel.cpp
         server/server_iostream.cpp
         server/server_http.cpp
         threads/multithreaded_object_extension.cpp
         threads/threaded_object_extension.cpp
         threads/threads_kernel_1.cpp
         threads/threads_kernel_2.cpp
         threads/threads_kernel_shared.cpp
         threads/thread_pool_extension.cpp
         threads/async.cpp
         timer/timer.cpp
         stack_trace.cpp
         cuda/cpu_ireclib.cpp
         cuda/tensor_tools.cpp
         data_io/image_dataset_metadata.cpp
         data_io/mnist.cpp
         data_io/cifar.cpp
         global_optimization/global_function_search.cpp
         filtering/kalman_filter.cpp
         svm/auto.cpp
         )

      if(UNIX)
         set(CMAKE_THREAD_PREFER_PTHREAD ON)
         find_package(Threads REQUIRED)
         list (APPEND ireclib_needed_private_libraries ${CMAKE_THREAD_LIBS_INIT})
      endif()

      if (WIN32 AND NOT CYGWIN) ###############################################################################
         if (IRECLIB_NO_GUI_SUPPORT)
            list (APPEND ireclib_needed_private_libraries ws2_32 winmm)
         else()
            list (APPEND ireclib_needed_private_libraries ws2_32 winmm comctl32 gdi32 imm32)
         endif()
      elseif(APPLE) ############################################################################
         set(CMAKE_MACOSX_RPATH 1)
         if (NOT IRECLIB_NO_GUI_SUPPORT)
            find_package(X11 QUIET)
            if (X11_FOUND)
               foreach (ITR ${X11_INCLUDE_DIR})
                  if ("${ITR}" MATCHES "(.*)(Ana|ana|mini)conda(.*)")
                     list (REMOVE_ITEM X11_INCLUDE_DIR ${ITR})
                  endif ()
               endforeach(ITR)
               list (APPEND ireclib_needed_public_includes ${X11_INCLUDE_DIR})
               list (APPEND ireclib_needed_public_libraries ${X11_LIBRARIES})
            else()
               find_library(xlib X11)
               find_path(xlib_path Xlocale.h
                  PATHS 
                  /Developer/SDKs/MacOSX10.4u.sdk/usr/X11R6/include
                  /opt/local/include
                  PATH_SUFFIXES X11
                  )
               if (xlib AND xlib_path)
                  get_filename_component(x11_path ${xlib_path} PATH CACHE)
                  list (APPEND ireclib_needed_public_includes ${x11_path})
                  list (APPEND ireclib_needed_public_libraries ${xlib})
                  set(X11_FOUND 1)
               endif()
            endif()
            if (NOT X11_FOUND)
               message(" *****************************************************************************")
               message(" *** IRECLIB GUI SUPPORT DISABLED BECAUSE X11 DEVELOPMENT LIBRARIES NOT FOUND ***")
               message(" *** Make sure XQuartz is installed if you want GUI support.               ***")
               message(" *** You can download XQuartz from: https://www.xquartz.org/               ***")
               message(" *****************************************************************************")
               set(IRECLIB_NO_GUI_SUPPORT ON CACHE STRING ${IRECLIB_NO_GUI_SUPPORT_STR} FORCE )
               enable_preprocessor_switch(IRECLIB_NO_GUI_SUPPORT)
            endif()
         endif()

         mark_as_advanced(xlib xlib_path x11_path)
      else () ##################################################################################
         find_library(socketlib socket)
         if (socketlib)
            list (APPEND ireclib_needed_private_libraries ${socketlib})
         endif ()

         if (NOT IRECLIB_NO_GUI_SUPPORT)
            include(FindX11)
            if (X11_FOUND)
               list (APPEND ireclib_needed_private_includes ${X11_INCLUDE_DIR})
               list (APPEND ireclib_needed_private_libraries ${X11_LIBRARIES})
            else()
               message(" *****************************************************************************")
               message(" *** IRECLIB GUI SUPPORT DISABLED BECAUSE X11 DEVELOPMENT LIBRARIES NOT FOUND ***")
               message(" *** Make sure libx11-dev is installed if you want GUI support.            ***")
               message(" *** On Ubuntu run: sudo apt-get install libx11-dev                        ***")
               message(" *****************************************************************************")
               set(IRECLIB_NO_GUI_SUPPORT ON CACHE STRING ${IRECLIB_NO_GUI_SUPPORT_STR} FORCE )
               enable_preprocessor_switch(IRECLIB_NO_GUI_SUPPORT)
            endif()
         endif()

         mark_as_advanced(nsllib socketlib)
      endif () ##################################################################################

      if (NOT IRECLIB_NO_GUI_SUPPORT)
         set(source_files ${source_files}
            gui_widgets/widgets.cpp
            gui_widgets/drawable.cpp
            gui_widgets/canvas_drawing.cpp
            gui_widgets/style.cpp
            gui_widgets/base_widgets.cpp
            gui_core/gui_core_kernel_1.cpp
            gui_core/gui_core_kernel_2.cpp
            )
      endif()

      INCLUDE (CheckFunctionExists)

      if (IRECLIB_GIF_SUPPORT)
         find_package(GIF QUIET)
         if (GIF_FOUND)
            list (APPEND ireclib_needed_public_includes ${GIF_INCLUDE_DIR})
            list (APPEND ireclib_needed_public_libraries ${GIF_LIBRARY})
         else()
            set(IRECLIB_GIF_SUPPORT OFF CACHE STRING ${IRECLIB_GIF_SUPPORT_STR} FORCE )
            toggle_preprocessor_switch(IRECLIB_GIF_SUPPORT)
         endif()
      endif()

      if (IRECLIB_PNG_SUPPORT)
         include(cmake_utils/find_libpng.cmake)
         if (PNG_FOUND)
            list (APPEND ireclib_needed_private_includes ${PNG_INCLUDE_DIR})
            list (APPEND ireclib_needed_private_libraries ${PNG_LIBRARIES})
         else()
            include_directories(external/libpng external/zlib)
            set(source_files ${source_files}
               external/libpng/arm/arm_init.c
               external/libpng/arm/filter_neon_intrinsics.c
               external/libpng/arm/palette_neon_intrinsics.c
               external/libpng/png.c
               external/libpng/pngerror.c
               external/libpng/pngget.c
               external/libpng/pngmem.c
               external/libpng/pngpread.c
               external/libpng/pngread.c
               external/libpng/pngrio.c
               external/libpng/pngrtran.c
               external/libpng/pngrutil.c
               external/libpng/pngset.c
               external/libpng/pngtrans.c
               external/libpng/pngwio.c
               external/libpng/pngwrite.c
               external/libpng/pngwtran.c
               external/libpng/pngwutil.c
               external/zlib/adler32.c
               external/zlib/compress.c
               external/zlib/crc32.c
               external/zlib/deflate.c
               external/zlib/gzclose.c
               external/zlib/gzlib.c
               external/zlib/gzread.c
               external/zlib/gzwrite.c
               external/zlib/infback.c
               external/zlib/inffast.c
               external/zlib/inflate.c
               external/zlib/inftrees.c
               external/zlib/trees.c
               external/zlib/uncompr.c
               external/zlib/zutil.c
               )

            include(cmake_utils/check_if_neon_available.cmake)
            if (ARM_NEON_IS_AVAILABLE)
               message (STATUS "NEON instructions will be used for libpng.")
               enable_language(ASM)
               set(source_files ${source_files}
                  external/libpng/arm/arm_init.c
                  external/libpng/arm/filter_neon_intrinsics.c
                  external/libpng/arm/filter_neon.S
                  )
               set_source_files_properties(external/libpng/arm/filter_neon.S PROPERTIES COMPILE_FLAGS "${CMAKE_ASM_FLAGS} ${CMAKE_CXX_FLAGS} -x assembler-with-cpp")
            endif()
         endif()
         set(source_files ${source_files}
            image_loader/png_loader.cpp
            image_saver/save_png.cpp
            )
      endif()

      if (IRECLIB_JPEG_SUPPORT)
         include(cmake_utils/find_libjpeg.cmake)
         if (JPEG_FOUND)
            list (APPEND ireclib_needed_private_includes ${JPEG_INCLUDE_DIR})
            list (APPEND ireclib_needed_private_libraries ${JPEG_LIBRARY})
         else()
            add_definitions(-DIRECLIB_JPEG_STATIC)
            set(source_files ${source_files}
              external/libjpeg/jaricom.c
              external/libjpeg/jcapimin.c
              external/libjpeg/jcapistd.c
              external/libjpeg/jcarith.c
              external/libjpeg/jccoefct.c
              external/libjpeg/jccolor.c
              external/libjpeg/jcdctmgr.c
              external/libjpeg/jchuff.c
              external/libjpeg/jcinit.c
              external/libjpeg/jcmainct.c
              external/libjpeg/jcmarker.c
              external/libjpeg/jcmaster.c
              external/libjpeg/jcomapi.c
              external/libjpeg/jcparam.c
              external/libjpeg/jcprepct.c
              external/libjpeg/jcsample.c
              external/libjpeg/jdapimin.c
              external/libjpeg/jdapistd.c
              external/libjpeg/jdarith.c
              external/libjpeg/jdatadst.c
              external/libjpeg/jdatasrc.c
              external/libjpeg/jdcoefct.c
              external/libjpeg/jdcolor.c
              external/libjpeg/jddctmgr.c
              external/libjpeg/jdhuff.c
              external/libjpeg/jdinput.c
              external/libjpeg/jdmainct.c
              external/libjpeg/jdmarker.c
              external/libjpeg/jdmaster.c
              external/libjpeg/jdmerge.c
              external/libjpeg/jdpostct.c
              external/libjpeg/jdsample.c
              external/libjpeg/jerror.c
              external/libjpeg/jfdctflt.c
              external/libjpeg/jfdctfst.c
              external/libjpeg/jfdctint.c
              external/libjpeg/jidctflt.c
              external/libjpeg/jidctfst.c
              external/libjpeg/jidctint.c
              external/libjpeg/jmemmgr.c
              external/libjpeg/jmemnobs.c
              external/libjpeg/jquant1.c
              external/libjpeg/jquant2.c
              external/libjpeg/jutils.c
               )
         endif()
         set(source_files ${source_files}
            image_loader/jpeg_loader.cpp
            image_saver/save_jpeg.cpp
            )
      endif()
      if (IRECLIB_WEBP_SUPPORT)
         include(cmake_utils/find_libwebp.cmake)
         if (WEBP_FOUND)
            list (APPEND ireclib_needed_private_includes ${WEBP_INCLUDE_DIR})
            list (APPEND ireclib_needed_private_libraries ${WEBP_LIBRARY})
            set(source_files ${source_files}
               image_loader/webp_loader.cpp
               image_saver/save_webp.cpp
               )
         else()
             set(IRECLIB_WEBP_SUPPORT OFF CACHE BOOL ${IRECLIB_WEBP_SUPPORT_STR} FORCE )
             toggle_preprocessor_switch(IRECLIB_WEBP_SUPPORT)
         endif()
      endif()
      if (IRECLIB_JXL_SUPPORT)
         include(cmake_utils/find_libjxl.cmake)
         if (JXL_FOUND)
            list (APPEND ireclib_needed_private_includes ${JXL_INCLUDE_DIRS})
            list (APPEND ireclib_needed_private_libraries ${JXL_LIBRARIES})
            list (APPEND ireclib_needed_public_cflags ${JXL_CFLAGS})
            list (APPEND ireclib_needed_public_ldflags ${JXL_LDFLAGS})
            set(source_files ${source_files}
               image_loader/jxl_loader.cpp
               image_saver/save_jxl.cpp
               )
            enable_preprocessor_switch(IRECLIB_JXL_SUPPORT)
         else()
            set(IRECLIB_JXL_SUPPORT OFF CACHE BOOL ${IRECLIB_JXL_SUPPORT_STR} FORCE)
            disable_preprocessor_switch(IRECLIB_JXL_SUPPORT)
         endif()
      endif()


      if (IRECLIB_USE_BLAS OR IRECLIB_USE_LAPACK OR IRECLIB_USE_MKL_FFT)
         if (IRECLIB_USE_MKL_WITH_TBB AND IRECLIB_USE_MKL_SEQUENTIAL)
            set(IRECLIB_USE_MKL_SEQUENTIAL OFF CACHE STRING ${IRECLIB_USE_MKL_SEQUENTIAL_STR} FORCE )
            toggle_preprocessor_switch(IRECLIB_USE_MKL_SEQUENTIAL)
            message(STATUS "Disabling IRECLIB_USE_MKL_SEQUENTIAL. It cannot be used simultaneously with IRECLIB_USE_MKL_WITH_TBB.")
         endif()


         include(cmake_utils/find_blas.cmake)

         if (IRECLIB_USE_BLAS)
            if (blas_found)
               list (APPEND ireclib_needed_public_libraries ${blas_libraries})
            else()
               set(IRECLIB_USE_BLAS OFF CACHE STRING ${IRECLIB_USE_BLAS_STR} FORCE )
               toggle_preprocessor_switch(IRECLIB_USE_BLAS)
            endif()
         endif()

         if (IRECLIB_USE_LAPACK)
            if (lapack_found)
               list (APPEND ireclib_needed_public_libraries ${lapack_libraries})
               if (lapack_with_underscore)
                  set(LAPACK_FORCE_UNDERSCORE 1)
                  enable_preprocessor_switch(LAPACK_FORCE_UNDERSCORE)
               elseif (lapack_without_underscore)
                  set(LAPACK_FORCE_NOUNDERSCORE 1)
                  enable_preprocessor_switch(LAPACK_FORCE_NOUNDERSCORE)
               endif ()
            else()
               set(IRECLIB_USE_LAPACK OFF CACHE STRING ${IRECLIB_USE_LAPACK_STR} FORCE )
               toggle_preprocessor_switch(IRECLIB_USE_LAPACK)
            endif()
         endif()

         if (IRECLIB_USE_MKL_FFT)
            if (found_intel_mkl AND found_intel_mkl_headers)
               list (APPEND ireclib_needed_public_includes ${mkl_include_dir})
               list (APPEND ireclib_needed_public_libraries ${mkl_libraries})
            else()
               set(IRECLIB_USE_MKL_FFT OFF CACHE STRING ${IRECLIB_USE_MKL_FFT_STR} FORCE )
               toggle_preprocessor_switch(IRECLIB_USE_MKL_FFT)
            endif()
         endif()
      endif()


      if (IRECLIB_USE_CUDA)
         find_package(CUDA 7.5)

         if (CUDA_VERSION VERSION_GREATER 9.1 AND CMAKE_VERSION VERSION_LESS 3.12.2)
            list(REMOVE_ITEM CUDA_CUBLAS_LIBRARIES "CUDA_cublas_device_LIBRARY-NOTFOUND")
         endif()


         if (CUDA_FOUND AND MSVC AND NOT CUDA_CUBLAS_LIBRARIES AND "${CMAKE_SIZEOF_VOID_P}" EQUAL "4")
            message(WARNING "You have CUDA installed, but we can't use it unless you put visual studio in 64bit mode.")
            set(CUDA_FOUND 0)
         endif()

         if (NOT CUDA_CUBLAS_LIBRARIES)
            message(STATUS "Found CUDA, but CMake was unable to find the cuBLAS libraries that should be part of every basic CUDA "
               "install. Your CUDA install is somehow broken or incomplete. Since cuBLAS is required for ireclib to use CUDA we won't use CUDA.")
            set(CUDA_FOUND 0)
         endif()

         if (CUDA_FOUND)

            if (APPLE)
               set(CUDA_PROPAGATE_HOST_FLAGS OFF)
               string(REGEX MATCHALL "-D[^ ]*" FLAGS_FOR_NVCC "${CMAKE_CXX_FLAGS}")

               if (COMMAND pybind11_add_module)
                  list(APPEND FLAGS_FOR_NVCC "-Xcompiler=-fvisibility=hidden")
               endif()
            endif()

            set(CUDA_HOST_COMPILATION_CPP ON)
            string(REPLACE "," ";" IRECLIB_CUDA_COMPUTE_CAPABILITIES ${IRECLIB_USE_CUDA_COMPUTE_CAPABILITIES})
            foreach(CAP ${IRECLIB_CUDA_COMPUTE_CAPABILITIES})
                list(APPEND CUDA_NVCC_FLAGS "-gencode arch=compute_${CAP},code=[sm_${CAP},compute_${CAP}]")
            endforeach()
            list(APPEND CUDA_NVCC_FLAGS "-D__STRICT_ANSI__;-D_MWAITXINTRIN_H_INCLUDED;-D_FORCE_INLINES;${FLAGS_FOR_NVCC}")
            list(APPEND CUDA_NVCC_FLAGS ${active_preprocessor_switches})
            if (NOT IRECLIB_IN_PROJECT_BUILD)
               LIST(APPEND CUDA_NVCC_FLAGS -DIRECLIB__CMAKE_GENERATED_A_CONFIG_H_FILE)
            endif()
            if (NOT MSVC)
               list(APPEND CUDA_NVCC_FLAGS "-std=c++14")
            endif()
            if (CMAKE_POSITION_INDEPENDENT_CODE)
               if (NOT MSVC) # Visual studio doesn't have -fPIC so don't do it in that case.
                  list(APPEND CUDA_NVCC_FLAGS "-Xcompiler -fPIC")
               endif()
            endif()

            include(cmake_utils/test_for_cudnn/find_cudnn.txt)

            if (cudnn AND cudnn_include AND NOT DEFINED cuda_test_compile_worked AND NOT DEFINED cudnn_test_compile_worked)
               message(STATUS "Building a CUDA test project to see if your compiler is compatible with CUDA...")

               set(CUDA_TEST_CMAKE_FLAGS 
                  "-DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}"
                  "-DCMAKE_INCLUDE_PATH=${CMAKE_INCLUDE_PATH}"
                  "-DCMAKE_LIBRARY_PATH=${CMAKE_LIBRARY_PATH}")

               if (NOT MSVC) # see https://github.com/davisking/ireclib/issues/363
                  list(APPEND CUDA_TEST_CMAKE_FLAGS "-DCUDA_HOST_COMPILER=${CUDA_HOST_COMPILER}")
               endif()

               try_compile(cuda_test_compile_worked 
                  ${PROJECT_BINARY_DIR}/cuda_test_build 
                  ${PROJECT_SOURCE_DIR}/cmake_utils/test_for_cuda cuda_test
                  CMAKE_FLAGS ${CUDA_TEST_CMAKE_FLAGS}
                  OUTPUT_VARIABLE try_compile_output_message
                  )
               if (NOT cuda_test_compile_worked)
                  string(REPLACE "\n" "\n   ***   " try_compile_output_message "${try_compile_output_message}")
                  message(STATUS "*****************************************************************************************************************")
                  message(STATUS "*** CUDA was found but your compiler failed to compile a simple CUDA program so ireclib isn't going to use CUDA. ")
                  message(STATUS "*** The output of the failed CUDA test compile is shown below: ")
                  message(STATUS "*** ")
                  message(STATUS "***   ${try_compile_output_message}")
                  message(STATUS "*****************************************************************************************************************")
               else()
                  message(STATUS "Building a cuDNN test project to check if you have the right version of cuDNN installed...")
                  try_compile(cudnn_test_compile_worked 
                     ${PROJECT_BINARY_DIR}/cudnn_test_build 
                     ${PROJECT_SOURCE_DIR}/cmake_utils/test_for_cudnn cudnn_test
                     CMAKE_FLAGS ${CUDA_TEST_CMAKE_FLAGS}
                     OUTPUT_VARIABLE try_compile_output_message
                     )
                  if (NOT cudnn_test_compile_worked)
                     string(REPLACE "\n" "\n   ***   " try_compile_output_message "${try_compile_output_message}")
                     message(STATUS "*****************************************************************************************************")
                     message(STATUS "*** Found cuDNN, but we failed to compile the ireclib/cmake_utils/test_for_cudnn project. ")
                     message(STATUS "*** You either have an unsupported version of cuDNN or something is wrong with your cudDNN install.")
                     message(STATUS "*** Since a functional cuDNN is not found IRECLIB WILL NOT USE CUDA. ")
                     message(STATUS "*** The output of the failed test_for_cudnn build is: ")
                     message(STATUS "*** ")
                     message(STATUS "***   ${try_compile_output_message}")
                     message(STATUS "*****************************************************************************************************")
                  endif()
               endif()
            endif()

            if (NOT CUDA_cusolver_LIBRARY)
               get_filename_component(cuda_blas_path "${CUDA_CUBLAS_LIBRARIES}" DIRECTORY)
               find_library(CUDA_cusolver_LIBRARY cusolver HINTS ${cuda_blas_path})
               if (NOT CUDA_cusolver_LIBRARY)
                  find_library(CUDA_cusolver_LIBRARY cusolver HINTS 
                     /usr/local/cuda/lib64/
                     )
               endif()
               mark_as_advanced(CUDA_cusolver_LIBRARY)
            endif()
            if (CUDA_VERSION VERSION_LESS "9.1" AND NOT openmp_libraries AND NOT MSVC AND NOT XCODE AND NOT APPLE)
               find_package(OpenMP)
               if (OPENMP_FOUND)
                  set(openmp_libraries ${OpenMP_CXX_FLAGS}) 
               else()
                  message(STATUS "*** Didn't find OpenMP, which is required to use CUDA. ***")
                  set(CUDA_FOUND 0)
               endif()
            endif()
         endif()

         if (CUDA_FOUND AND cudnn AND cuda_test_compile_worked AND cudnn_test_compile_worked AND cudnn_include)
            set(source_files ${source_files} 
               cuda/cuda_ireclib.cu 
               cuda/cudnn_ireclibapi.cpp
               cuda/cublas_ireclibapi.cpp
               cuda/cusolver_ireclibapi.cu
               cuda/curand_ireclibapi.cpp
               cuda/cuda_data_ptr.cpp
               cuda/gpu_data.cpp
               )
            list (APPEND ireclib_needed_private_libraries ${CUDA_CUBLAS_LIBRARIES})
            list (APPEND ireclib_needed_private_libraries ${cudnn})
            list (APPEND ireclib_needed_private_libraries ${CUDA_curand_LIBRARY})
            list (APPEND ireclib_needed_private_libraries ${CUDA_cusolver_LIBRARY})
            list (APPEND ireclib_needed_private_libraries ${CUDA_CUDART_LIBRARY})
            if(openmp_libraries)
               list (APPEND ireclib_needed_private_libraries ${openmp_libraries})
            endif()

            include_directories(${cudnn_include})
            message(STATUS "Enabling CUDA support for ireclib.  IRECLIB WILL USE CUDA, compute capabilities: ${IRECLIB_CUDA_COMPUTE_CAPABILITIES}")
         else()
            set(IRECLIB_USE_CUDA OFF CACHE STRING ${IRECLIB_USE_BLAS_STR} FORCE )
            toggle_preprocessor_switch(IRECLIB_USE_CUDA)
            if (NOT CUDA_FOUND)
               message(STATUS "DID NOT FIND CUDA")
            endif()
            message(STATUS "Disabling CUDA support for ireclib.  IRECLIB WILL NOT USE CUDA")
         endif()
      endif()


      if (IRECLIB_LINK_WITH_SQLITE3)
         find_library(sqlite sqlite3)
         find_path(sqlite_path sqlite3.h)
         if (sqlite AND sqlite_path)
            list (APPEND ireclib_needed_public_includes ${sqlite_path})
            list (APPEND ireclib_needed_public_libraries ${sqlite} )
         else()
            set(IRECLIB_LINK_WITH_SQLITE3 OFF CACHE STRING ${IRECLIB_LINK_WITH_SQLITE3_STR} FORCE )
         endif()
         mark_as_advanced(sqlite sqlite_path)
      endif()



      if (IRECLIB_USE_FFTW)
         find_library(fftw fftw3)
         find_path(fftw_path fftw3.h)
         if (fftw AND fftw_path)
           list (APPEND ireclib_needed_private_includes ${fftw_path})
           list (APPEND ireclib_needed_private_libraries ${fftw})
         else()
            set(IRECLIB_USE_FFTW OFF CACHE STRING ${IRECLIB_USE_FFTW_STR} FORCE )
            toggle_preprocessor_switch(IRECLIB_USE_FFTW)
         endif()
         mark_as_advanced(fftw fftw_path)
      endif()

      if (IRECLIB_USE_FFMPEG)
         include(cmake_utils/find_ffmpeg.cmake)
         if (FFMPEG_FOUND)
            list (APPEND ireclib_needed_public_includes ${FFMPEG_INCLUDE_DIRS})
            list (APPEND ireclib_needed_public_libraries ${FFMPEG_LINK_LIBRARIES})
            list (APPEND ireclib_needed_public_cflags ${FFMPEG_CFLAGS})
            list (APPEND ireclib_needed_public_ldflags ${FFMPEG_LDFLAGS})
            enable_preprocessor_switch(IRECLIB_USE_FFMPEG)
         else()
            set(IRECLIB_USE_FFMPEG OFF CACHE BOOL ${IRECLIB_USE_FFMPEG_STR} FORCE )
            disable_preprocessor_switch(IRECLIB_USE_FFMPEG)
         endif()
      endif()

      if (IRECLIB_USE_CUDA)
         include_directories(${ireclib_needed_public_includes})
         cuda_add_library(ireclib ${source_files} )
      else()
         add_library(ireclib ${source_files} )
      endif()

   endif ()  ##### end of if NOT IRECLIB_ISO_CPP_ONLY ##########################################################


   target_include_directories(ireclib
      INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
      INTERFACE $<INSTALL_INTERFACE:include>
      PUBLIC ${ireclib_needed_public_includes}
      PRIVATE ${ireclib_needed_private_includes}
      )
   target_link_libraries(ireclib PUBLIC ${ireclib_needed_public_libraries} ${ireclib_needed_public_ldflags})
   target_link_libraries(ireclib PRIVATE ${ireclib_needed_private_libraries})
   target_compile_options(ireclib PUBLIC ${ireclib_needed_public_cflags})
   if (IRECLIB_IN_PROJECT_BUILD)
      target_compile_options(ireclib PUBLIC ${active_preprocessor_switches})
   else()
      target_compile_options(ireclib PRIVATE ${active_preprocessor_switches})
      target_compile_options(ireclib PRIVATE -DIRECLIB__CMAKE_GENERATED_A_CONFIG_H_FILE)

      set(IRECLIB_CHECK_FOR_VERSION_MISMATCH 
         IRECLIB_VERSION_MISMATCH_CHECK__EXPECTED_VERSION_${CPACK_PACKAGE_VERSION_MAJOR}_${CPACK_PACKAGE_VERSION_MINOR}_${CPACK_PACKAGE_VERSION_PATCH})
      target_compile_options(ireclib PRIVATE "-DIRECLIB_CHECK_FOR_VERSION_MISMATCH=${IRECLIB_CHECK_FOR_VERSION_MISMATCH}")
   endif()


   if (IRECLIB_TEST_COMPILE_ALL_SOURCE_CPP)
      add_library(ireclib_all_source_cpp STATIC all/source.cpp) 
      target_link_libraries(ireclib_all_source_cpp ireclib)
      target_compile_options(ireclib_all_source_cpp PUBLIC ${active_preprocessor_switches})
      target_compile_features(ireclib_all_source_cpp PUBLIC cxx_std_14)
   endif()

   target_compile_features(ireclib PUBLIC cxx_std_14)
   if((MSVC AND CMAKE_VERSION VERSION_LESS 3.11))
      target_compile_options(ireclib PUBLIC ${active_compile_opts})
      target_compile_options(ireclib PRIVATE ${active_compile_opts_private})
   else()
      target_compile_options(ireclib PUBLIC $<$<COMPILE_LANGUAGE:CXX>:${active_compile_opts}>)
      target_compile_options(ireclib PRIVATE $<$<COMPILE_LANGUAGE:CXX>:${active_compile_opts_private}>)
   endif()

   if (NOT IRECLIB_IN_PROJECT_BUILD)
      string (REPLACE ";" " " pkg_config_ireclib_needed_libraries "${ireclib_needed_public_libraries}")
      foreach (ITR ${ireclib_needed_public_includes})
         set (pkg_config_ireclib_needed_includes "${pkg_config_ireclib_needed_includes} -I${ITR}")
      endforeach()
      set_target_properties(ireclib PROPERTIES
         VERSION ${VERSION})
      install(TARGETS ireclib
         EXPORT ireclib 
         RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # Windows considers .dll to be runtime artifacts
         LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
         ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

      install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ireclib
         FILES_MATCHING 
            PATTERN "*.h" 
            PATTERN "*.cmake"
            PATTERN "*_tutorial.txt"
            PATTERN "cassert"
            PATTERN "cstring"
            PATTERN "fstream"
            PATTERN "iomanip"
            PATTERN "iosfwd"
            PATTERN "iostream"
            PATTERN "istream"
            PATTERN "locale"
            PATTERN "ostream"
            PATTERN "sstream"
            REGEX "${CMAKE_CURRENT_BINARY_DIR}" EXCLUDE)


      configure_file(${PROJECT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h)
      install(FILES ${CMAKE_CURRENT_BINARY_DIR}/config.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ireclib)

      configure_file(${PROJECT_SOURCE_DIR}/revision.h.in ${CMAKE_CURRENT_BINARY_DIR}/revision.h)
      install(FILES ${CMAKE_CURRENT_BINARY_DIR}/revision.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ireclib)


      set(ConfigPackageLocation "${CMAKE_INSTALL_LIBDIR}/cmake/ireclib")
      install(EXPORT ireclib
         NAMESPACE ireclib::
         DESTINATION ${ConfigPackageLocation})

      configure_file(cmake_utils/ireclibConfig.cmake.in "${CMAKE_CURRENT_BINARY_DIR}/config/ireclibConfig.cmake" @ONLY)

      include(CMakePackageConfigHelpers)
      write_basic_package_version_file(
         "${CMAKE_CURRENT_BINARY_DIR}/config/ireclibConfigVersion.cmake"
         VERSION ${VERSION}
         COMPATIBILITY AnyNewerVersion
         )

      install(FILES 
         "${CMAKE_CURRENT_BINARY_DIR}/config/ireclibConfig.cmake" 
         "${CMAKE_CURRENT_BINARY_DIR}/config/ireclibConfigVersion.cmake" 
         DESTINATION ${ConfigPackageLocation})


      configure_file("cmake_utils/ireclib.pc.in" "ireclib-1.pc" @ONLY)
      install(FILES "${CMAKE_CURRENT_BINARY_DIR}/ireclib-1.pc"
         DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig")

      include(CPack)

   endif()

endif()

if (MSVC)
   math(EXPR numbits ${CMAKE_SIZEOF_VOID_P}*8)
   set_target_properties(ireclib PROPERTIES DEBUG_POSTFIX "${VERSION}_debug_${numbits}bit_msvc${MSVC_VERSION}")
   set_target_properties(ireclib PROPERTIES RELEASE_POSTFIX "${VERSION}_release_${numbits}bit_msvc${MSVC_VERSION}")
   set_target_properties(ireclib PROPERTIES MINSIZEREL_POSTFIX "${VERSION}_minsizerel_${numbits}bit_msvc${MSVC_VERSION}")
   set_target_properties(ireclib PROPERTIES RELWITHDEBINFO_POSTFIX "${VERSION}_relwithdebinfo_${numbits}bit_msvc${MSVC_VERSION}")
endif()

if (COMMAND pybind11_add_module)
   set_target_properties(ireclib PROPERTIES CXX_VISIBILITY_PRESET "hidden")
   set_target_properties(ireclib PROPERTIES CUDA_VISIBILITY_PRESET "hidden")
endif()

if (WIN32 AND mkl_iomp_dll)
   if (CMAKE_LIBRARY_OUTPUT_DIRECTORY)
      add_custom_command(TARGET ireclib POST_BUILD
         COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/"
         COMMAND ${CMAKE_COMMAND} -E copy "${mkl_iomp_dll}" "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/"
         )
   else()
      add_custom_command(TARGET ireclib POST_BUILD
         COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/$<CONFIG>/"
         COMMAND ${CMAKE_COMMAND} -E copy "${mkl_iomp_dll}" "${CMAKE_BINARY_DIR}/$<CONFIG>/"
         )
   endif()
endif()

add_library(ireclib::ireclib ALIAS ireclib)
