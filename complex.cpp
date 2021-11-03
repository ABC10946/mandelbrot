// Copyright [2021] <abc10946>
#include "include/complex.h"

Complex::Complex(double re, double im) {
    re_ = re;
    im_ = im;
}

double Complex::get_re() {
    return re_;
}

double Complex::get_im() {
    return im_;
}

Complex Complex::operator+(const Complex &other) {
    return Complex(re_+other.re_, im_+other.im_);
}

Complex Complex::operator-(const Complex &other) {
    return Complex(re_-other.re_, im_-other.im_);
}

Complex Complex::operator*(const Complex &other) {
    return Complex(re_ * other.re_ - im_ * other.im_, re_*other.im_ + im_*other.re_);
}

Complex Complex::operator*(const double &other) {
    return Complex(re_ * other, im_ * other);
}

Complex Complex::operator/(const Complex &other) {
    Complex numerator = Complex(re_, im_) * Complex(other.re_, -other.im_);
    return numerator * (1.0/(other.re_ * other.re_ + other.im_ * other.im_));
}

double abs(Complex complex) {
    return std::sqrt(complex.get_re() * complex.get_re() + complex.get_im() * complex.get_im());
}
