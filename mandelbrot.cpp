// Copyright [2021] <abc10946>
#include "include/mandelbrot.h"

Complex mandelbrotRecurrentRelation(Complex z, Complex c) {
    return z * z + c;
}


int isInsideMandelbrot(Complex c) {
    Complex z(0, 0);
    for (int i=0; i < CALCULATE_COUNT_MAX; i++) {
        z = mandelbrotRecurrentRelation(z, c);
        if (abs(z) > 2.0) {
            return i;
        }
    }
    return CALCULATE_COUNT_MAX;
}
