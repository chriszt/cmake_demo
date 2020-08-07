cmake_minimum_required (VERSION 3.0)

project (demo5)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

set (CMAKE_BUILD_TYPE "Debug")
set (CMAKE_C_FLAGS_DEBUG "${CFLAGS} -Wall -g")

aux_source_directory (. MAIN_SRCS)

option (USE_MYMATH "use libMathFunctions.a ?" ON)
if (USE_MYMATH)
    message (STATUS "ENABLE libMathFunctions.a")
    include_directories (${PROJECT_SOURCE_DIR}/math)
    add_subdirectory (math)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
else ()
    message (STATUS "ENABLE libm.a")
    set (EXTRA_LIBS ${EXTRA_LIBS} m)
endif ()
configure_file (${PROJECT_SOURCE_DIR}/config.h.in ${PROJECT_SOURCE_DIR}/config.h)

add_executable (demo ${MAIN_SRCS})
target_link_libraries (demo ${EXTRA_LIBS})

install (TARGETS demo DESTINATION bin)
install (FILES config.h DESTINATION include)

enable_testing ()

add_test (test_run demo 2 2)

add_test (test_usage demo)
set_tests_properties (test_usage
    PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

add_test (test_5_2 demo 5 2)
set_tests_properties (test_5_2
    PROPERTIES PASS_REGULAR_EXPRESSION "is 25")

add_test (test_10_5 demo 10 5)
set_tests_properties (test_10_5
    PROPERTIES PASS_REGULAR_EXPRESSION "is 100000")

add_test (test_2_10 demo 2 10)
set_tests_properties (test_2_10
    PROPERTIES PASS_REGULAR_EXPRESSION "is 1024")

macro (do_test arg1 arg2 result)
    add_test (testx_${arg1}_${arg2} demo ${arg1} ${arg2})
    set_tests_properties (test_${arg1}_${arg2}
        PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro ()

do_test(5 2 "is 25")
do_test(10 5 "is 100000")
do_test(2 10 "is 1024")

