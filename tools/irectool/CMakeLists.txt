
cmake_minimum_required(VERSION 3.10.0)

set (target_name imglab)

PROJECT(${target_name})
add_subdirectory(../../ireclib ireclib_build)

add_executable(${target_name} 
   src/main.cpp
   src/metadata_editor.h
   src/metadata_editor.cpp
   src/convert_pascal_xml.h
   src/convert_pascal_xml.cpp
   src/convert_pascal_v1.h
   src/convert_pascal_v1.cpp
   src/convert_idl.h
   src/convert_idl.cpp
   src/common.h
   src/common.cpp
   src/cluster.cpp
   src/flip_dataset.cpp
)


target_link_libraries(${target_name} ireclib::ireclib )


install(TARGETS ${target_name}
	RUNTIME DESTINATION bin
	)
install(PROGRAMS convert_imglab_paths_to_relative copy_imglab_dataset DESTINATION bin )

