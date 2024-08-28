#include <math.h>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
typedef std::chrono::milliseconds ms;
#include "Line.h"
#include "Circle.h"
#include "Ellipse.h"
#include "IsoTriangle.h"
#include "EquiTriangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "RegularPolygon.h"
#include "Arrow.h"
#include "Star.h"
#include "Plus.h"
#include "Multiplication.h"
#include "Division.h"
#include "Division2.h"
int ww = 800, wh = 800;
static int window, returnmenu, returnsubmenu2, returnsubmenu3, returnsubmenu4, returnsubmenu5, returnsubmenu6, returnsubmenu7, returnsubmenu8, value;
float fillCol[3];
const float borderCol[3] = { 0.0, 0.0, 0.0 };

void menu(int n)
{
	value = n;
	glutPostRedisplay();
}

void createMenu(void)
{

	//Triangle
	returnsubmenu2 = glutCreateMenu(menu);
	glutAddMenuEntry("Right isosceles triangle", 1);
	glutAddMenuEntry("Equilateral triangle", 2);

	//Quadrangle: 4-sided
	returnsubmenu3 = glutCreateMenu(menu);
	glutAddMenuEntry("Rectangle", 3);
	glutAddMenuEntry("Square", 4);

	//Oval
	returnsubmenu4 = glutCreateMenu(menu);
	glutAddMenuEntry("Circle", 5);
	glutAddMenuEntry("Ellipse", 6);

	//Regular polygon: da giac deu
	returnsubmenu5 = glutCreateMenu(menu);
	glutAddMenuEntry("Regular pentagon", 7);
	glutAddMenuEntry("Regular hexagon", 8);

	//Others
	returnsubmenu6 = glutCreateMenu(menu);
	glutAddMenuEntry("Arrow", 9);
	glutAddMenuEntry("Star", 10);

	//Sign
	returnsubmenu7 = glutCreateMenu(menu);
	glutAddMenuEntry("Plus", 11);
	glutAddMenuEntry("Minus", 12);
	glutAddMenuEntry("Multiplication", 13);
	glutAddMenuEntry("Division", 14);

	//Choose color
	returnsubmenu8 = glutCreateMenu(menu);
	glutAddMenuEntry("Blue", 15);
	glutAddMenuEntry("Red", 16);
	glutAddMenuEntry("Yellow", 17);

	returnmenu = glutCreateMenu(menu); //function to call menu function and return value
	glutAddMenuEntry("Line", 18);
	glutAddSubMenu("Triangle", returnsubmenu2);
	glutAddSubMenu("Quadrangle", returnsubmenu3);
	glutAddSubMenu("Oval", returnsubmenu4);
	glutAddSubMenu("Regular polygon", returnsubmenu5);
	glutAddSubMenu("Others", returnsubmenu6);
	glutAddSubMenu("Sign", returnsubmenu7);
	glutAddSubMenu("Fill color", returnsubmenu8);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void setPixel(int pointx, int pointy, float f[3])
{
	glBegin(GL_POINTS);
	glColor3f(f[0], f[1], f[2]);
	glVertex2i(pointx, pointy);
	glEnd();
	glFlush();
}

void getPixel(int x, int y, float pixels[3])
{
	glReadPixels(x, wh - y, 1.0, 1.0, GL_RGB, GL_FLOAT, pixels);
}

void boundaryFill4(int x, int y, float fillColor[3], const float borderColor[3])
{
	float interiorColor[3];
	getPixel(x, y, interiorColor);
	/*cout << "Inside " << interiorColor[0] << " " << interiorColor[1] << " " << interiorColor[2] << endl;
	cout << "Border " << borderColor[0] << " " << borderColor[1] << " " << borderColor[2] << endl;
	cout << "Fill " << fillColor[0] << " " << fillColor[1] << " " << fillColor[2] << endl;
	cout << "------------------------------------\n" << endl;*/
	if (interiorColor[0] == borderColor[0] && interiorColor[1] == borderColor[1] && interiorColor[2] == borderColor[2])
		return;
	if (interiorColor[0] == fillColor[0] && interiorColor[1] == fillColor[1] && interiorColor[2] == fillColor[2])
		return;
	setPixel(x, y, fillColor);
	boundaryFill4(x - 1, y, fillColor, borderColor);
	boundaryFill4(x, y + 1, fillColor, borderColor);
	boundaryFill4(x + 1, y, fillColor, borderColor);
	boundaryFill4(x, y - 1, fillColor, borderColor);
}

void floodFill(int x, int y, float fillColor[3], const float borderColor[3])
{
	float interiorColor[3];
	getPixel(x, y, interiorColor);
	if (interiorColor[0] == borderColor[0] && interiorColor[1] == borderColor[1] && interiorColor[2] == borderColor[2])
	{
		getPixel(x, y, interiorColor);
		floodFill(x + 1, y, fillColor, borderColor);
		floodFill(x, y + 1, fillColor, borderColor);
		floodFill(x - 1, y, fillColor, borderColor);
		floodFill(x, y - 1, fillColor, borderColor);
	}
	return;
}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int xi = x;
		int yi = y;
		cout << "Click " << xi << " "<<yi << endl;
		cout << "Fill color: " << fillCol[0] << " " << fillCol[1] << " " << fillCol[2] << endl;
		auto start = high_resolution_clock::now();
		boundaryFill4(xi, yi, fillCol, borderCol);
		auto stop = high_resolution_clock::now();
		auto duration2 = duration_cast<ms>(stop - start);
		cout << "Boundary Fill: " << duration2.count() << " miliseconds" << endl;
		//glutPostRedisplay();
	}
}

void display(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//glClearColor(0.6, 0.8, 0.1, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	if (value == 0) {
		return;
	}

	else if (value == 1)
	{
		Shape* shape = new IsoTriangle(value, 450, 450, 50);
		shape->draw();
		delete(shape);
	}

	else if (value == 2)
	{
		Shape* shape = new EquiTriangle(value, 450, 450, 50, 50);
		shape->draw();
		delete(shape);
	}

	else if (value == 3)
	{
		Shape* shape = new Rectangle(value, 450, 450, 40, 50);
		shape->draw();
		delete(shape);
	}

	else if (value == 4)
	{
		Shape* shape = new Square(value, 450, 450, 50);
		shape->draw();
		delete(shape);
	}

	else if (value == 5)
	{
		Shape* shape = new Circle(value, 400, 400, 25);
		shape->draw();
		delete(shape);
	}

	else if (value == 6)
	{
		Shape* shape = new Ellipse(value, 400, 400, 40, 20);
		shape->draw();
		delete(shape);
	}

	else if (value == 7)
	{
		Shape* shape = new RegularPolygon(value, 400, 400, 5, 30);
		shape->draw();
		delete(shape);
	}

	else if (value == 8)
	{
		Shape* shape = new RegularPolygon(value, 400, 400, 6, 30);
		shape->draw();
		delete(shape);
	}

	else if (value == 9)
	{
		Shape* shape = new Arrow(value, 300, 300, 40, 20, 10, 20);
		shape->draw();
		delete(shape);
	}

	else if (value == 10)
	{
		Shape* shape = new Star(value, 400, 400, 50);
		shape->draw();
		delete(shape);
	}

	else if (value == 11)
	{
		Shape* shape = new Plus(value, 400, 400, 30, 20);
		shape->draw();
		delete(shape);
	}

	//minus
	else if (value == 12)
	{
		Shape* shape = new Rectangle(value, 450, 450, 70, 30);
		shape->draw();
		delete(shape);
	}

	else if (value == 13)
	{
		Shape* shape = new Multiplication(value, 400, 300, 15, 15);
		shape->draw();
		delete(shape);
	}

	else if (value == 14)
	{
		//Shape* shape = new Division(value, 400, 300, 40, 70);
		Shape* shape = new NewDivision(value, 400, 300, 10, 50, 15);
		shape->draw();
		delete(shape);
	}

	else if (value == 18)
	{
		Shape* shape = new Line(value, 1, 2, 600, 650);
		shape->draw();
		delete(shape);
	}

	//blue
	else if (value == 15)
	{
		/*fillCol[0] = 0.0;
		fillCol[1] = 0.0;
		fillCol[2] = 1.0;*/
		const static float newvals[] = {0.0,0.0,1.0};
		std::copy(newvals, newvals + sizeof(newvals) / sizeof(newvals[0]), fillCol);
		//Fcolor = { 0.0, 0.0, 1.0 };
	}

	//red
	else if (value == 16)
	{
		/*fillCol[0] = 1.0;
		fillCol[1] = 0.0;
		fillCol[2] = 0.0;*/
		const static float newvals[] = { 1.0,0.0,0.0 };
		std::copy(newvals, newvals + sizeof(newvals) / sizeof(newvals[0]), fillCol);
		//Fcolor = { 1.0, 0.0, 0.0 };
	}

	//yellow
	else if (value == 17)
	{
		/*fillCol[0] = 1.0;
		fillCol[1] = 1.0;
		fillCol[2] = 0.0;*/
		const static float newvals[] = { 1.0,1.0,0.0 };
		std::copy(newvals, newvals + sizeof(newvals) / sizeof(newvals[0]), fillCol);
		//Fcolor = { 1.0, 1.0, 0.0 };
	}

	glFlush();
}

void init(void)
{
	/*glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 800, 0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);*/

	/*glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, ww, wh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 0.0, (GLdouble)ww, (GLdouble)wh);
	glMatrixMode(GL_MODELVIEW);*/

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, (GLdouble)ww, (GLdouble)wh, 0.0);
	glColor3f(0.0, 0.0, 0.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(ww, wh);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("20125060_Lab1");
	glutDisplayFunc(display);
	
	createMenu();
	//glClearColor(0.0, 0.0, 0.0, 0.0);
	init();
	glutMouseFunc(mouse);
	glutMainLoop();
	return 1;

	/*fillCol[0] = 1.0;
	fillCol[1] = 1.0;
	fillCol[2] = 1.0;
	cout << fillCol[0] << " " << fillCol[1] << " " << fillCol[2] << endl;*/
}

