#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
const int Width = 200;
const int Height = 200;
struct Point2d {
    double x, y;
};
/*顶点需按照顺时针或者逆时针排序，不能乱序*/
bool isPointInsidePoly(const Point2d& P,const vector<Point2d>& polyVertices)
{
    std::size_t vertCount = polyVertices.size();
    if (vertCount < 2)
        return false;
    bool inside = false;
    for (unsigned i = 1; i <= vertCount; ++i)
    {
        const Point2d& A = polyVertices[i - 1];
        const Point2d& B = polyVertices[i%vertCount];
        if ((B.y <= P.y && P.y < A.y) || (A.y <= P.y && P.y < B.y))
        {
            double t = (P.x - B.x)*(A.y - B.y) - (A.x - B.x)*(P.y - B.y);
            if (A.y < B.y)
                t = -t;
            if (t < 0)
                inside = !inside;
        }
    }
    return inside;
}
vector<Point2d> point;
void drawPoints(double x, double y)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex2f(x, y);
    glVertex2f(x, y+0.3);
    glVertex2f(x+0.3, y+0.3);
    glVertex2f(x+0.3, y);

    glEnd();

}
void paintpin()
{
    for (int i = -10; i <= 10; i++) {
        if (i % 2==0) {
            for (int j = -10; j <= 10; j++) {
                if (isPointInsidePoly({i * 1.0, j * 1.0}, point)) drawPoints(i, j);
            }
        } else {
            for (double j = -10.5; j <= 10.5; j++) {
                if (isPointInsidePoly({i * 1.0, j * 1.0}, point)) drawPoints(i, j);
            }
        }
    }
}
void paintjing()
{
    for (double i = -10; i <= 10; i++) {
        for (double j = -10; j <= 10; j++) {
            if (isPointInsidePoly({i, j}, point)) drawPoints(i, j);
        }
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    point.push_back({3-5, 3-5});
    point.push_back({5-5, 10-5});
    point.push_back({10-5, 12-5});
    point.push_back({15-5, 10-5});
    point.push_back({15-5, 5-5});
    glVertex2f(3-5, 3-5);
    glVertex2f(5-5, 10-5);
    glVertex2f(10-5, 12-5);
    glVertex2f(15-5, 10-5);
    glVertex2f(15-5, 5-5);
    glEnd();
    paintpin();
    glFlush();
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 0.1, 100000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 25, 0, 0, -1, 0, 1, 0);
}
void init() {
    glClearColor(0.0, 0.3, 0.7, 0.0);
    glShadeModel(GL_SMOOTH);
}
int main(int argc,char** argv)
{
    glutInit(&argc, const_cast<char**>(argv));
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // 初始化窗口
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutMainLoop();
}