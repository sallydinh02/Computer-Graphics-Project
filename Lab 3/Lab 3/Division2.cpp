#include "Division2.h"

NewDivision::NewDivision()
{
	this->x = 0;
	this->y = 0;
	this->r = 50;
	this->w = 50;
	this->h = 50;
}

NewDivision::NewDivision(float param, float x, float y, float r, float w, float h) :Shape(param)
{
	this->x = x;
	this->y = y;
	this->r = r;
	this->w = w;
	this->h = h;
}

void NewDivision::drawNewDivisionOpenGL(int x, int y, int r, int w, int h)
{
	glColor3f(0.0, 0.0, 0.0);
	/*glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x + a, y);
	glVertex2i(x - a / 2, y + b);
	glVertex2i(x - a / 2 - a, y + b);
	glVertex2i(x, y);
	glEnd();*/
	Circle c(0, x, y, r);
	c.draw();
	int startXRec = x - w / 2;
	int startYRec = y + 3 * r;
	Rectangle rec(1, startXRec, startYRec, w, h);
	rec.draw();
	int startXCircle = x;
	int startYCircle = startYRec + h + 2*r;
	Circle c2(2, startXCircle, startYCircle, r);
	c2.draw();
	//glFlush();
}

void NewDivision::draw()
{
	drawNewDivisionOpenGL(this->x, this->y, this->r, this->w, this->h);
}