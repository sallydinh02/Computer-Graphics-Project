#include "RectangleSquare.h"

RectangleSquare::RectangleSquare()
{
	this->xa = 0;
	this->ya = 0;
	this->xb = 0;
	this->yb = 0;
	this->xc = 0;
	this->yc = 0;
	this->xd = 0;
	this->yd = 0;
	this->xmid = 0;
	this->ymid = 0;
}

RectangleSquare::RectangleSquare(int numVertice, float xa, float ya, float xb, float yb):Shape(numVertice)
{
	this->xa = xa;
	this->ya = ya;
	this->xb = xb;
	this->yb = ya;
	this->xc = xb;
	this->yc = yb;
	this->xd = xa;
	this->yd = yb;
	/*float tmp[4][2] = {
		{this->xa, this->ya},
		{this->xb, this->yb},
		{this->xc, this->yc},
		{this->xd, this->yd}
	};
	for (int i = 0; i < numVertice; i++)
	{
		for (int j = 0; j < 2; j++)
			p[i][j] = tmp[i][j];
	}*/
	p.push_back({ this->xa, this->ya });
	p.push_back({ this->xb, this->yb });
	p.push_back({ this->xc, this->yc });
	p.push_back({ this->xd, this->yd });
	this->xmid = xa + (xb - xa) / 2;
	this->ymid = ya + (yb - ya) / 2; 
	cout << "Old mid: " << this->xmid << " " << this->ymid << endl;
}

void RectangleSquare::setMid(float x, float y)
{
	/*float mid[2] = { this->xmid, this->ymid };
	for (int i = 0; i < 2; i++)
		mid[i] += tr[i];*/
	this->xmid += x;
	this->ymid += y;
	//cout << "New mid: " << this->xmid << " " << this->ymid << endl;
}

float RectangleSquare::getXMid()
{
	return xmid;
}

float RectangleSquare::getYMid()
{
	return ymid;
}

void RectangleSquare::draw()
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < this->getNumVertice(); i++)
	{
		glVertex2f(p[i][0], p[i][1]);
	}
	glEnd();
	glFlush();
}