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

void Ellipse::drawEllipseOpenGL(int xc, int yc, int a, int b)
{
	int numSegment = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat pi = 3.1415926f;
	auto start2 = high_resolution_clock::now();
	glColor3f(0.0, 0.0, 0.0);
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
	drawEllipseOpenGL(xc, yc, a, b);
	//MidPoint(this->xc, this->yc, this->a, this->b);
}