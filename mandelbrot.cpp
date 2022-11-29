// Copyright [2021] <abc10946>
#include "include/mandelbrot.h"
double calculate_count_max = 20.0;

Complex mandelbrotRecurrentRelation(Complex z, Complex c)
{
    return z * z + c;
}

int isInsideMandelbrot(Complex c)
{
    Complex z(0, 0);
    for (int i = 0; i < calculate_count_max; i++)
    {
        z = mandelbrotRecurrentRelation(z, c);
        if (abs(z) > 2.0)
        {
            return i;
        }
    }
    return calculate_count_max;
}
