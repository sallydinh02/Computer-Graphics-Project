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

Line::Line(float param, float x1, float y1, float x2, float y2):Shape(param)
{
    //Shape(param);
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

void Line::DDA(float x1, float y1, float x2, float y2) {
    float step;
    float x, y, xInc, yInc, dx, dy;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy)) step = abs(dx);
    else step = abs(dy);
    xInc = (x2 - x1) / (step);
    yInc = (y2 - y1) / (step);
    x = x1;
    y = y1;
    auto start1 = high_resolution_clock::now();
    //glColor3f(1.0, 0.0, 0.0);
    //glPointSize(2.0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    for (int i = 0; i < step; i++) {
        x = x + xInc;
        y = y + yInc;
        //cout << round(x) << " " << round(y) << endl;
        //draw pixel
        glBegin(GL_POINTS);
        glVertex2i(round(x), round(y));
        glEnd();
    }
    glFlush();
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<ms>(stop1 - start1);
    cout << "Time to draw line using DDA: "<<duration1.count() << " miliseconds" << endl;
    //drawLineOpenGL(x1, y1, x2, y2);
}

void Line::drawLineOpenGL(int x1, int y1, int x2, int y2)
{
    auto start2 = high_resolution_clock::now();
    //glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
    glFlush();
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<ms>(stop2 - start2);
    cout << "Time to draw line OpenGL: " << duration2.count() << " miliseconds" << endl;
}

void Line::Bresenham(int x1, int y1, int x2, int y2)
{
    int dx, dy, p, xInc, yInc, pInc1, pInc2, x, y;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    xInc = 1;
    if (x2 < x1) xInc = -1;
    yInc = 1;
    if (y2 < y1) yInc = -1;
    x = x1;
    y = y1;

    //slope<1
    if (dy<dx)
    {
        auto start1 = high_resolution_clock::now();
        //glColor3f(1.0, 0.0, 0.0);
        //glPointSize(2.0);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        p = 2 * dy - dx;
        for (int i = 0; i < dx; i++)
        {
            if (p >= 0)
            {
                p += 2 * dy - 2 * dx;
                y += yInc;
            }
            else p += 2 * dy;
            x += xInc;
            //glColor3f(1.0, 0.0, 0.0);
            /*glPointSize(2.0);*/
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
        glFlush();
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<ms>(stop1 - start1);
        cout << "Time to draw line using Bresenham: " << duration1.count() << " miliseconds" << endl;
    }

    else
    {
        auto start1 = high_resolution_clock::now();
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        p = 2 * dx - dy;
        for (int i = 0; i < dy; i++)
        {
            if (p >= 0)
            {
                p += 2 * dx - 2 * dy;
                x += xInc;
            }
            else p += 2 * dx;
            y += yInc;
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
        glFlush();
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<ms>(stop1 - start1);
        cout << "Time to draw line using Bresenham: " << duration1.count() << " miliseconds" << endl;
    }
    //drawLineOpenGL(x1, y1, x2, y2);
}

void Line::draw()
{
    /*cout << "Param: " << this->getParam() << endl;*/
    //drawLineOpenGL(x1, y1, x2, y2);
    if (this->getParam() == 0) DDA(this->x1, this->y1, this->x2, this->y2);
    else if (this->getParam() == 1) Bresenham(this->x1, this->y1, this->x2, this->y2);
}