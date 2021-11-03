// Copyright [2021] <abc10946>
#ifndef LIB_COMPLEX_H_
#define LIB_COMPLEX_H_

#include <cmath>

class Complex {
 private:
    double re_;
    double im_;

 public:
    Complex(double re, double im);
    double get_re();
    double get_im();
    Complex operator+(const Complex &other);
    Complex operator-(const Complex &other);
    Complex operator*(const Complex &other);
    Complex operator*(const double &other);
    Complex operator/(const Complex &other);
};

double abs(Complex complex);

#endif  // LIB_COMPLEX_H_
