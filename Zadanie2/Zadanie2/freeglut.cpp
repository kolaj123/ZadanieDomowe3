//Micha³ Miko³ajczak
#include <iostream>
#include<math.h>
#include <GL/freeglut.h>
#include<string>

const float PI = 3.14;
const int glutWindowWidth = 640;
const int glutWindowHeight = 480;

float proportion = (float)glutWindowWidth / (float)glutWindowHeight;
/* GLUT callback Handlers */
static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;
	proportion = ar;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
static void idle(void)
{
	glutPostRedisplay();
}
enum Typ{kw, ko, sz };
struct Ksztalt
{
	Typ moj;
	double pozycjaX;
	double pozycjaY;
	double kolor;
}kwadrat,kolo,szesciokat;

void DrawRectangle(void)
{
	double height = 0.5;
	double width = 0.5;

	glPushMatrix();
	glTranslated(kwadrat.pozycjaX, kwadrat.pozycjaY, 0);
	glTranslated(-2, -1.5, 0);
	glColor3d(kwadrat.kolor, 0.0, 0.0);
	glBegin(GL_POLYGON);
	{
		if (kwadrat.moj == kw)
		{
			glVertex3d(width, height, 0);
			glVertex3d(-width, height, 0);
			glVertex3d(-width, -height, 0);
			glVertex3d(width, -height, 0);
		}
		else if (kwadrat.moj == ko)
		{
				for (int i = 0; i < 360; i += 10)
				{
					double radiany;
					radiany = (i*PI) / 180;
					glVertex3d(width*cos(radiany), height*sin(radiany), 0);
				}
		}
		else if (kwadrat.moj == sz)
		{
				for (int i = 0; i < 6; i++)
				{
					glVertex2f(cos(6.28*i / 6) / 1.75, sin(6.28*i / 6) / 1.75);
				}
		}
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(kolo.pozycjaX, kolo.pozycjaY, 0);
	glTranslated(0, -1.5, 0);
	glColor3d(kolo.kolor, 0.0, 0.0);
	glBegin(GL_POLYGON);
	{
		if (kolo.moj == ko)
		{
			for (int i = 0; i < 360; i += 10)
			{
				double radiany;
				radiany = (i*PI) / 180;
				glVertex3d(width*cos(radiany), height*sin(radiany), 0);
			}
		}
		else if (kolo.moj == kw)
		{
			glVertex3d(width, height, 0);
			glVertex3d(-width, height, 0);
			glVertex3d(-width, -height, 0);
			glVertex3d(width, -height, 0);
		}
		else if (kolo.moj == sz)
		{
			for (int i = 0; i < 6; i++)
			{
				glVertex2f(cos(6.28*i / 6) / 1.75, sin(6.28*i / 6) / 1.75);
			}
		}
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(szesciokat.pozycjaX, szesciokat.pozycjaY, 0);
	glTranslated(2, -1.5, 0);
	glColor3d(szesciokat.kolor, 0.0, 0.0);
	glBegin(GL_POLYGON);
	{
		if (szesciokat.moj == sz)
		{
				for (int i = 0; i < 6; i++)
				{
					glVertex2f(cos(6.28*i / 6) / 1.75, sin(6.28*i / 6) / 1.75);
				}
		}
		else if (szesciokat.moj == ko)
		{
				for (int i = 0; i < 360; i += 10)
				{
					double radiany;
					radiany = (i*PI) / 180;
					glVertex3d(width*cos(radiany), height*sin(radiany), 0);
				}
		}
		else if (szesciokat.moj == kw)
		{
				glVertex3d(width, height, 0);
				glVertex3d(-width, height, 0);
				glVertex3d(-width, -height, 0);
				glVertex3d(width, -height, 0);
		}
	}
	glEnd();
	glPopMatrix();
}
void glKeyboardFunc(void (klawiatura)(unsigned char key, int x, int y));
void klawiatura(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
	{
				if (kwadrat.kolor == 0.0 && kolo.kolor == 0.0 && szesciokat.kolor == 0.0)
				{
					kwadrat.kolor = 1.0;
					kolo.kolor = 0.0;
					szesciokat.kolor = 0.0;
					break;
				}
				if (kolo.kolor == 1.0)
				{
					kwadrat.kolor = 1.0;
					kolo.kolor = 0.0;
					szesciokat.kolor = 0.0;
					break;
				}
				if (kwadrat.kolor == 1.0)
				{
					kwadrat.kolor = 0.0;
					kolo.kolor = 0.0;
					szesciokat.kolor = 1.0;
					break;
				}
				if (szesciokat.kolor == 1.0);
				{
					kwadrat.kolor = 0.0;
					kolo.kolor = 1.0;
					szesciokat.kolor = 0.0;
					break;
				}
	}
	case 'e':
	{
				if (kwadrat.kolor == 1.0)
				{
					kwadrat.kolor = 0.0;
					kolo.kolor = 1.0;
					szesciokat.kolor = 0.0;
					break;
				}
				else if (kolo.kolor == 1.0)
				{
					kwadrat.kolor = 0.0;
					kolo.kolor = 0.0;
					szesciokat.kolor = 1.0;
					break;
				}
				else if (szesciokat.kolor == 1.0)
				{
					kwadrat.kolor = 1.0;
					kolo.kolor = 0.0;
					szesciokat.kolor = 0.0;
					break;
				}
	}
	case 'i':
	{
				if (kolo.kolor == 1.0)
				{
					kolo.moj = kw;
					break;
				}
				else if (szesciokat.kolor == 1.0)
				{
					szesciokat.moj = kw;
					break;
				}
				else if (kwadrat.kolor == 1.0)
				{
					kwadrat.moj = kw;
					break;
				}
	}
	case 'o':
	{
				if (kolo.kolor == 1.0)
				{
					kolo.moj = ko;
					break;
				}
				else if (szesciokat.kolor == 1.0)
				{
					szesciokat.moj = ko;
					break;
				}
				else if (kwadrat.kolor == 1.0)
				{
					kwadrat.moj = ko;
					break;
				}
	}
	case 'p':
	{
				if (kolo.kolor == 1.0)
				{
					kolo.moj = sz;
					break;
				}
				else if (szesciokat.kolor == 1.0)
				{
					szesciokat.moj = sz;
					break;
				}
				else if (kwadrat.kolor == 1.0)
				{
					kwadrat.moj = sz;
					break;
				}
	}
	case 'w':
	{
				if (kwadrat.kolor == 1.0)
				{
					kwadrat.pozycjaY += 0.1;
					break;
				}
				else if (kolo.kolor == 1.0)
				{
					kolo.pozycjaY += 0.1;
					break;
				}
				else if (szesciokat.kolor == 1.0)
				{
					szesciokat.pozycjaY += 0.1;
					break;
				}
	}
	case 's':
	{
				if (kwadrat.kolor == 1.0)
				{
					kwadrat.pozycjaY -= 0.1;
					break;
				}
				else if (kolo.kolor == 1.0)
				{
					kolo.pozycjaY -= 0.1;
					break;
				}
				else if (szesciokat.kolor == 1.0)
				{
					szesciokat.pozycjaY -= 0.1;
					break;
				}
	}
	case 'a':
	{
				if (kwadrat.kolor == 1.0)
				{
					kwadrat.pozycjaX -= 0.1;
					break;
				}
				else if (kolo.kolor == 1.0)
				{
					kolo.pozycjaX -= 0.1;
					break;
				}
				else if (szesciokat.kolor == 1.0)
				{
					szesciokat.pozycjaX -= 0.1;
					break;
				}			
	}
	case 'd':
	{
				if (kwadrat.kolor == 1.0)
				{
					kwadrat.pozycjaX += 0.1;
					break;
				}
				else if (kolo.kolor == 1.0)
				{
					kolo.pozycjaX += 0.1;
					break;
				}
				else if (szesciokat.kolor == 1.0)
				{
					szesciokat.pozycjaX += 0.1;
					break;
				}
	}
	}
}
static void display(void)
{
	// wyczyszenie sceny
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	DrawRectangle();
	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	kwadrat.kolor = 0.0; kolo.kolor = 0.0; szesciokat.kolor = 0.0;
	kwadrat.moj = kw; kolo.moj = kw; szesciokat.moj = kw;

	printf("Hello openGL world!");
	glutInitWindowSize(glutWindowWidth, glutWindowHeight);
	glutInitWindowPosition(40, 40);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);
	glutCreateWindow("OpenGLUT Shapes");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(klawiatura);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glutMainLoop();

	return 0;
}
