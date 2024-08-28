#include "Line.h"
typedef std::chrono::milliseconds ms;
using namespace std;

Line::Line()
{
    this->x1 = 0;
    this->y1 = 0;
    this->x2 = 100;
    this->y2 = 100;
}

Line::Line(float param, float x1, float y1, float x2, float y2) :Shape(param)
{
    //Shape(param);
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
}

void Line::drawLineOpenGL(int x1, int y1, int x2, int y2)
{
    auto start2 = high_resolution_clock::now();
    //glLineWidth(2.0);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
    glFlush();
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<ms>(stop2 - start2);
    cout << "Time to draw line OpenGL: " << duration2.count() << " miliseconds" << endl;
}

void Line::draw()
{
    /*cout << "Param: " << this->getParam() << endl;*/
    drawLineOpenGL(x1, y1, x2, y2);
    /*if (this->getParam() == 0) DDA(this->x1, this->y1, this->x2, this->y2);
    else if (this->getParam() == 1) Bresenham(this->x1, this->y1, this->x2, this->y2);*/
}