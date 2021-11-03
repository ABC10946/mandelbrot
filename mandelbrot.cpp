// Copyright [2021] <abc10946>
#include "include/mandelbrot.h"

Complex mandelbrotRecurrentRelation(Complex z, Complex c) {
    return z * z + c;
}


bool isInsideMandelbrot(Complex c) {
    Complex z(0, 0);
    for (int i=0; i < 20; i++) {
        z = mandelbrotRecurrentRelation(z, c);
        if (abs(z) > 2.0) {
            return false;
        }
    }
    return true;
}
