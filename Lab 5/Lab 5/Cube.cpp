#include "Cube.h"
Cube::Cube():Shape()
{
	for (int i = 0; i < this->numSurface; i++)
		textureList[i] = i;
}

Cube::Cube(int numSurface) :Shape(numSurface)
{
	// Front face
	this->p.push_back({ -0.8f, -0.8f, 0.8f });
	this->p.push_back({ 0.8f, -0.8f, 0.8f });
	this->p.push_back({ 0.8f, 0.8f, 0.8f });
	this->p.push_back({ -0.8f, 0.8f, 0.8f });

	// Back face
	this->p.push_back({ -0.8f, -0.8f, -0.8f });
	this->p.push_back({ -0.8f, 0.8f, -0.8f });
	this->p.push_back({ 0.8f, 0.8f, -0.8f });
	this->p.push_back({ 0.8f, -0.8f, -0.8f });

	// Top Face
	this->p.push_back({ -0.8f, 0.8f, -0.8f });
	this->p.push_back({ -0.8f, 0.8f, 0.8f });
	this->p.push_back({ 0.8f, 0.8f, 0.8f });
	this->p.push_back({ 0.8f, 0.8f, -0.8f });
	// Bottom Face
	this->p.push_back({ -0.8f, -0.8f, -0.8f });
	this->p.push_back({ 0.8f, -0.8f, -0.8f });
	this->p.push_back({ 0.8f, -0.8f, 0.8f });
	this->p.push_back({ -0.8f, -0.8f, 0.8f });
	// Right face
	this->p.push_back({ 0.8f, -0.8f, -0.8f });
	this->p.push_back({ 0.8f, 0.8f, -0.8f });
	this->p.push_back({ 0.8f, 0.8f, 0.8f });
	this->p.push_back({ 0.8f, -0.8f, 0.8f });
	// Left Face
	this->p.push_back({ -0.8f, -0.8f, -0.8f });
	this->p.push_back({ -0.8f, -0.8f, 0.8f });
	this->p.push_back({ -0.8f, 0.8f, 0.8f });
	this->p.push_back({ -0.8f, 0.8f, -0.8f });
}

void Cube::loadTexture(const char* textureName[])
{
	for (int i = 0; i < this->numSurface; i++)
	{
		// load an image file directly as a new opengl texture
		//cout << "textureName["<<i<<"]: " << textureName[i] << endl;
		textureList[i] = SOIL_load_OGL_texture
		(
			textureName[rand() % 6],
			//textureName[i],
			//textureName[1],
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
		);
		/*glBindTexture(GL_TEXTURE_2D, textureList[i]);*/
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
}

void Cube::drawMesh()
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 4; i++)
	{
		glVertex3f(this->p[i][0], this->p[i][1], this->p[i][2]);
	}
	glEnd();
	glFlush();
	glBegin(GL_LINE_LOOP);
	for (int i = 4; i < 8; i++)
	{
		glVertex3f(this->p[i][0], this->p[i][1], this->p[i][2]);
	}
	glEnd();
	glFlush();
	glBegin(GL_LINE_LOOP);
	for (int i = 8; i < 12; i++)
	{
		glVertex3f(this->p[i][0], this->p[i][1], this->p[i][2]);
	}
	glEnd();
	glFlush();
	glBegin(GL_LINE_LOOP);
	for (int i = 12; i < 16; i++)
	{
		glVertex3f(this->p[i][0], this->p[i][1], this->p[i][2]);
	}
	glEnd();
	glFlush();
}

void Cube::draw()
{
	glBegin(GL_QUADS);
	// Front Face
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureList[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(this->p[0][0], this->p[0][1], this->p[0][2]);
	glTexCoord2f(0.8f, 0.0f); glVertex3f(this->p[1][0], this->p[1][1], this->p[1][2]);
	glTexCoord2f(0.8f, 0.8f); glVertex3f(this->p[2][0], this->p[2][1], this->p[2][2]);
	glTexCoord2f(0.0f, 0.8f); glVertex3f(this->p[3][0], this->p[3][1], this->p[3][2]);
	glEnd();
	// Back Face
	glBindTexture(GL_TEXTURE_2D, textureList[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.8f, 0.0f); glVertex3f(this->p[4][0], this->p[4][1], this->p[4][2]);
	glTexCoord2f(0.8f, 0.8f); glVertex3f(this->p[5][0], this->p[5][1], this->p[5][2]);
	glTexCoord2f(0.0f, 0.8f); glVertex3f(this->p[6][0], this->p[6][1], this->p[6][2]);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(this->p[7][0], this->p[7][1], this->p[7][2]);
	glEnd();
	// Top Face
	glBindTexture(GL_TEXTURE_2D, textureList[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.8f); glVertex3f(this->p[8][0], this->p[8][1], this->p[8][2]);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(this->p[9][0], this->p[9][1], this->p[9][2]);
	glTexCoord2f(0.8f, 0.0f); glVertex3f(this->p[10][0], this->p[10][1], this->p[10][2]);
	glTexCoord2f(0.8f, 0.8f); glVertex3f(this->p[11][0], this->p[11][1], this->p[11][2]);
	glEnd();
	// Bottom Face
	glBindTexture(GL_TEXTURE_2D, textureList[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.8f, 0.8f); glVertex3f(this->p[12][0], this->p[12][1], this->p[12][2]);
	glTexCoord2f(0.0f, 0.8f); glVertex3f(this->p[13][0], this->p[13][1], this->p[13][2]);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(this->p[14][0], this->p[14][1], this->p[14][2]);
	glTexCoord2f(0.8f, 0.0f); glVertex3f(this->p[15][0], this->p[15][1], this->p[15][2]);
	glEnd();
	// Right face
	glBindTexture(GL_TEXTURE_2D, textureList[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.8f, 0.0f); glVertex3f(this->p[16][0], this->p[16][1], this->p[16][2]);
	glTexCoord2f(0.8f, 0.8f); glVertex3f(this->p[17][0], this->p[17][1], this->p[17][2]);
	glTexCoord2f(0.0f, 0.8f); glVertex3f(this->p[18][0], this->p[18][1], this->p[18][2]);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(this->p[19][0], this->p[19][1], this->p[19][2]);
	glEnd();
	// Left Face
	glBindTexture(GL_TEXTURE_2D, textureList[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(this->p[20][0], this->p[20][1], this->p[20][2]);
	glTexCoord2f(0.8f, 0.0f); glVertex3f(this->p[21][0], this->p[21][1], this->p[21][2]);
	glTexCoord2f(0.8f, 0.8f); glVertex3f(this->p[22][0], this->p[22][1], this->p[22][2]);
	glTexCoord2f(0.0f, 0.8f); glVertex3f(this->p[23][0], this->p[23][1], this->p[23][2]);
	glEnd();
	glFlush();
	/*xrot += 0.3f;
	yrot += 0.2f;
	zrot += 0.4f;*/
}