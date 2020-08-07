cmake_minimum_required (VERSION 2.8)

project (demo3)

aux_source_directory (. SRCS)

add_subdirectory (math)

add_executable (demo ${SRCS})

target_link_libraries (demo MathFunctions)
