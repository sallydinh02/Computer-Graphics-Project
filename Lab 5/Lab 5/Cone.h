#include "Shape.h"
using namespace std;
#ifndef _CONE_H_
#define _CONE_H_
class Cone :public Shape
{
private:
	float r, h;
	GLuint textureList[2];
public:
	Cone();
	Cone(int numSurface, float r, float h);
	void loadTexture(const char* textureName[]);
	void drawMesh();
	void draw();
	~Cone() {};
};
#endif
