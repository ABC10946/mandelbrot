#include "./include/gui.h"
#include <iostream>

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho(-500, 250, -250, 250, -1.0, 1.0);
}

void drawPoint(double x, double y, Color color) {
    glColor3d(color.r, color.g, color.b);
    glPointSize(1);
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    for (double y=-250; y < 250; y++) {
        for (double x=-500; x < 250; x++) {
            Complex c(x/250, y/250);
            int calculate_count = isInsideMandelbrot(c);
            Color color;
            color.r = static_cast<double>(static_cast<double>(calculate_count)/static_cast<double>(CALCULATE_COUNT_MAX));
            color.g = static_cast<double>(static_cast<double>(calculate_count)/static_cast<double>(CALCULATE_COUNT_MAX));
            color.b = static_cast<double>(static_cast<double>(calculate_count)/static_cast<double>(CALCULATE_COUNT_MAX));
            drawPoint(x, y, color);
        }
    }
    glFlush();
}
