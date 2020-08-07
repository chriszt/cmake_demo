cmake_minimum_required(VERSION 3.0)

project(demo6)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (CMAKE_BUILD_TYPE "Debug")
set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -g")

aux_source_directory(. MAIN_SRCS)

include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (pow POW_HAVE)

if (POW_HAVE)
    message (STATUS "Use libm.a library.")
    set (EXTRA_LIBS ${EXTRA_LIBS} m)
else ()
    message (STATUS "Use libMathFunctions.a library.")
    include_directories(${PROJECT_SOURCE_DIR}/math)
    add_subdirectory(math)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif ()

configure_file(
    ${PROJECT_SOURCE_DIR}/config.h.in
    ${PROJECT_SOURCE_DIR}/config.h
)

add_executable(demo ${MAIN_SRCS})
target_link_libraries(demo ${EXTRA_LIBS})

install (TARGETS demo DESTINATION bin)
install (FILES config.h DESTINATION include)

enable_testing()

add_test(test_run demo 2 3)

add_test(test_2_5 demo 2 5)
set_tests_properties(test_2_5
    PROPERTIES PASS_REGULAR_EXPRESSION "is 32")

macro(do_test arg1 arg2 result)
    add_test(test_${arg1}_${arg2} demo ${arg1} ${arg2})
    set_tests_properties(test_${arg1}_${arg2}
        PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro()

do_test(5 1 "is 5")
do_test(5 2 "is 25")
do_test(5 3 "is 125")
