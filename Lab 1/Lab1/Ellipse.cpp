#include "Ellipse.h"
typedef std::chrono::milliseconds ms;

Ellipse::Ellipse()
{
	//Shape(-1);
	this->xc = 0;
	this->yc = 0;
	this->a = 100;
	this->b = 100;
}

Ellipse::Ellipse(float param, float xc, float yc, float a, float b) :Shape(param)
{
	/*Shape(param);*/
	this->xc = xc;
	this->yc = yc;
	this->a = a;
	this->b = b;
}

void Ellipse::putPixel(int x, int y)
{
	/*glColor3f(0.0, 0.0, 1.0);*/
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void Ellipse::MidPoint(int xc, int yc, int a, int b)
{
	int x = 0;
	int y = b;
	float p1 = b*b-a*a*b+0.25f*a*a;
	float dx = 2 * b * b * x;
	float dy = 2 * a * a * b;
	auto start1 = high_resolution_clock::now();
	while (dx < dy)
	{
		putPixel(xc + x, yc+y);
		putPixel(xc - x, yc + y);
		putPixel(xc + x, yc - y);
		putPixel(xc - x, yc - y);
		if (p1 < 0)
		{
			x++;
			dx = 2 * b * b * x;
			p1 += dx+b*b;
		}
		else
		{
			x++;
			y--;
			dx = dx + 2 * b * b;
			dy = dy - 2 * a * a;
			p1 = p1 + dx - dy + b*b;
		}
	}

	float p2 = (b * b * (x + 0.5f) * (x + 0.5f)) + (a * a * (y - 1) * (y - 1)) - (a * a * b * b);
	while (y > 0)
	{ 
		putPixel(xc + x, yc + y);
		putPixel(xc - x, yc + y);
		putPixel(xc + x, yc - y);
		putPixel(xc - x, yc - y); //glEnd();  
		if (p2 > 0)
		{
			y--;
			dy = dy-2*a*a;
			p2 = p2 - dy + a * a;
		}
		else {
			x++;
			y--;
			dy = dy - 2 * a * a;
			dx = dx + 2 * b * b;
			p2 = p2 + dx - dy + (a * a);
		}
	}
	glFlush();
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<ms>(stop1 - start1);
	cout << "Time to draw ellipse using Midpoint: " << duration1.count() << " miliseconds" << endl;

	//drawEllipseOpenGL(xc, yc, a, b);
}

void Ellipse::drawEllipseOpenGL(int xc, int yc, int a, int b)
{
	int numSegment = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat pi = 3.1415926f;
	auto start2 = high_resolution_clock::now();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= numSegment; i++) {
		//current angle
		GLfloat theta = i * 2.0f * pi / numSegment;
		int x = xc + (a * cos(theta));
		int y = yc + (b * sin(theta));
		glVertex2i(x, y);
	}
	glEnd();
	glFlush();
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<ms>(stop2 - start2);
	cout << "Time to draw ellipse OpenGL: " << duration2.count() << " miliseconds" << endl;

	//glFlush();
}

void Ellipse::draw()
{
	//MidPoint(this->xc, this->yc, this->r);
	cout << "Param: " << this->getParam() << endl;
	//drawEllipseOpenGL(xc, yc, a, b);
	MidPoint(this->xc, this->yc, this->a, this->b);
}