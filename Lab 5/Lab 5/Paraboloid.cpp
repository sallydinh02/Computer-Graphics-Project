#include "Paraboloid.h"
Paraboloid::Paraboloid() :Shape()
{
	this->textureList[0] = 0;
	this->r = 0;
}

Paraboloid::Paraboloid(int numSurface, float r) :Shape(numSurface)
{
	this->r = r;
}

void Paraboloid::loadTexture(const char* textureName[])
{
	// load an image file directly as a new opengl texture
	textureList[0] = SOIL_load_OGL_texture
	(
		textureName[3],
		//textureName[0],
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	/*glBindTexture(GL_TEXTURE_2D, textureList[0]);*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Paraboloid::drawMesh()
{
	GLfloat pi = 3.1415926f;
	float numSegments = 100;
	//glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for (float u = 0; u <= r; u += 0.01)
	{
		for (float v = 0; v <= numSegments; v++)
		{
			float x = u * sin(v);
			float y = -1 * (u * u);
			float z = u * cos(v);
			glVertex3f(x, y, z);
		}
	}
	glEnd();
}

void Paraboloid::draw()
{
	GLfloat pi = 3.1415926f;
	float numSegments = 100;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureList[0]);
	//glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (float u = 0; u <= r; u+=0.01)
	{
		for (float v = 0; v <= numSegments; v++)
		{
			float x = u * sin(v);
			float y = - 1 * (u * u);
			float z = u * cos(v);
			glTexCoord2f(u/(2*pi), v/(2*pi));
			glVertex3f(x, y, z);
		}
	}
	glEnd();
}