#include <stdio.h>
#include <stdlib.h>
#include "config.h"

#ifdef POW_HAVE
# include <math.h>
#else
# include "math/MathFunctions.h"
#endif

int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    double base = atof(argv[1]);
    int exponent = atoi(argv[2]);
    
#ifdef POW_HAVE
    printf("Using libm.so\n");
    double result = pow(base, exponent);
#else
    printf("Using libMathFunctions.a\n");
    double result = power(base, exponent);
#endif

    printf("%g ^ %d is %g\n", base, exponent, result);
    return 0;
}
