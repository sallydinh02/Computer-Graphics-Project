#include "Hyperboloid.h"
Hyperboloid::Hyperboloid() :Shape()
{
	for (int i = 0; i < this->numSurface; i++)
		textureList[i] = i;
	this->depth = 0;
	this->a = 0;
	this->b = 0;
	this->c = 0;
}

Hyperboloid::Hyperboloid(int numSurface, float a, float b, float c, float depth) :Shape(numSurface)
{
	this->depth = depth;
	this->a = a;
	this->b = b;
	this->c = c;
}

void Hyperboloid::loadTexture(const char* textureName[])
{
	// load an image file directly as a new opengl texture
	for (int i = 0; i < this->numSurface; i++)
	{
		// load an image file directly as a new opengl texture
		//cout << "textureName["<<i<<"]: " << textureName[i] << endl;
		textureList[i] = SOIL_load_OGL_texture
		(
			textureName[i+3],
			//textureName[2],
			//textureName[i],
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
		);
		glBindTexture(GL_TEXTURE_2D, textureList[i]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
}

void Hyperboloid::drawMesh()
{
	GLfloat pi = 3.1415926f;
	int maxU = 10;
	int maxV = 10;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureList[0]);
	//glRotatef(-90, 1, 0, 0);
	//glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for (float u = 0; u < maxU; u +=0.5)
	{
		for (float v = 0; v < maxV; v +=0.5)
		{
			float uNormal = ((depth * 2 * u / (maxU - 1)) - depth) / c;
			float vNormal = 2 * pi * v / maxV;
			float x = a * sqrt(1 + uNormal * uNormal) * cos(vNormal);
			float y = c * uNormal;
			float z = b * sqrt(1 + uNormal * uNormal) * sin(vNormal);
			glTexCoord3f(x, y, z);
			glVertex3f(x, y, z);
		}
	}
	glEnd();

	int numSegment = 100;
	float uNormalMax = ((depth * 2 * (maxU - 1 * 0.05) / (maxU - 1)) - depth) / c;
	float h = 1+2*0.05;
	// top circle
	glBindTexture(GL_TEXTURE_2D, textureList[1]);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= numSegment; i++)
	{
		//current angle
		glTexCoord2f(h + cos(i) * h, h + sin(i) * h);
		GLfloat theta = i * 2.0f * pi / numSegment;
		float x = depth * cos(theta);
		float z = depth * sin(theta);
		glVertex3f(x, h, z);
	}
	glEnd();

	// base circle
	glBindTexture(GL_TEXTURE_2D, textureList[1]);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= numSegment; i++)
	{
		//current angle
		glTexCoord2f(h + cos(i) * h, h + sin(i) * h);
		GLfloat theta = i * 2.0f * pi / numSegment;
		float x = depth * cos(theta);
		float z = depth * sin(theta);
		glVertex3f(x, -h, z);
	}
	glEnd();
}

void Hyperboloid::draw()
{
	GLfloat pi = 3.1415926f;
	int maxU = 10;
	int maxV = 10;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureList[0]);
	//glRotatef(-90, 1, 0, 0);
	//glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (float u = 0; u < maxU; u += 0.05)
	{
		for (float v = 0; v < maxV; v += 0.05)
		{
			float uNormal = ((depth * 2 * u / (maxU - 1)) - depth)/c;
			float vNormal = 2 * pi * v / maxV;
			float x = a*sqrt(1 + uNormal * uNormal) * cos(vNormal);
			float y = c*uNormal;
			float z = b * sqrt(1 + uNormal * uNormal) * sin(vNormal);
			glTexCoord3f(x, y, z);
			glVertex3f(x, y, z);
		}
	}
	glEnd();

	int numSegment = 100;
	float uNormalMax= ((depth * 2 * (maxU-1*0.05)/ (maxU - 1)) - depth) / c;
	float h = 1+2*0.05;

	// top circle
	glBindTexture(GL_TEXTURE_2D, textureList[1]);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= numSegment; i++)
	{
		//current angle
		glTexCoord2f(h + cos(i) * h, h + sin(i) * h);
		GLfloat theta = i * 2.0f * pi / numSegment;
		float x = depth * cos(theta);
		float z = depth * sin(theta);
		glVertex3f(x, h, z);
	}
	glEnd();

	// base circle
	glBindTexture(GL_TEXTURE_2D, textureList[1]);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= numSegment; i++)
	{
		//current angle
		glTexCoord2f(h + cos(i) * h, h + sin(i) * h);
		GLfloat theta = i * 2.0f * pi / numSegment;
		float x = depth * cos(theta);
		float z = depth * sin(theta);
		glVertex3f(x, -h, z);
	}
	glEnd();
}