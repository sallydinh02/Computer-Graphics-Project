#include "Circle.h"
typedef std::chrono::milliseconds ms;

Circle::Circle()
{
	//Shape(-1);
	this->xc = 0;
	this->yc = 0;
	this->r = 100;
}

Circle::Circle(float param, float xc, float yc, float r) :Shape(param)
{
	/*Shape(param);*/
	this->xc = xc;
	this->yc = yc;
	this->r = r;
}

void Circle::putPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(this->xc+x, this->yc+y);
	glEnd();
}

void Circle::MidPoint(int xc, int yc, int r)
{
	int x = 0;
	int y = r;
	float p = 5 / 4 - r;
	auto start1 = high_resolution_clock::now();
	while (x < y)
	{
		if (p < 0)
		{
			x++;
			p += 2 * x + 1;
		}
		else
		{
			x++;
			y--;
			p += 2 * x + 1 - 2 *y;
		}
		putPixel(x, y);
		putPixel(x, -y);
		putPixel(-x, y);
		putPixel(-x, -y);
		putPixel(y, x);
		putPixel(y, -x);
		putPixel(-y, x);
		putPixel(-y, -x);
	}
	glFlush();
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<ms>(stop1 - start1);
	cout << "Time to draw circle using Midpoint: " << duration1.count() << " miliseconds" << endl;

	//drawCircleOpenGL(xc, yc, r);
}

void Circle::drawCircleOpenGL(int xc, int yc, int r)
{	
	int numSegment = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat pi = 3.1415926f;
	auto start2 = high_resolution_clock::now();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= numSegment; i++) {
		//current angle
		GLfloat theta = i * 2.0f * pi / numSegment;
		int x = xc + (r * cos(theta));
		int y = yc + (r * sin(theta));
		glVertex2i(x, y);
	}
	glEnd();
	glFlush();
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<ms>(stop2 - start2);
	cout << "Time to draw circle OpenGL: " << duration2.count() << " miliseconds" << endl;

	//glFlush();
}

void Circle::draw()
{
	//MidPoint(this->xc, this->yc, this->r);
	cout <<"Param: " << this->getParam() << endl;
	//drawCircleOpenGL(this->xc, this->yc, this->r);
	MidPoint(this->xc, this->yc, this->r);
}