#include "Triangle.h"

Triangle::Triangle()
{
	this->xa = 0;
	this->ya = 0;
	this->xb = 0;
	this->yb = 0;
	this->xc = 0;
	this->yc = 0;
	this->xmid = 0;
	this->ymid = 0;
}

Triangle::Triangle(int numVertice, float xa, float ya, float xb, float yb) 
	:Shape(numVertice)
{
	/*this->a = Point(a.getX()+((b.getX()-a.getX())/2), a.getY());
	this->b = b;
	this->c = Point(a.getX(), b.getY());
	p[0] = this->a;
	p[1] = this->b;
	p[2] = this->c;*/
	this->xa = xa+((xb-xa)/2);
	this->ya = ya;
	this->xb = xb;
	this->yb = yb;
	this->xc = xa;
	this->yc = yb;
	/*float tmp[3][2] = {
		{this->xa, this->ya},
		{this->xb, this->yb},
		{this->xc, this->yc}
	};
	for (int i = 0; i < numVertice; i++)
	{
		for (int j = 0; j < 2; j++)
			p[i][j] = tmp[i][j];
	}*/
	p.push_back({ this->xa, this->ya });
	p.push_back({ this->xb, this->yb });
	p.push_back({ this->xc, this->yc });
	this->xmid = this->xa;
	this->ymid = this->ya + (this->yb - this->ya) * 2 / 3;
	cout << "Old mid: " << this->xmid << " " << this->ymid << endl;
}

//void Triangle::drawTriangleOpenGL(Point a, Point b, Point c)
//{
//	glBegin(GL_LINE_LOOP);
//	glVertex2i(a.getX(), a.getY());
//	glVertex2i(b.getX(), b.getY());
//	glVertex2i(c.getX(), c.getY());
//	glEnd();
//	glFlush();
//}

void Triangle::setMid(float x, float y)
{
	this->xmid += x;
	this->ymid += y;
	//cout << "New mid: " << this->xmid << " " << this->ymid << endl;
	/*float mid[2] = { this->xmid, this->ymid };
	for (int i = 0; i < 2; i++)
		mid[i] += tr[i];
	cout << "New mid: " << mid[0] << " " << mid[1] << endl;*/
}

float Triangle::getXMid()
{
	return xmid;
}

float Triangle::getYMid()
{
	return ymid;
}

void Triangle::draw()
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < this->getNumVertice(); i++)
	{
		glVertex2f(p[i][0], p[i][1]);
	}
	glEnd();
	glFlush();
}