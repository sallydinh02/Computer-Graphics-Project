#include "Shape.h"
using namespace std;
#ifndef _CUBE_H_
#define _CUBE_H_
class Cube :public Shape
{
private:
	GLuint textureList[6];
public:
	Cube();
	Cube(int numSurface);
	void loadTexture(const char* textureName[]);
	void draw();
	void drawMesh();
	~Cube() {};
};
#endif
