// Copyright [2021] <abc10946>
#include <iostream>
#include "./include/mandelbrot.h"


int main(int argc, char *argv[]) {
    for (double y=-1; y < 1; y+=0.01) {
        for (double x=-4; x < 2; x+=0.01) {
            Complex c(x, y);
            if (isInsideMandelbrot(c)) {
                std::cout << "X";
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
