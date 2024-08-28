#include "Multiplication.h"

Multiplication::Multiplication()
{
	this->x = 0;
	this->y = 0;
	this->a = 50;
	this->b = 50;
}

Multiplication::Multiplication(float param, float x, float y, float a, float b) :Shape(param)
{
	this->x = x;
	this->y = y;
	this->a = a;
	this->b = b;
}

void Multiplication::drawMultiplicationOpenGL(int x, int y, int a, int b)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x+a, y);
	glVertex2i(x+a+b, y+a+b);
	glVertex2i(x+a+2*b, y);
	glVertex2i(x+2*a+2*b, y);
	glVertex2i(x + 2 * a + b, y + a + b+a/2);
	glVertex2i(x + 2 * a + 2 * b, y + 2 * a + 2 * b+a/2);
	glVertex2i(x + a + 2*b, y + 2 * a + 2 * b+a/2);
	glVertex2i(x + a + b, y + 2 * a + b);
	glVertex2i(x + a, y + 2*a + 2*b+a/2);
	glVertex2i(x, y + 2*a + 2*b+a/2);
	glVertex2i(x + b, y + a + b + a / 2);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void Multiplication::draw()
{
	drawMultiplicationOpenGL(this->x, this->y, this->a, this->b);
}