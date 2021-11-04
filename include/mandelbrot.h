// Copyright [2021] <abc10946>
#ifndef LIB_MANDELBROT_H_
#define LIB_MANDELBROT_H_
#include "./complex.h"
#define CALCULATE_COUNT_MAX 20

Complex mandelbrotRecurrentRelation(Complex z, Complex c);
int isInsideMandelbrot(Complex c);

#endif  // LIB_MANDELBROT_H_
