#include "./include/gui.h"
#include <iostream>
#define HALF_WIDTH (WINDOW_WIDTH / 2.0)
#define HALF_HEIGHT (WINDOW_HEIGHT / 2.0)

double zoom_magn = 1.0;
double cursor_x = 0.0;
double cursor_y = 0.0;
double plot_x = 0.0;
double plot_y = 0.0;

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1.0, 1.0);
}

void drawPoint(double x, double y, Color color)
{
    glColor3d(color.r, color.g, color.b);
    glPointSize(1);
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
}

void drawAxis()
{
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2d(0, -HALF_HEIGHT);
    glVertex2d(0, HALF_HEIGHT);
    glEnd();

    glBegin(GL_LINES);
    glVertex2d(-HALF_WIDTH, 0);
    glVertex2d(HALF_WIDTH, 0);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (double y = -HALF_HEIGHT; y < HALF_HEIGHT; y++)
    {
        for (double x = -HALF_WIDTH; x < HALF_WIDTH; x++)
        {
            Complex c(x / HALF_WIDTH, y / HALF_HEIGHT);
            c = c + Complex(cursor_x * zoom_magn / HALF_WIDTH, cursor_y * zoom_magn / HALF_HEIGHT);
            c = c * (1 / zoom_magn);

            int calculate_count = isInsideMandelbrot(c);
            Color color;
            color.r = static_cast<double>(static_cast<double>(calculate_count) / static_cast<double>(CALCULATE_COUNT_MAX));
            color.g = static_cast<double>(static_cast<double>(calculate_count) / static_cast<double>(CALCULATE_COUNT_MAX));
            color.b = static_cast<double>(static_cast<double>(calculate_count) / static_cast<double>(CALCULATE_COUNT_MAX));
            drawPoint(x, y, color);
        }
    }
    drawAxis();
    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if ((button == 3) || (button == 4))
    {
        if (state == GLUT_UP)
            return;
        std::cout << "scroll:" << ((button == 3) ? "UP" : "DOWN") << std::endl;
        std::cout << "cursor_x: " << cursor_x << ","
                  << "cursor_y: " << cursor_y << std::endl;
        std::cout << "HALF_WIDTH: " << HALF_WIDTH << ","
                  << "HALF_HEIGHT: " << HALF_HEIGHT << std::endl;
        if (button == 3)
        {
            zoom_magn = zoom_magn * 1.1;
            std::cout << "zoom_magn: " << zoom_magn << std::endl;
        }
        else
        {
            zoom_magn = zoom_magn * 0.9;
            std::cout << "zoom_magn: " << zoom_magn << std::endl;
        }
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        cursor_x = cursor_x + (x - HALF_WIDTH) / zoom_magn;
        cursor_y = cursor_y - (y - HALF_HEIGHT) / zoom_magn;
        std::cout << cursor_x << "," << cursor_y << std::endl;
    }

    glutPostRedisplay();
}

