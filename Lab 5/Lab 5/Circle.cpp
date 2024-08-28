#include "Circle.h"
float h = 2;
Circle::Circle() :Shape()
{
	this->textureList[0] = 0;
	this->r = 0;
}

Circle::Circle(int numSurface, float r) :Shape(numSurface)
{
	this->r = r;
}

void Circle::loadTexture(const char* textureName[])
{
	// load an image file directly as a new opengl texture
	textureList[0] = SOIL_load_OGL_texture
	(
		textureName[4],
		//textureName[0],
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	/*glBindTexture(GL_TEXTURE_2D, textureList[0]);*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Circle::drawMesh()
{
	int numSegment = 14;
	GLfloat pi = 3.1415926f;
	// circle
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= numSegment; i++)
	{
		//current angle
		//glTexCoord2f(h / 2 + cos(i) * h / 2, h / 2 + sin(i) * h / 2);
		GLfloat theta = i * 2.0f * pi / numSegment;
		float x = r * cos(theta);
		float z = r * sin(theta);
		glVertex3f(x, -h / 2, z);
	}
	glEnd();

	// xy line
	glBegin(GL_LINE_LOOP);
	glVertex3f(r, -h / 2, 0);
	glVertex3f(-r, -h / 2, 0);
	glEnd();

	// yz line
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, -h / 2, r);
	glVertex3f(0, -h / 2, -r);
	glEnd();
}

void Circle::draw()
{
	int numSegment = 100;
	GLfloat pi = 3.1415926f;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureList[0]);
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
}