
cmake_minimum_required(VERSION 3.10.0)
project (myproject)
set(java_package_name net.ireclib)
set(source_files
   )

include(../cmake_utils/release_build_by_default)

include_directories(
   .
   )


set(install_target_output_folder .)



include(cmake_swig_jni)


