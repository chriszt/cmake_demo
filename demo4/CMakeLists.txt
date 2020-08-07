cmake_minimum_required (VERSION 3.0)

project (demo4)

aux_source_directory (. SRCS)

option (USE_MYMATH "Use my math library" ON)

if (USE_MYMATH)
    message ("ENABLE USE_MYMATH Macro")
    # include_directories (${PROJECT_SOURCE_DIR}/math)
    add_subdirectory (math)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
else ()
    set (EXTRA_LIBS ${EXTRA_LIBS} m)
endif ()

configure_file (
    config.h.in 
    ../config.h
    )

add_executable (demo ${SRCS})
target_link_libraries (demo ${EXTRA_LIBS})

