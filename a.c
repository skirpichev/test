#include <complex.h>
#include <stdio.h>
#if !defined(CMPLX)
#define HAS_CMPLX 0
double complex
CMPLX(double real, double imag)
{
    double complex z;
    ((double *)(&z))[0] = real;
    ((double *)(&z))[1] = imag;
    return z;
}
#else
#define HAS_CMPLX 1
#endif
int main(void)
{
    printf("CMPLX: %d\n", HAS_CMPLX);
    double complex z, r;
    z = CMPLX(4, 0);
    r = csqrt(z);
    printf("%20s csqrt(%+lf%+lf) (%+lf%+lf)\n", "CMPLX(4, 0)", creal(z), cimag(z), creal(r), cimag(r));
    z = 4 + 0*_Complex_I;
    r = csqrt(z);
    printf("%20s csqrt(%+lf%+lf) (%+lf%+lf)\n", "4 + 0*_Complex_I", creal(z), cimag(z), creal(r), cimag(r));
    z = CMPLX(-1, +0.001);
    r = csqrt(z);
    printf("%20s csqrt(%+lf%+lf) (%+lf%+lf)\n", "CMPLX(-1, +0.001)", creal(z), cimag(z), creal(r), cimag(r));
    z = CMPLX(-1, -0.001);
    r = csqrt(z);
    printf("%20s csqrt(%+lf%+lf) (%+lf%+lf)\n", "CMPLX(-1, -0.001)", creal(z), cimag(z), creal(r), cimag(r));
    return 0;
}
