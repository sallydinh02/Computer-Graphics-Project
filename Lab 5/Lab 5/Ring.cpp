#include "Ring.h"
Ring::Ring() :Shape()
{
	textureList[0] = 0;
	this->r = 0;
	this->R = 0;
}

Ring::Ring(int numSurface, float r, float R) :Shape(numSurface)
{
	this->r = r;
	this->R = R;
}

void Ring::loadTexture(const char* textureName[])
{
	// load an image file directly as a new opengl texture
	textureList[0] = SOIL_load_OGL_texture
	(
		//textureName[rand() % 6],
		textureName[1],
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	/*glBindTexture(GL_TEXTURE_2D, textureList[0]);*/
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Ring::drawMesh()
{
	GLUquadric* qobj = gluNewQuadric();
	glRotatef(80, 1, 0, 0);
	glutWireTorus(r, R, 8, 8);
	glFlush();
	gluDeleteQuadric(qobj);
}

void Ring::draw()
{
	//GLUquadric* qobj = gluNewQuadric();
	//glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	//glEnable(GL_TEXTURE_GEN_T);
	//glBindTexture(GL_TEXTURE_2D, textureList[0]);
	////gluQuadricTexture(qobj, GL_TRUE);
	//gluQuadricDrawStyle(qobj, GLU_FILL);
	//gluQuadricTexture(qobj, GL_TRUE);
	//gluQuadricNormals(qobj, GLU_SMOOTH);
	//glRotatef(85, 1, 0, 0);
	//glutSolidTorus(r, R, 40, 40);
	//glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	//glDisable(GL_TEXTURE_GEN_T);
	//glFlush();
	//gluDeleteQuadric(qobj);


	int i, j;
	GLfloat theta, phi, theta1;
	GLfloat cosTheta, sinTheta;
	GLfloat cosTheta1, sinTheta1;
	GLfloat ringDelta, sideDelta;
	GLfloat pi = 3.1415926f;
	int rings = 40;
	int sides = 40;

	ringDelta = 2.0 * pi / rings;
	sideDelta = 2.0 * pi / sides;

	theta = 0.0;
	cosTheta = 1.0;
	sinTheta = 0.0;

	glEnable(GL_TEXTURE_2D);
	glRotatef(90, 1, 0, 0);
	glBindTexture(GL_TEXTURE_2D, textureList[0]);
	for (i = rings - 1; i >= 0; i--) 
	{
		theta1 = theta + ringDelta;
		cosTheta1 = cos(theta1);
		sinTheta1 = sin(theta1);
		glBegin(GL_QUAD_STRIP);
		phi = 0.0;
		for (j = sides; j >= 0; j--) 
		{
			GLfloat cosPhi, sinPhi, dist;

			phi += sideDelta;
			cosPhi = cos(phi);
			sinPhi = sin(phi);
			dist = R + r * cosPhi;

			//glTexCoord2f(cosTheta1 * cosPhi, -sinTheta1 * cosPhi); //second
			//glTexCoord2f(cosTheta1 * dist, -sinTheta1 * dist); //first
			glTexCoord2f(theta1/(2*pi), phi/(2*pi)); //third
			glNormal3f(cosTheta1 * cosPhi, -sinTheta1 * cosPhi, sinPhi);
			glVertex3f(cosTheta1 * dist, -sinTheta1 * dist, r * sinPhi);
			//glTexCoord2f(cosTheta * cosPhi, -sinTheta * cosPhi); //second
			//glTexCoord2f(cosTheta * dist, -sinTheta * dist); //first
			glTexCoord2f(theta / (2 * pi), phi / (2 * pi)); //third
			glNormal3f(cosTheta * cosPhi, -sinTheta * cosPhi, sinPhi);
			glVertex3f(cosTheta * dist, -sinTheta * dist, r * sinPhi);
		}
		glEnd();
		theta = theta1;
		cosTheta = cosTheta1;
		sinTheta = sinTheta1;
	}
}