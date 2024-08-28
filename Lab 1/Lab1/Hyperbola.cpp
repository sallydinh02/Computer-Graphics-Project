#include "Hyperbola.h"
typedef std::chrono::milliseconds ms;
using namespace std;

Hyperbola::Hyperbola()
{
    this->xc = 0;
    this->yc = 0;
    this->major = 100;
    this->minor = 100;
}

Hyperbola::Hyperbola(float param, float xc, float yc, float major, float minor) :Shape(param)
{
    //Shape(param);
    this->xc = xc;
    this->yc = yc;
    this->major = major;
    this->minor = minor;
}

void Hyperbola::putPixel(float x, float y)
{
    /*glColor3f(0.0, 0.0, 1.0);*/
    glBegin(GL_POINTS);
    glVertex2f(xc + x, yc + y);
    glVertex2f(xc + x, yc - y);
    glVertex2f(xc - x, yc - y);
    glVertex2f(xc - x, yc + y);
    glEnd();
}

void Hyperbola::MidPoint(float xc, float yc, float major, float minor)
{
    /*glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(5.0);*/
    /*float a = major / 2.0;
    float b = minor / 2.0;
    float p1, dx, dy, x, y;
    p1 = b * b * (a + 0.5) * (a + 0.5) - (a * a) - (a * a * b * b);
    x = a;
    y = 0;
    dx = 2 * b * b * a;
    dy = 0;

    while (abs(dy) <= dx)
    {
        if (p1 >= 0)
            p1 = p1 - a * a * (2 * y + 3);
        else
        {
            p1 = p1 - a * a * (2 * y + 3) + b * b * (2 * x + 2);
            x++;
            dx = dx + 2 * b * b;
        }
        y++;
        dy = dy + 2 * a * a;
        putPixel(x + 100 + xc, 350 - y - yc);
        putPixel(x + 100 + xc, 350 + y - yc);
        putPixel(-x + 100 + xc, 350 - y - yc);
        
    }
    cout << "end loop 1" << endl;
    float p = b;
    x = p / 2;
    y = p;
    float p2 = -p;

    while (y < 3 * p)
    {
        x++;
        if (p2 >= 0)
            p2 = p2 - 2 * p;
        else
        {
            p2 = p2 + 2 * y + 2 - 2 * p;
            y++;
        }
        cout << x + 100 + xc << " " << 350 - y - yc << endl;
        cout << x + 100 + xc << " " << 350 + y + yc << endl;
        putPixel(x + 100 + xc, 350 - y - yc);
        putPixel(x + 100 + xc, 350 + y - yc);
    }*/

    float a = major / 2.0;
    float b = minor / 2.0;
    float x, y;
    x=a,y=0;
    float p1 = b*b*(2*a+1)*(a+1/2) - 2*a*a -2*a*a*b*b;
    auto start1 = high_resolution_clock::now();
    while(y<=b*b*x/(a*a))
    {
        putPixel(x,y);
        if(p1>0)
            p1-=2*a*a*(1+2*(y+1));
        else
        {
            p1+=b*b*(2+2*(2*x+1))-2*a*a*(1+2*(y+1)) ;
            x++;
        }
        y++;
    }
    int init = 170;
    while(init--)
    {
       if(p1>0)
       {
            p1+=2*b*b*(1+(2*x+1));
       }
       else
       {
            p1+=2*b*b*(1+(2*x+1)) -2*a*a*(1+2*y+1);
            y++;
       }
       x++;
       putPixel(x,y);
    }

    glFlush();
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<ms>(stop1 - start1);
    cout << "Time to draw hyperbola using Midpoint: " << duration1.count() << " miliseconds" << endl;
}

void Hyperbola::drawHyperbolaOpenGL(float xc, float yc, float major, float minor)
{
    float a = major / 2.0;
    float b = minor / 2.0;
    float minY = -100;
    float maxY = 400;
    auto start2 = high_resolution_clock::now();
    // draw half left of hyperbola 
    glBegin(GL_LINE_STRIP);
    for (float y = minY; y <= maxY; y += 0.05)
    {
        float x = xc - a * sqrt(1.0 + (y - yc) * (y - yc) / (b * b));
        glVertex2f(x, y);
    }
    glEnd();

    // draw half left of hyperbola 
    glBegin(GL_LINE_STRIP);
    for (float y = minY; y <= maxY; y += 0.05)
    {
        float x = xc + a * sqrt(1.0 + (y - yc) * (y - yc) / (b * b));
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<ms>(stop2 - start2);
    cout << "Time to draw hyperbola OpenGL: " << duration2.count() << " miliseconds" << endl;
}

void Hyperbola::draw()
{
    cout << "Param: " << this->getParam() << endl;
    //drawHyperbolaOpenGL(this->xc, this->yc, this->major, this->minor);
    MidPoint(this->xc, this->yc, this->major, this->minor);
}