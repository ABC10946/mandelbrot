// Copyright [2021] <abc10946>
#ifndef LIB_MANDELBROT_H_
#define LIB_MANDELBROT_H_
#include "./complex.h"
extern double calculate_count_max;

Complex mandelbrotRecurrentRelation(Complex z, Complex c);
int isInsideMandelbrot(Complex c);

#endif // LIB_MANDELBROT_H_
