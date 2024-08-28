#include "Sphere.h"
Sphere::Sphere() :Shape()
{
	this->textureList[0] = 0;
	this->r = 0;
}

Sphere::Sphere(int numSurface, float r) :Shape(numSurface)
{
	this->r = r;
}

void Sphere::loadTexture(const char* textureName[])
{
	// load an image file directly as a new opengl texture
	textureList[0] = SOIL_load_OGL_texture
	(
		textureName[rand() % 6],
		//textureName[0],
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	/*glBindTexture(GL_TEXTURE_2D, textureList[0]);*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Sphere::drawMesh()
{
	/*glutWireSphere(r, 8, 5);
	glFlush();*/
	// number of segments to create a circle (number of edges of polygon)
	int numSegment = 40; 
	GLfloat pi = 3.1415926f;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= numSegment; i++) 
	{
		//current angle
		GLfloat theta = i * 2.0f * pi / numSegment;
		float x = r * cos(theta);
		float y = r * sin(theta);
		glVertex3f(x, y, 0);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= numSegment; i++)
	{
		//current angle
		GLfloat theta = i * 2.0f * pi / numSegment;
		float x = r * cos(theta);
		float z = r*sin(theta);
		glVertex3f(x, 0, z);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= numSegment; i++)
	{
		//current angle
		GLfloat theta = i * 2.0f * pi / numSegment;
		float y = r * cos(theta);
		float z = r * sin(theta);
		glVertex3f(0, y, z);
	}
	glEnd();
	glFlush();
}

void Sphere::draw()
{
	GLUquadric* qobj = gluNewQuadric();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureList[0]);
	//gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricTexture(qobj, GL_TRUE);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	gluSphere(qobj, this->r, 40, 40);
	gluDeleteQuadric(qobj);
	glFlush();
}