
#include "stdafx.h"


#include <glut.h>
bool mode1=true,point=false;
int mode = 0;//0-shaded,1-wireframe,2-points
float a = 0.0f, b = 0.0f;
void processNormalKeys(unsigned char key, int x, int y) {

	if (key == 27)
		exit(0);
	else if (key == 111)
	{
		a = 5.0f;
		b = 5.0f;
	}
	else if (key == 112)
	{
		a = 0.0f;
		b = 0.0f;
	}
	else if (key == 'm')
	{
		mode = 1;
	}
	else if (key == 'l')
	{
		mode = 2;

	}
	else if (key == 'z')
	{
		mode = 0;

	}
	/*else if (key == 'l')
	{
		if (point)
			point = false;
		else if (!point)
			point = true;
	}*/
}
void changeSize(int w, int h) {

	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
	
}

float angle = 0.0f;

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();

	gluLookAt(a, b, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
	if (mode == 0)
	{
		//glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glColor3f(0.1f, 0.3f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(-2.0f, 0.0f, -2.0f);//1
	glVertex3f(-2.0f, 0.0f, 2.0f);//2
	glVertex3f(2.0f, 0.0f, 2.0f);//3
	glVertex3f(2.0f, 0.0f, -2.0f);//4
	glEnd();
	glColor3f(1.0f, 0.2f, 0.5f);
	glBegin(GL_QUADS);
	glVertex3f(-2.0f, 0.0f, -2.0f);//1
	glVertex3f(-2.0f, 2.0f, -2.0f);//2
	glVertex3f(2.0f, 2.0f, -2.0f);//3
	glVertex3f(2.0f, 0.0f, -2.0f);//4
	glEnd();

	glColor3f(0.3f, 1.0f, 0.3f);
	glBegin(GL_QUADS);
	glVertex3f(2.0f, 0.0f, 2.0f);//1
	glVertex3f(2.0f, 2.0f, 2.0f);//2
	glVertex3f(-2.0f, 2.0f, 2.0f);//3
	glVertex3f(-2.0f, 0.0f, 2.0f);//4
	glEnd();

	glColor3f(0.3f, 0.3f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-2.0f, 2.0f, -2.0f);//2
	glVertex3f(2.0f, 2.0f, -2.0f);//3
	glVertex3f(2.0f, 2.0f, 2.0f);//1		
	glVertex3f(-2.0f, 2.0f, 2.0f);//4
	glEnd();
}
	else if (mode == 1)
	{
		glColor3f(0.1f, 0.3f, 0.5f);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-2.0f, 0.0f, -2.0f);//1
		glVertex3f(-2.0f, 0.0f, 2.0f);//2
		glVertex3f(2.0f, 0.0f, 2.0f);//3
		glVertex3f(2.0f, 0.0f, -2.0f);//4
		glEnd();
		glColor3f(1.0f, 0.2f, 0.5f);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-2.0f, 0.0f, -2.0f);//1
		glVertex3f(-2.0f, 2.0f, -2.0f);//2
		glVertex3f(2.0f, 2.0f, -2.0f);//3
		glVertex3f(2.0f, 0.0f, -2.0f);//4
		glEnd();

		glColor3f(0.3f, 1.0f, 0.3f);
		glBegin(GL_LINE_LOOP);
		glVertex3f(2.0f, 0.0f, 2.0f);//1
		glVertex3f(2.0f, 2.0f, 2.0f);//2
		glVertex3f(-2.0f, 2.0f, 2.0f);//3
		glVertex3f(-2.0f, 0.0f, 2.0f);//4
		glEnd();

		glColor3f(0.3f, 0.3f, 1.0f);
		glBegin(GL_LINE_LOOP);
		glVertex3f(-2.0f, 2.0f, -2.0f);//2
		glVertex3f(2.0f, 2.0f, -2.0f);//3
		glVertex3f(2.0f, 2.0f, 2.0f);//1		
		glVertex3f(-2.0f, 2.0f, 2.0f);//4
		glEnd();
		
	}
	else if (mode == 2)
	{
		
			glPointSize(10);
			glColor3f(0.1f, 0.3f, 0.5f);
			glBegin(GL_POINTS);
			glVertex3f(-2.0f, 0.0f, -2.0f);//1
			glVertex3f(-2.0f, 0.0f, 2.0f);//2
			glVertex3f(2.0f, 0.0f, 2.0f);//3
			glVertex3f(2.0f, 0.0f, -2.0f);//4
			glEnd();
			glColor3f(1.0f, 0.2f, 0.5f);
			glBegin(GL_POINTS);
			glVertex3f(-2.0f, 0.0f, -2.0f);//1
			glVertex3f(-2.0f, 2.0f, -2.0f);//2
			glVertex3f(2.0f, 2.0f, -2.0f);//3
			glVertex3f(2.0f, 0.0f, -2.0f);//4
			glEnd();

			glColor3f(0.3f, 1.0f, 0.3f);
			glBegin(GL_POINTS);
			glVertex3f(2.0f, 0.0f, 2.0f);//1
			glVertex3f(2.0f, 2.0f, 2.0f);//2
			glVertex3f(-2.0f, 2.0f, 2.0f);//3
			glVertex3f(-2.0f, 0.0f, 2.0f);//4
			glEnd();

			glColor3f(0.3f, 0.3f, 1.0f);
			glBegin(GL_POINTS);
			glVertex3f(-2.0f, 2.0f, -2.0f);//2
			glVertex3f(2.0f, 2.0f, -2.0f);//3
			glVertex3f(2.0f, 2.0f, 2.0f);//1		
			glVertex3f(-2.0f, 2.0f, 2.0f);//4
			glEnd();
		
	}
	angle += 0.1f;

	glutSwapBuffers();
}

int main(int argc, char **argv) {


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1920, 1080);
	glutCreateWindow("Views");


	glutDisplayFunc(renderScene);
#include "stdafx.h"


#include <glut.h>
	bool mode1 = true, point = false;
	int mode = 0;//0-shaded,1-wireframe,2-points
	float a = 0.0f, b = 0.0f;
	void processNormalKeys(unsigned char key, int x, int y) {

		if (key == 27)
			exit(0);
		else if (key == 111)
		{
			a = 5.0f;
			b = 5.0f;
		}
		else if (key == 112)
		{
			a = 0.0f;
			b = 0.0f;
		}
		else if (key == 'm')
		{
			mode = 1;
		}
		else if (key == 'l')
		{
			mode = 2;

		}
		else if (key == 'z')
		{
			mode = 0;

		}
		/*else if (key == 'l')
		{
		if (point)
		point = false;
		else if (!point)
		point = true;
		}*/
	}
	void changeSize(int w, int h) {

		if (h == 0)
			h = 1;

		float ratio = w * 1.0 / h;

		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();

		glViewport(0, 0, w, h);

		gluPerspective(45.0f, ratio, 0.1f, 100.0f);

		glMatrixMode(GL_MODELVIEW);

	}

	float angle = 0.0f;

	void renderScene(void) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glLoadIdentity();

		gluLookAt(a, b, 10.0f,
			0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f);
		if (mode == 0)
		{
			//glRotatef(angle, 0.0f, 1.0f, 0.0f);
			glColor3f(0.1f, 0.3f, 0.5f);
			glBegin(GL_QUADS);
			glVertex3f(-2.0f, 0.0f, -2.0f);//1
			glVertex3f(-2.0f, 0.0f, 2.0f);//2
			glVertex3f(2.0f, 0.0f, 2.0f);//3
			glVertex3f(2.0f, 0.0f, -2.0f);//4
			glEnd();
			glColor3f(1.0f, 0.2f, 0.5f);
			glBegin(GL_QUADS);
			glVertex3f(-2.0f, 0.0f, -2.0f);//1
			glVertex3f(-2.0f, 2.0f, -2.0f);//2
			glVertex3f(2.0f, 2.0f, -2.0f);//3
			glVertex3f(2.0f, 0.0f, -2.0f);//4
			glEnd();

			glColor3f(0.3f, 1.0f, 0.3f);
			glBegin(GL_QUADS);
			glVertex3f(2.0f, 0.0f, 2.0f);//1
			glVertex3f(2.0f, 2.0f, 2.0f);//2
			glVertex3f(-2.0f, 2.0f, 2.0f);//3
			glVertex3f(-2.0f, 0.0f, 2.0f);//4
			glEnd();

			glColor3f(0.3f, 0.3f, 1.0f);
			glBegin(GL_QUADS);
			glVertex3f(-2.0f, 2.0f, -2.0f);//2
			glVertex3f(2.0f, 2.0f, -2.0f);//3
			glVertex3f(2.0f, 2.0f, 2.0f);//1		
			glVertex3f(-2.0f, 2.0f, 2.0f);//4
			glEnd();
		}
		else if (mode == 1)
		{
			glColor3f(0.1f, 0.3f, 0.5f);
			glBegin(GL_LINE_LOOP);
			glVertex3f(-2.0f, 0.0f, -2.0f);//1
			glVertex3f(-2.0f, 0.0f, 2.0f);//2
			glVertex3f(2.0f, 0.0f, 2.0f);//3
			glVertex3f(2.0f, 0.0f, -2.0f);//4
			glEnd();
			glColor3f(1.0f, 0.2f, 0.5f);
			glBegin(GL_LINE_LOOP);
			glVertex3f(-2.0f, 0.0f, -2.0f);//1
			glVertex3f(-2.0f, 2.0f, -2.0f);//2
			glVertex3f(2.0f, 2.0f, -2.0f);//3
			glVertex3f(2.0f, 0.0f, -2.0f);//4
			glEnd();

			glColor3f(0.3f, 1.0f, 0.3f);
			glBegin(GL_LINE_LOOP);
			glVertex3f(2.0f, 0.0f, 2.0f);//1
			glVertex3f(2.0f, 2.0f, 2.0f);//2
			glVertex3f(-2.0f, 2.0f, 2.0f);//3
			glVertex3f(-2.0f, 0.0f, 2.0f);//4
			glEnd();

			glColor3f(0.3f, 0.3f, 1.0f);
			glBegin(GL_LINE_LOOP);
			glVertex3f(-2.0f, 2.0f, -2.0f);//2
			glVertex3f(2.0f, 2.0f, -2.0f);//3
			glVertex3f(2.0f, 2.0f, 2.0f);//1		
			glVertex3f(-2.0f, 2.0f, 2.0f);//4
			glEnd();

		}
		else if (mode == 2)
		{

			glPointSize(10);
			glColor3f(0.1f, 0.3f, 0.5f);
			glBegin(GL_POINTS);
			glVertex3f(-2.0f, 0.0f, -2.0f);//1
			glVertex3f(-2.0f, 0.0f, 2.0f);//2
			glVertex3f(2.0f, 0.0f, 2.0f);//3
			glVertex3f(2.0f, 0.0f, -2.0f);//4
			glEnd();
			glColor3f(1.0f, 0.2f, 0.5f);
			glBegin(GL_POINTS);
			glVertex3f(-2.0f, 0.0f, -2.0f);//1
			glVertex3f(-2.0f, 2.0f, -2.0f);//2
			glVertex3f(2.0f, 2.0f, -2.0f);//3
			glVertex3f(2.0f, 0.0f, -2.0f);//4
			glEnd();

			glColor3f(0.3f, 1.0f, 0.3f);
			glBegin(GL_POINTS);
			glVertex3f(2.0f, 0.0f, 2.0f);//1
			glVertex3f(2.0f, 2.0f, 2.0f);//2
			glVertex3f(-2.0f, 2.0f, 2.0f);//3
			glVertex3f(-2.0f, 0.0f, 2.0f);//4
			glEnd();

			glColor3f(0.3f, 0.3f, 1.0f);
			glBegin(GL_POINTS);
			glVertex3f(-2.0f, 2.0f, -2.0f);//2
			glVertex3f(2.0f, 2.0f, -2.0f);//3
			glVertex3f(2.0f, 2.0f, 2.0f);//1		
			glVertex3f(-2.0f, 2.0f, 2.0f);//4
			glEnd();

		}
		angle += 0.1f;

		glutSwapBuffers();
	}

	int main(int argc, char **argv) {


		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
		glutInitWindowPosition(100, 100);
		glutInitWindowSize(1920, 1080);
		glutCreateWindow("Views");


		glutDisplayFunc(renderScene);
		glutReshapeFunc(changeSize);
		glutIdleFunc(renderScene);

		glutKeyboardFunc(processNormalKeys);

		glutMainLoop();

		return 1;
	}
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(processNormalKeys);

	glutMainLoop();

	return 1;
}