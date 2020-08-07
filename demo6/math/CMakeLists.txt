aux_source_directory(. MATH_SRCS)

add_library(MathFunctions ${MATH_SRCS})

install (TARGETS MathFunctions DESTINATION lib)
install (FILES MathFunctions.h DESTINATION include)