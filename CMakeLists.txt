cmake_minimum_required(VERSION 3.10.0)
project(ireclib_project)

get_directory_property(has_parent PARENT_DIRECTORY)
if(NOT has_parent)
   set(IRECLIB_IN_PROJECT_BUILD false)
endif()
add_subdirectory(ireclib)
