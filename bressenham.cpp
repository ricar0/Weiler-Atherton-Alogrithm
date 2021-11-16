#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;
void init() {
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,200.0,0.0,150.0);
}
void drawdelta(int x, int y, int len) {
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j <= i; j++) {
            glVertex2f(x + i*0.1, y + j*0.1);
        }
    }
    glVertex2d(x, y);
    glEnd();
}
void drawrect(int x, int y, int len) {
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            glVertex2f(x + i*0.1, y + j*0.1);
        }
    }
    glVertex2d(x, y);
    glEnd();
}
void DrawBresenhamline(int x0, int y0, int x1, int y1) {

    glClear(GL_COLOR_BUFFER_BIT);
    int dx = x1 - x0;
    int dy = y1 - y0;
    int ux = dx > 0 ? 1 : -1;
    int uy = dy > 0 ? 1 : -1;
    int dx2 = abs(dx << 1);
    int dy2 = abs(dy << 1);
    if (abs(dx) > abs(dy)) {
        int e = -dx;
        int x = x0;
        int y = y0;
        while (x != x1 + ux) {
            drawrect(x, y, 10);
            e = e + dy2;
            if (e > 0) {
                if (y != y1) {
                    y += uy;
                }
                e = e - dx2;
            }
            x += ux;
        }
    } else {
        int e = -dy;
        int x = x0;
        int y = y0;
        while (y != y1 + uy) {
            drawdelta(x, y, 10);
            e = e + dx2;
            if (e > 0) {
                if (x != x1) {
                    x += ux;
                }
                e = e - dy2;
            }
            y += uy;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    DrawBresenhamline(50, 50, 100, 100);
    glFlush();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(400,300);
    glutCreateWindow("Bresenham Draw Line");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}