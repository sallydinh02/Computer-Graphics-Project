#include "Parabola.h"
typedef std::chrono::milliseconds ms;
using namespace std;

Parabola::Parabola()
{
    this->xc = 0;
    this->yc = 0;
    this->p = 100;
}

Parabola::Parabola(float param, float xc, float yc, float p) :Shape(param)
{
    //Shape(param);
    this->xc = xc;
    this->yc = yc;
    this->p = p;
}

void Parabola::putPixel(float x, float y)
{
    /*glColor3f(0.0, 0.0, 1.0);*/
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void Parabola::MidPoint(float xc, float yc, float p)
{
    /*float x = 0;
    float y = 0;
    float x2 = 200;
    float y2 = 800;
    float p1 = 1 - 2 * p;
    while (x < 2 / p)
    {
        putPixel(x+xc, y+yc-p);
        putPixel(xc-x, y + yc - p);
        if (p1 < 0)
        {
            x++;
            p1 += 1 + 2 * x;
        }
        else
        {
            y++;
            x++;
            p1 += 1 + 2 * x - 4 * p;
        }
    }

    float p2 = (x + 0.5) * (x + 0.5) - 4 * p * (y + 1);
    while (x < x2)
    {
        putPixel(x + xc, y + yc - p);
        putPixel(xc - x, y + yc - p);
        if (p2 > 0)
        {
            y++;
            x++;
            p2 += 2 * x - 4 * p;
        }
        else
        {
            y++;
            p2 -= 4 * p;
        }
    }
    glFlush();*/

    float a = 4 * p;
    float p1 = 0.25 - 4 * p;
    int x = 0, y = 0;
    float minX = -200;
    float maxX = 200;
    float maxY = 800;
    auto start1 = high_resolution_clock::now();
    while (2 * x <= a)
    {
        putPixel(x + xc, y + yc - p);
        putPixel(xc - x, y + yc - p);
        if (p1 < 0)
            p1 += (float)x * 2.0 + 2.0;
        else
        {
            p1 += (float)x * 2.0 + 2.0 - 4.0 * p;
            y++;
        }
        x++;
    }

    if ((xc - x<minX && xc + x>maxX) || y > maxY) return;

    float p2 = (float)y - ((float)x + 0.5) * ((float)x + 0.5) / a;
    while ((minX<= xc - x || x + xc <= maxX) && y <= maxY)
    {
        putPixel(x + xc, y + yc);
        putPixel(xc - x, y + yc);
        if (p2 < 0)
        {
            p2 += 1;
        }
        else
        {
            p2 += 1 - 2.0 * (float)x / a;
            x++;
        }
        y++;
    }
    glFlush();
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<ms>(stop1 - start1);
    cout << "Time to draw parabola using Midpoint: " << duration1.count() << " miliseconds" << endl;
    //drawParabolaOpenGL(xc, yc, p);
}

void Parabola::drawParabolaOpenGL(float xc, float yc, float p)
{
    float x, y, minX, maxX, a;
    minX = -200;
    maxX = 200;
    glClear(GL_COLOR_BUFFER_BIT);
    auto start2 = high_resolution_clock::now();
    glBegin(GL_LINE_STRIP);
    for (x = minX; x <= maxX; x = x + 0.05) 
    {
        /* p: focal length
         y=a*x*x
         p=1/(4*a) => a=1/(4*p)*/
        a = 1 / (4 * p);
        //y=a*(x-xvertex)(x-xvertex)+yvertex
        //xfocal=xvertex
        //yfocal=yvertex+p
        y = a*(x-xc) * (x-xc) + yc-p;
        //cout << x + xc << " " << y + yc << endl;
        //cout << x << " " << y << endl;
        glVertex2f(x,y);
    }
    glEnd();
    glFlush();
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<ms>(stop2 - start2);
    cout << "Time to draw parabola OpenGL: " << duration2.count() << " miliseconds" << endl;
}

void Parabola::draw()
{
    cout << "Param: " << this->getParam() << endl;
    drawParabolaOpenGL(xc, yc, p);
    //MidPoint(this->xc, this->yc, this->p);
}