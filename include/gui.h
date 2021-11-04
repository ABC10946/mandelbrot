#ifndef LIB_GUI_H_
#define LIB_GUI_H
#include <GL/glut.h>
#include "./mandelbrot.h"
#define WINDOW_WIDTH 750
#define WINDOW_HEIGHT 500

struct Color {
    double r, g, b;
};

void drawPoint(float x, float y, int r, int g, int b);
void display(void);
void reshape(int w, int h);

#endif
