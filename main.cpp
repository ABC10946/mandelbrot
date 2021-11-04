// Copyright [2021] <abc10946>
#include <iostream>
#include "./include/mandelbrot.h"


int main(int argc, char *argv[]) {
    for (double y=-1; y < 1; y+=0.01) {
        for (double x=-4; x < 2; x+=0.01) {
            Complex c(x, y);
            int calculate_count = isInsideMandelbrot(c);
            if (calculate_count == CALCULATE_COUNT_MAX) {
                std::cout << "X";
            } else {
                int color_code = (int)(((float)calculate_count)/((float)CALCULATE_COUNT_MAX) * 255);
                std::cout << "\x1b[38;2;" << color_code << ";" << color_code << ";" << color_code << "mX\x1b[0m";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
