#ifndef LIB_GUI_H_
#define LIB_GUI_H
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "./mandelbrot.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

struct Color
{
    double r, g, b;
};

void drawPoint(float x, float y, int r, int g, int b);
void display(void);
void reshape(int w, int h);
void mouse(int button, int state, int x, int y);

#endif
