cmake_minimum_required (VERSION 2.8)

project (demo2)

aux_source_directory (. SRCS)

add_executable (demo ${SRCS})
