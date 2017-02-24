#include<iostream>
#include <cstdlib>
#include <GL/freeglut.h>
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;

float x = 1, y = 1;



void init(void) {

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void reshapeFunc(int width, int height) {

	// prevent divide by ZERO
	if (height == 0) {
		height = 1;

	}
	else {
		height = height;
	}


	float aspectRatio = (GLfloat)width / (GLfloat)height;


	glViewport(0, 0, width, height);


	//Define the world coordinates frame
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	if (width <= height)
		glOrtho(-x, x, -y / aspectRatio, y / aspectRatio, -1.0, 1.0);
	else
		glOrtho(-x*aspectRatio, x*aspectRatio, -y, y, -1.0, 1.0);
}

void drawCircle(float pointX, float pointY, float Radius, int PointsDrawn)
{

	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i < PointsDrawn; i++)
	{
		float theta = i * (2.0f * (float)M_PI / PointsDrawn);
		float x = Radius * cos(theta);
		float y = Radius * sin(theta);
		glVertex2f(x + pointX, y + pointY);


	}
	glEnd();
}



void pointAbove(float pointX, float pointY, float Radius, int PointsDrawn)
{
	glPointSize(4);
	glColor3f(1.0f, 0.0f, 0.0);
	glBegin(GL_POINTS);

	for (int i = 0; i < PointsDrawn; i++)
	{
		float theta = i * (2.0f * (float)M_PI / PointsDrawn);
		float x = Radius * cos(theta);
		float y = Radius * sin(theta);
		glVertex2f(x + pointX, y + pointY);


	}
	glEnd();
}



//Text

void print(float x, float y, float angle, char* text) {

	glPushMatrix();

	glTranslatef(x, y, 0);
	
	glScalef(1 / (GLfloat)980.0, 1 / (GLfloat)980.0, 0);

	glRotatef(angle, 0, 0, 1);

	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *text);

	glPopMatrix();

}


void drawTraingle() {

	glColor3f(81.0f / 255, 92.0f / 255, 125.0f / 255);


	glBegin(GL_POLYGON);


	glVertex2f(0.045f, 0.0f);


	glVertex2f(-0.045f, 0.0f);



	glVertex2f(0.0f, 0.48f);

	glEnd();
}


void drawTraingleFanFive() {

	glScalef(0.04f, 0.04f, 0);

	glBegin(GL_TRIANGLE_FAN);


	glColor3f(81.0f / 255, 92.0f / 255, 125.0f / 255);
	
	glVertex2f(0.0f, 0.8f);


	glVertex2f(0.0f, 0.0f);


	glVertex2f(-0.34f, 0.21f);

	glEnd();

}


void Star() {

	for (int i = 0;i <360;i = i + 72) {
	


		glPushMatrix();
		glRotatef((float)i, 0, 0, 1);

		drawTraingleFanFive();
		glPopMatrix();



		glPushMatrix();
		glScalef(-1, 1, 0);
		glRotatef((float)i, 0, 0, 1);




		drawTraingleFanFive();

		glPopMatrix();

	}


}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	//---------------FILL CIRCLE Bottom full yellow----------------------
	glColor3f(247.0f / 255, 183.0f / 255, 50.0f / 255);
	drawCircle(0.0f, 0.0f, 0.80f, 360);


	//---------------FILL CIRCLE above blue change radius----------------------
	glColor3f(3.0f / 255, 21.0f / 255, 83.0f / 255);
	drawCircle(0.0f, 0.0f, 0.77f, 360);

	//---------------Fill CIRCLE bottom yellow change radius----------------------
	glColor3f(247.0f / 255, 183.0f / 255, 50.0f / 255);
	drawCircle(0.0f, 0.0f, 0.62f, 360);

	//---------------Fill CIRCLE above blue change radius----------------------
	glColor3f(3.0f / 255, 21.0f / 255, 83.0f / 255);
	drawCircle(0.0f, 0.0f, 0.6133f, 360);



	//---------------Traingle and star--------------------------------

	for (int i = 0;i <= 360;i = i + 15) {
		glRotatef((float)i, 0, 0, 1);
		drawTraingle();
		glLoadIdentity();

	}





	for (int i = 0;i <= 360;i = i + 8) {

		glRotatef((float)i, 0, 0, 1);
		glTranslatef(0.56f, 0.0f, 0.0f);
		Star();
		glLoadIdentity();

	}

	glColor3f(81.0f / 255, 92.0f / 255, 125.0f / 255);
	drawCircle(0.0f, 0.0f, 0.13f, 720);


	glColor3f(247.0f / 255, 183.0f / 255, 50.0f / 255);
	drawCircle(0.0f, 0.0f, 0.11f, 720);




	glColor3f(1.0f, 1.0f, 1.0f);
	char *ch = "ENERGY RESEARCH & DEVELOPMENT ADMINISTRATION USA";
	for (int i = 0; i <48; ++i)
	{
		float radius = (float)M_PI / 180;

		double angle = 135 - 7.5 * i;
		double angleletter = 45 - 7.5 * i;
		print(0.64f*(float)cos(angle*radius), 0.64f*(float)sin(angle*radius), (float)angleletter, ch + i);
	}


	glFlush();
}














int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(590, 590);
	glutInitWindowPosition(450, 50);
	glutCreateWindow("Frame");
	init();
	glutDisplayFunc(&display);
	glutReshapeFunc(&reshapeFunc);
	glutMainLoop();

	return EXIT_SUCCESS;
}