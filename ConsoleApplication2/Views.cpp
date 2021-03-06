// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <glut.h>

float a = 0.0f, b = 0.0f;
void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27)
		exit(0);
	else if (key == 111)
	{
		a = 5.0f;
		b = 5.0f;
	}
}
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

float angle = 0.0f;

void renderScene(void) {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(a, b, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	//glRotatef(angle, 0.0f, 1.0f, 0.0f);

	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_QUADS);
	glVertex3f(-2.0f, 0.0f, -2.0f);//1
	glVertex3f(-2.0f, 0.0f, 2.0f);//2
	glVertex3f(2.0f, 0.0f, 2.0f);//3
	glVertex3f(2.0f, 0.0f, -2.0f);//4
	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-2.0f, 0.0f, -2.0f);//1
	glVertex3f(-2.0f, 2.0f, 0.0f);//2
	glVertex3f(2.0f, 2.0f, 0.0f);//3
	glVertex3f(2.0f, 0.0f, -2.0f);//4
	glEnd();

	angle += 0.1f;

	glutSwapBuffers();
}

int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Lighthouse3D- GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);
	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}