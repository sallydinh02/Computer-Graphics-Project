#include "GL/glut.h"
#include <stdlib.h>
#include <math.h>
#include<stdio.h>
#include <iostream>
#include "Point.h"
#include "Shape.h"
#include "RectangleSquare.h"
#include "Triangle.h"
#include "RegularPolygon.h"
#include "NPolygon.h"
#include <chrono>
using namespace std;
using namespace std::chrono;
typedef std::chrono::milliseconds ms;
using namespace std;
#define N 50

int wheight = 800;
int wwidth = 800;
int idx = 0;

//top left vertices
float topleft[N][2];
//low r
float bottomright[N][2];
//color vector
int colorType[N];
//Point* p;
GLfloat angle;
GLfloat pi = 3.1415926f;
float arrTranslate[2] = { 0, 0 };
float arrScale[2][2] = {
					    {0, 0}, 
					    {0, 0} 
					   };

GLfloat arrRotate[2][2];
float arrX[50];
float arrY[50];

//bool isLeft, isRight, isUp, isDown, isScaleUp, isScaleDown, isRotateLeft, isRotateRight;
int mainMenu, subMenuTemplate, subMenuColor;
bool isDrawing = false;
//bool clearScreen = false;
bool rerender = false;
bool drawFreeStyle = false;
bool rightClick = false;
bool endDrawFreeStyle = false;


int numObj = 0;
int value;
int colorVal;
Shape* shape;

void init() 
{
	glViewport(0, 0, wwidth, wheight);
	glMatrixMode(GL_PROJECTION);
	//set current matrix to identity matrix
	glLoadIdentity();
	//smooth shading
	glShadeModel(GL_SMOOTH);
	//black background
	cout << "Clear init" << endl;
	glClearColor(0.0, 0.0, 0.0, 1.0);
}

void myReshape(GLsizei ww, GLsizei hh) 
{
	cout << "Clear color reshape" << endl;
	glClearColor(1.0, 1.0, 1.0, 1.0);
	cout << "Clear reshape" << endl;
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)ww, 0.0, (GLdouble)hh);
	glViewport(0, 0, ww, hh);
	wwidth = ww;
	wheight = hh;
}
//choose color from menu
void menu(int n) 
{
	value = n;
	if (value == 6 || value == 7 || value == 8) colorVal = value;
	glutPostRedisplay();
}
//save start coords 
void saveCoordinates(int x, int y) 
{
	topleft[numObj][0] = bottomright[numObj][0] = x;
	topleft[numObj][1] = bottomright[numObj][1] = wheight - y;
	colorType[numObj] = colorVal;
}
//save bottom right coords
void dragDraw(int x, int y) 
{
	//bottom right x
	bottomright[numObj][0] = x;
	//bottom right y
	bottomright[numObj][1] = wheight - y;
	glutPostRedisplay();
}

//void drawingFreeStylePolygon()
//{
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, (GLdouble)wwidth, 0.0, (GLdouble)wheight);
//	
//	
//}

void handleMouse(int button, int event, int x, int y) 
{
	if (button == GLUT_LEFT_BUTTON && event == GLUT_DOWN)
	{
		if (drawFreeStyle == false)
		{
			saveCoordinates(x, y);
			glutPostRedisplay();
		}
	}
	if (button == GLUT_LEFT_BUTTON && event == GLUT_UP)
	{
		
		if (drawFreeStyle==false) numObj++;
		//cout << "numObj: " << numObj << endl;
		if (drawFreeStyle)
		{
			/*vector<float>tmp;
			tmp.push_back((float)x);
			tmp.push_back((float)(wheight - y));
			cout << "Left click: " << x << " " << wheight - y << endl;*/
			cout << "index: " << idx << endl;
			arrX[idx] = x;
			arrY[idx] = wheight - y;
			cout << "Left click: " << arrX[idx] << " " << arrY[idx] << endl;
			idx++;

			//shape->p.push_back({ (float)x, (float)(wheight - y) });
			//shape->p.push_back(tmp);
			//tmp.clear();
			/*cout << "Vector size: " << shape->p.size() << endl;
			cout << "\nvector points" << endl;
			for (int i = 0; i < shape->p.size(); i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cout << "i: " << i << " j: " << j << endl;
					cout << shape->p[i][j] << " ";
				}
				cout << endl;
			}*/
			glutPostRedisplay();
		}
	}
	else if (button == GLUT_RIGHT_BUTTON && event == GLUT_UP)
	{
		if (drawFreeStyle)
		{
			cout << "index: " << idx << endl;
			arrX[idx] = x;
			arrY[idx] = wheight - y;
			cout << "Right click last point: " << arrX[idx] << " " << arrY[idx] << endl;
			++idx;
			arrX[idx] = arrX[0];
			arrY[idx] = arrY[0];
			/*shape->p.push_back({ (float)x, (float)(wheight - y) });
			cout << x << " " << wheight - y << endl;
			vector<float>tmp = { shape->p[0][0], shape->p[0][1] };
			cout << "Start point: " << shape->p[0][0] << " " << shape->p[0][1] << endl;
			shape->p.push_back(tmp);
			tmp.clear();
			cout << "Vector size: " << shape->p.size() << endl;
			cout << "\nvector points" << endl;
			for (int i = 0; i < shape->p.size(); i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cout << "i: " << i << " j: " << j << endl;
					cout << shape->p[i][j] << " ";
				}
				cout << endl;
			}*/
			rightClick = true;
			//endDrawFreeStyle = true;
			//isDrawing = false;
			glutPostRedisplay();
		}
	}
	//glutPostRedisplay();
}

void translateShape(Shape*shape,float arrTranslate[2])
{
	for (int i = 0; i < shape->getNumVertice(); i++)
	{
		/*shape->p[i].setX(shape->p[i].getX() + arrTranslate[0]);
		shape->p[i].setY(shape->p[i].getY() + arrTranslate[1]);
		cout << shape->p[i].getX() << " " << shape->p[i].getY() << endl;*/
		for (int j = 0; j < 2; j++)
		{
			shape->p[i][j] += arrTranslate[j];
		}
	}
	//set new mid point
	shape->setMid(arrTranslate[0], arrTranslate[1]);
}

void scaleShape(Shape* shape, float mat[2][2], float XFixedPoint, float YFixedPoint)
{
	int numVertice = shape->getNumVertice();
	float **res=new float*[numVertice];
	//r1
	for (int i = 0; i < numVertice; i++)
	{
		res[i] = new float[2];
		//c2
		for (int j = 0; j < 2; j++)
		{
			res[i][j] = 0;
			//c1
			for (int k = 0; k < 2; k++)
				res[i][j] += shape->p[i][k] * mat[k][j];
		}
	}
	float fixedScaleArr[2][2] = {
								  {1-mat[0][0], 0},
								  {0, 1-mat[1][1]}
								};
	float midArr[1][2] = { {XFixedPoint, YFixedPoint} };
	float fixedAdd[1][2] = { {0,0} };
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
				fixedAdd[i][j] += midArr[i][k] * fixedScaleArr[k][j];
		}
	}
	//cout << "New points scale: " << endl;
	for (int i = 0; i < numVertice; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			shape->p[i][j] = res[i][j] + fixedAdd[0][j];
			//cout << " " << shape->p[i][j] << " ";
		}
		//cout << endl;
	}
	for (int i = 0; i < numVertice; i++)
		delete res[i];
	delete[]res;
}

void rotateShape(Shape* shape, GLfloat mat[2][2], float XFixedPoint, float YFixedPoint)
{
	int numVertice = shape->getNumVertice();
	float** res = new float* [numVertice];
	for (int i = 0; i < numVertice; i++)
	{
		res[i] = new float[2];
		//c2
		for (int j = 0; j < 2; j++)
		{
			res[i][j] = 0;
			//c1
			for (int k = 0; k < 2; k++)
				res[i][j] += shape->p[i][k] * mat[k][j];
		}
	}
	//cout << "New points scale: " << endl;
	for (int i = 0; i < numVertice; i++)
	{
		shape->p[i][0] = res[i][0] + (1 - cos(angle)) * XFixedPoint + sin(angle) * YFixedPoint;
		shape->p[i][1] = res[i][1] - sin(angle) * XFixedPoint + (1 - cos(angle)) * YFixedPoint;
	}
	for (int i = 0; i < numVertice; i++)
		delete res[i];
	delete[]res;
}

void handleKeyBoard(unsigned char key, int x, int y) 
{
	//Ctrl Z: Undo
	if (key == 26) 
	{
		numObj--;
		colorType[numObj] = 0;
		topleft[numObj][0] = topleft[numObj][1] = bottomright[numObj][0] = bottomright[numObj][1] = 0;
		glutPostRedisplay();
	}
	// +: scale up
	else if (key == '+')
	{
		cout << "Scale up" << endl;
		auto startScaleUp = high_resolution_clock::now();
		arrScale[0][0] = arrScale[1][1] = 1.1;
		//cout << "arrScale: " << arrScale[0][0] << " " << arrScale[1][1] << endl;
		float XFixedPoint = shape->getXMid();
		float YFixedPoint = shape->getYMid();
		//cout << "Get Mid: " << XFixedPoint << " " << YFixedPoint << endl;
		scaleShape(shape, arrScale, XFixedPoint, YFixedPoint);
		glClear(GL_COLOR_BUFFER_BIT);
		/*glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();*/
		shape->draw();
		auto stopScaleUp = high_resolution_clock::now();
		auto durationScaleUp = duration_cast<ms>(stopScaleUp - startScaleUp);
		cout << "  Time to scale up: " << durationScaleUp.count() << " miliseconds" << endl;
	}

	// -: scale down
	else if (key == '-')
	{
		cout << "Scale down" << endl;
		auto startScaleDown = high_resolution_clock::now();
		arrScale[0][0] = arrScale[1][1] = 0.9;
		//cout << "arrScale: " << arrScale[0][0] << " " << arrScale[1][1] << endl;
		float XFixedPoint = shape->getXMid();
		float YFixedPoint = shape->getYMid();
		//cout << "Get Mid: " << XFixedPoint << " " << YFixedPoint << endl;
		scaleShape(shape, arrScale, XFixedPoint, YFixedPoint);
		glClear(GL_COLOR_BUFFER_BIT);
		/*glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();*/
		shape->draw();
		auto stopScaleDown = high_resolution_clock::now();
		auto durationScaleDown = duration_cast<ms>(stopScaleDown - startScaleDown);
		cout << "  Time to scale down: " << durationScaleDown.count() << " miliseconds" << endl;
	}

	//Upper case L: rotate left
	else if (key == 'L')
	{
		cout << "Rotate left" << endl;
		auto startRLeft = high_resolution_clock::now();
		angle = 1.0 * pi / 180;
		arrRotate[0][0] = cos(angle);
		arrRotate[0][1] = sin(angle);
		arrRotate[1][0] = -sin(angle);
		arrRotate[1][1] = cos(angle);
		/*cout << "arrRotate: " << endl;
		cout<< arrRotate[0][0] << " " << arrRotate[0][1] << endl;
		cout << arrRotate[1][0] << " " << arrRotate[1][1] << endl;*/
		float XFixedPoint = shape->getXMid();
		float YFixedPoint = shape->getYMid();
		//cout << "Get Mid: " << XFixedPoint << " " << YFixedPoint << endl;
		rotateShape(shape, arrRotate, XFixedPoint, YFixedPoint);
		glClear(GL_COLOR_BUFFER_BIT);
		/*glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();*/
		shape->draw();
		auto stopRLeft = high_resolution_clock::now();
		auto durationRLeft = duration_cast<ms>(stopRLeft - startRLeft);
		cout << "  Time to rotate left: " << durationRLeft.count() << " miliseconds" << endl;
	}

	//Upper case R: rotate right
	else if (key == 'R')
	{
		cout << "Rotate right" << endl;
		auto startRRight = high_resolution_clock::now();
		angle = -1.0 * pi / 180;
		arrRotate[0][0] = cos(angle);
		arrRotate[0][1] = sin(angle);
		arrRotate[1][0] = -sin(angle);
		arrRotate[1][1] = cos(angle);
		/*cout << "arrRotate: " << endl;
		cout << arrRotate[0][0] << " " << arrRotate[0][1] << endl;
		cout << arrRotate[1][0] << " " << arrRotate[1][1] << endl;*/
		float XFixedPoint = shape->getXMid();
		float YFixedPoint = shape->getYMid();
		//cout << "Get Mid: " << XFixedPoint << " " << YFixedPoint << endl;
		rotateShape(shape, arrRotate, XFixedPoint, YFixedPoint);
		glClear(GL_COLOR_BUFFER_BIT);
		/*glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();*/
		shape->draw();
		auto stopRRight = high_resolution_clock::now();
		auto durationRRight = duration_cast<ms>(stopRRight - startRRight);
		cout << "  Time to rotate right: " << durationRRight.count() << " miliseconds" << endl;
	}
}

void specialKey(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)
	{
		cout << "Up" << endl;
		auto startUp = high_resolution_clock::now();
		arrTranslate[0] = 0;
		arrTranslate[1] = 1;
		//cout << "arrTranslate: " << arrTranslate[0] << " " << arrTranslate[1] << endl;
		translateShape(shape, arrTranslate);
		glClear(GL_COLOR_BUFFER_BIT);
		/*glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();*/
		shape->draw();
		auto stopUp = high_resolution_clock::now();
		auto durationUp = duration_cast<ms>(stopUp - startUp);
		cout << "  Time to translate up: " << durationUp.count() << " miliseconds" << endl;
		//glutPostRedisplay;
	}
	else if (key == GLUT_KEY_DOWN)
	{
		/*isDown = true;
		if (isDown && !isUp && !isLeft && !isRight)
		{
			
		}*/
		cout << "Down" << endl;
		auto startDown = high_resolution_clock::now();
		arrTranslate[0] = 0;
		arrTranslate[1] = -1;
		//cout << "arrTranslate: " << arrTranslate[0] << " " << arrTranslate[1] << endl;
		translateShape(shape, arrTranslate);
		glClear(GL_COLOR_BUFFER_BIT);
		/*glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();*/
		shape->draw();
		auto stopDown = high_resolution_clock::now();
		auto durationDown = duration_cast<ms>(stopDown - startDown);
		cout << "  Time to translate down: " << durationDown.count() << " miliseconds" << endl;
	}
	else if (key == GLUT_KEY_LEFT)
	{
		/*isLeft = true;*/
		cout << "Left" << endl;
		auto startLeft = high_resolution_clock::now();
		arrTranslate[0]=-1;
		arrTranslate[1] = 0;
		//cout << "arrTranslate: " << arrTranslate[0] << " " << arrTranslate[1] << endl;
		translateShape(shape, arrTranslate);
		glClear(GL_COLOR_BUFFER_BIT);
		/*glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();*/
		shape->draw();
		auto stopLeft = high_resolution_clock::now();
		auto durationLeft = duration_cast<ms>(stopLeft - startLeft);
		cout << "  Time to translate left: " << durationLeft.count() << " miliseconds" << endl;
		//glutPostRedisplay;
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		/*isRight = true;*/
		cout << "Right" << endl;
		auto startRight = high_resolution_clock::now();
		arrTranslate[0] = 1;
		arrTranslate[1] = 0;
		//cout << "arrTranslate: " << arrTranslate[0] << " " << arrTranslate[1] << endl;
		translateShape(shape, arrTranslate);
		glClear(GL_COLOR_BUFFER_BIT);
		/*glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();*/
		shape->draw();
		auto stopRight = high_resolution_clock::now();
		auto durationRight = duration_cast<ms>(stopRight - startRight);
		cout << "  Time to translate right: " << durationRight.count() << " miliseconds" << endl;
		//glutPostRedisplay;
	}
}

void display(void) 
{
	cout << "Clear color display" << endl;
	glClearColor(1.0, 1.0, 1.0, 1.0);
	cout << "Clear display" << endl;
	glClear(GL_COLOR_BUFFER_BIT);
	int i = 0;
	int count = 0;
	while (i <= numObj)
	{
		//cout << "i " << i << endl;
		if (value == 1)
		{
			/*Point a(topleft[i][0], topleft[i][1]);
			Point b(bottomright[i][0], bottomright[i][1]);*/
			isDrawing = true;
			shape = new Triangle(3, topleft[i][0], topleft[i][1], bottomright[i][0], bottomright[i][1]);
			//shape->draw();
			//cout << "Points: " << shape->p[0].getX() << " " << shape->p[1].getX() << " " << shape->p[2].getX() << endl;
			/*delete shape;*/
		}
		if (value == 2)
		{
			/*Point a(topleft[i][0], topleft[i][1]);
			Point b(bottomright[i][0], bottomright[i][1]);*/
			isDrawing = true;
			shape = new RectangleSquare(4, topleft[i][0], topleft[i][1], bottomright[i][0], bottomright[i][1]);
			//shape->draw();
			/*delete shape;*/
		}
		if (value == 3)
		{
			isDrawing = true;
			shape = new RegularPolygon(5, topleft[i][0], topleft[i][1], bottomright[i][0], bottomright[i][1]);
			//shape->draw();
		}
		if (value == 4)
		{
			isDrawing = true;
			shape = new RegularPolygon(6, topleft[i][0], topleft[i][1], bottomright[i][0], bottomright[i][1]);
			//shape->draw();
		}
		if (value == 5)
		{
			isDrawing = true;
			drawFreeStyle = true;
			//shape = new Shape();
		}
		if (colorType[i] == 0)
		{
			rerender = true;
			glColor3f(0.0, 0.0, 0.0);
		}
		if (colorType[i] == 6)
		{
			rerender = true;
			glColor3f(1.0, 0.0, 0.0);
		}
		if (colorType[i] == 7)
		{
			rerender = true;
			glColor3f(0.0, 0.0, 1.0);
		}
		if (colorType[i] == 8)
		{
			rerender = true;
			glColor3f(0.0, 1.0, 0.0);
		}
		//if (value == 9)
		//{
		//	glClear(GL_COLOR_BUFFER_BIT);
		//	numObj--;
		//	colorType[i] = 0;
		//	topleft[i][0] = topleft[i][1] = bottomright[i][0] = bottomright[i][1] = 0;
		//	shape = NULL;
		//	/*if (i == 0)
		//	{
		//		colorType[i] = 0;
		//		topleft[i][0] = topleft[i][1] = bottomright[i][0] = bottomright[i][1] = 0;
		//	}
		//	else
		//	{
		//		--i;
		//		colorType[i] = 0;
		//		topleft[i][0] = topleft[i][1] = bottomright[i][0] = bottomright[i][1] = 0;
		//	}*/
		//	//glutPostRedisplay();
		//	/*numObj--;
		//	colorType[numObj] = 0;
		//	topleft[numObj][0] = topleft[numObj][1] = bottomright[numObj][0] = bottomright[numObj][1] = 0;
		//	glutPostRedisplay();*/
		//}
		if (rerender)
		{
			cout << "Clear rerender" << endl;
			glClear(GL_COLOR_BUFFER_BIT);
			count++;
			//cout << "Count: "<<count << endl;
			if (isDrawing)
			{
				if (count > 1)
				{
					numObj--;
					colorType[i] = 0;
					topleft[i][0] = topleft[i][1] = bottomright[i][0] = bottomright[i][1] = 0;
					isDrawing = false;
				}
				if (shape)
				{
					shape->draw();
					isDrawing = false;
				}
				else if (drawFreeStyle)
				{
					//shape->drawAnyPolygon(rightClick, arrX, arrY, idx);
					//idx++;
					if (rightClick)
					{
						cout << "xprev: " << arrX[idx - 1] << " yprev: " << arrY[idx - 1] << endl;
						cout << "x: " << arrX[idx] << " y: " << arrY[idx] << endl;
						cout << "\n";
						for (int i = 0; i < idx; i++)
						{
							cout << arrX[i] << " " << arrY[i] << endl;
						}
						cout << "idx when click right: " << idx << endl;
						glBegin(GL_LINE_STRIP);
						glVertex2f(arrX[idx - 2], arrY[idx - 2]);
						glVertex2f(arrX[idx - 1], arrY[idx - 1]);
						glVertex2f(arrX[idx], arrY[idx]);
						
						glEnd();
						glFlush();
						//drawFreeStyle = false;
						isDrawing = false;
						//endDrawFreeStyle = true;
						cout << "Create NPolygon" << endl;
						shape = new NPolygon(idx, arrX, arrY);
						drawFreeStyle = false;
					}
					else
					{
						glBegin(GL_LINE_STRIP);
						for (int k = 0; k < idx; k++)
						{
							cout << "k: " << k << endl;
							glVertex2f(arrX[k], arrY[k]);
						}
						glEnd();
						glFlush();
					}
				}
			}
			/*else if (isDrawing == false && drawFreeStyle == true)
			{
				
			}*/
			/*if (endDrawFreeStyle)
			{
				shape = new NPolygon(idx + 1, arrX, arrY);
			}*/
		}
		i++;
	}
	
	glFlush();
	glutSwapBuffers();
}

void createMenu(void)
{
	subMenuTemplate = glutCreateMenu(menu);
	glutAddMenuEntry("Triangle", 1);
	glutAddMenuEntry("Rectangle/Square", 2);
	glutAddMenuEntry("Pentagon", 3);
	glutAddMenuEntry("Hexagon", 4);
	subMenuColor = glutCreateMenu(menu);
	glutAddMenuEntry("Red", 6);
	glutAddMenuEntry("Blue", 7);
	glutAddMenuEntry("Green", 8);
	mainMenu = glutCreateMenu(menu);
	glutAddSubMenu("Template polygon", subMenuTemplate);
	glutAddMenuEntry("Draw any polygon", 5);
	glutAddSubMenu("Color", subMenuColor);
	//glutAddMenuEntry("Clear screen", 9);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char* argv[]) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(wwidth, wheight);
	glutInitWindowPosition(300, 0);
	glutCreateWindow("20125060_Lab3");
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutSpecialFunc(specialKey);
	glutKeyboardFunc(handleKeyBoard);
	glutMouseFunc(handleMouse);
	glutMotionFunc(dragDraw);
	
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	createMenu();
	init();
	glutMainLoop();
	//shape->p.clear();
	delete shape;
	return 0;
}

