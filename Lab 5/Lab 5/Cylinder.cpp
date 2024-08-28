#include "Cylinder.h"
Cylinder::Cylinder() :Shape()
{
	for (int i = 0; i < this->numSurface; i++)
		textureList[i] = i;
	this->r = 0;
	this->h = 0;
}

Cylinder::Cylinder(int numSurface, float r, float h) :Shape(numSurface)
{
	this->r = r;
	this->h = h;
}

void Cylinder::loadTexture(const char* textureName[])
{
	for (int i = 0; i < this->numSurface; i++)
	{
		// load an image file directly as a new opengl texture
		//cout << "textureName["<<i<<"]: " << textureName[i] << endl;
		textureList[i] = SOIL_load_OGL_texture
		(
			textureName[rand() % 6],
			//textureName[2],
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
		);
		glBindTexture(GL_TEXTURE_2D, textureList[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
}

void Cylinder::drawMesh()
{
	// rectangle in xy
	glBegin(GL_LINE_LOOP);
	glVertex3f(r, h / 2, 0);
	glVertex3f(r, -h / 2, 0);
	glVertex3f(-r, -h / 2, 0);
	glVertex3f(-r, h / 2, 0);
	glEnd();

	// rectangle in yz
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, h/2, r);
	glVertex3f(0, -h / 2, r);
	glVertex3f(0, -h / 2, -r);
	glVertex3f(0, h / 2, -r);
	glEnd();

	int numSegment = 30;
	GLfloat pi = 3.1415926f;
	// top 
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= numSegment; i++)
	{
		//current angle
		GLfloat theta = i * 2.0f * pi / numSegment;
		float x = r * cos(theta);
		float z = r * sin(theta);
		glVertex3f(x, h / 2, z);
	}
	glEnd();

	// base
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= numSegment; i++)
	{
		//current angle
		GLfloat theta = i * 2.0f * pi / numSegment;
		float x = r * cos(theta);
		float z = r * sin(theta);
		glVertex3f(x, -h / 2, z);
	}
	glEnd();
}

void Cylinder::draw()
{
	// code here
	int numSegment = 100;
	GLfloat pi = 3.1415926f;
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, textureList[0]);
	//// surrounding surface
	//glBegin(GL_QUAD_STRIP);
	//for (float i = 0; i <= numSegment; i ++)
	//{
	//	//glColor3f(1.0, 1.0, 1.0);
	//	glTexCoord2f(i / numSegment, h/2.0f);
	//	glVertex3f(r*cos(i), h/2.0f, r*sin(i));
	//	glTexCoord2f(i / numSegment, -h/2.0f);
	//	glVertex3f(r*cos(i), -h/2.0f, r*sin(i));
	//}
	//glEnd();

	// top (solid circle)
	glBindTexture(GL_TEXTURE_2D, textureList[1]);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= numSegment; i++)
	{
		//current angle
		glTexCoord2f(h / 2 + cos(i) * h / 2, h / 2 + sin(i) * h / 2);
		GLfloat theta = i * 2.0f * pi / numSegment;
		float x = r*cos(theta);
		float z = r*sin(theta);
		glVertex3f(x, h/2, z);
	}
	glEnd();

	// base (solid circle)
	glBindTexture(GL_TEXTURE_2D, textureList[2]);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= numSegment; i++)
	{
		//current angle
		glTexCoord2f(h / 2 + cos(i) * h / 2, h / 2 + sin(i) * h / 2);
		GLfloat theta = i * 2.0f * pi / numSegment;
		float x = r * cos(theta);
		float z = r * sin(theta);
		glVertex3f(x, -h / 2, z);
	}
	glEnd();

	// test
	/*float x, y;
	float height = 1;
	GLfloat angle_stepsize = 0.1;
	float alpha = 0;
	GLfloat PI = 3.1415926f;
	glRotatef(-90, 1, 0, 0);
	glBindTexture(GL_TEXTURE_2D, textureList[0]);
	glBegin(GL_QUAD_STRIP);
	alpha = 0.0;
	while (alpha < 2 * PI) {
		x = r * cos(alpha);
		y = r * sin(alpha);
		glTexCoord2f(x, y); glVertex3f(x, y, height);
		glTexCoord2f(x, y); glVertex3f(x, y, -1 * height);
		alpha = alpha + angle_stepsize;
	}
	glTexCoord2f(r, 0.0); glVertex3f(r, 0.0, height);
	glTexCoord2f(r, 0.0); glVertex3f(r, 0.0, -1 * height);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textureList[1]);
	glBegin(GL_POLYGON);
	alpha = 0.0;
	while (alpha < 2 * PI) {
		x = r * cos(alpha);
		y = r * sin(alpha);
		glTexCoord2f(x, y); glVertex3f(x, y, height);
		alpha = alpha + angle_stepsize;
	}
	glTexCoord2f(r, 0.0); glVertex3f(r, 0.0, height);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textureList[2]);
	glBegin(GL_POLYGON);
	alpha = 0.0;
	while (alpha < 2 * PI) {
		x = r * cos(alpha);
		y = r * sin(alpha);
		glTexCoord2f(x, y); glVertex3f(x, y, -1 * height);
		alpha = alpha + angle_stepsize;
	}
	glTexCoord2f(r, 0.0); glVertex3f(r, 0.0, -1 * height);
	glEnd();*/

	// gluCylinder to generate surrounding surface
	GLUquadric* qobj = gluNewQuadric();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureList[0]);
	gluQuadricTexture(qobj, GL_TRUE);
	glColor3f(1, 1, 1);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -h / 2.0f);
	gluCylinder(qobj, this->r, this->r, this->h, 40, 40);
	glFlush();
	gluDeleteQuadric(qobj);
}