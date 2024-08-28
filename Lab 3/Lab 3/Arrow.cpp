#include "Arrow.h"
Arrow::Arrow()
{
	this->x = 0;
	this->y = 0;
	this->w = 5;
	this->h = 50;
	this->e = 20;
	this->ht = 10;
}

Arrow::Arrow(float param, float x, float y, float w, float h, float e, float ht) :Shape(param)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->e = e;
	this->ht = ht;
}

void Arrow::drawArrowOpenGL(int x, int y, int w, int h, int e, int ht)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x, y);
	glVertex2i(x, y + h); // |
	glVertex2i(x + w, y + h); // |__
	glVertex2i(x + w, y + h+h/2+e);
	glVertex2i(x + w + ht, y  + h / 2);
	glVertex2i(x + w, y - (h/2+e));
	glVertex2i(x + w, y);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void Arrow::draw()
{
	drawArrowOpenGL(this->x, this->y, this->w, this->h, this->e, this->ht);
}