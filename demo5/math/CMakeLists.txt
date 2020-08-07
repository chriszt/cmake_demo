aux_source_directory (. MYMATH_SRCS)

add_library (MathFunctions ${MYMATH_SRCS})

install (TARGETS MathFunctions DESTINATION lib)
install (FILES MathFunctions.h DESTINATION include)
