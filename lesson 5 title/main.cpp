#include <GL/glut.h>
#include <cmath>
#include <string>
#include <stdlib.h>

static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;
int g_angle = 0.0;
float g_scale = 1.0;
char ang[12] = "Angle:";
char res[12] = "Angle";
char buf[5];

void VerticalLine()
{
	for (float i = -WINDOW_WIDTH / 2; i <= WINDOW_WIDTH / 2; i += 20.0)
	{
		glVertex2f(i, -WINDOW_HEIGHT / 2);
		glVertex2f(i, WINDOW_HEIGHT / 2);
	}
}

void HorizontalLine()
{
	for (float i = -WINDOW_HEIGHT / 2; i <= WINDOW_HEIGHT / 2; i += 20)
	{
		glVertex2f(-WINDOW_WIDTH / 2, i);
		glVertex2f(WINDOW_WIDTH / 2, i);
	}
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	g_angle %= 360;
	g_scale = 1.0 - abs(sin(3.14*g_angle/90.0)/sqrt(3.0)/2);
	glRotatef(g_angle, 0.0, 0.0, 1.0);
	glScalef(g_scale, g_scale, 1.0);
	glBegin(GL_LINES);
	    VerticalLine();
		HorizontalLine();
	glEnd();
	strcpy(ang, res);
	glutSetWindowTitle(strcat(ang, itoa(g_angle, buf, 10))
	);
	glPopMatrix();
	//glFlush(); //when GLUT_SINGLE
	glutSwapBuffers();
}

void Timer(int value)
{
	/*switch (value)
	{
	case 0: glColor3f(1.0, 1.0, 1.0);
		break;
	case 1: glColor3f(1.0, 0.0, 0.0);
		break;
	}*/
	glColor3f(1.0, 1.0, 1.0);
	//glRotatef(1, 0.0, 0.0, 1.0);
	glutPostRedisplay(); //Draw(); equivalent glutPostRedisplay
	glutTimerFunc(20, Timer, 0);
}

void Keyboard(unsigned char key, int x, int y) //x,y position mouse | generate ASCI code -> enter, letters, numbers, delite 
{
	switch (key)
	{
	case 'a': g_angle++;
		break;
	case 'd': g_angle--;
		break;
	}
}

void SKeyboard(int key, int x, int y) //f1-f12 , down ... | x,y position mouse
{
	switch (key)
	{
	case GLUT_KEY_LEFT: g_angle++;
		break;
	case GLUT_KEY_RIGHT: g_angle--;
		break;
	}

}

void Initialize()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WINDOW_WIDTH / 2, WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2, -200, 200); //x,y,z
	glMatrixMode(GL_MODELVIEW);
	/*glTranslatef(50.0, -50.0, 0.0); // x,y,z
	glScalef(0.9, 0.9, 1.0); //scale x,y,z
	glRotatef(15, 0.0, 0.0, 1.0); //15 degrees clockwise or -1.0  counter-clockwise */
}

int main(int argc, char** argv)
{
	//Инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //GLUT_SINGLE static image, GLUT_DOUBLE two buffers (buffer drawing and calculation of the buffer)
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Lesson 4");

	float angle = 0.0;
	glutDisplayFunc(Draw);
	glutTimerFunc(20, Timer, 0); //500 time millisec, 0 transfer values into the function 
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SKeyboard);
	Initialize();
	glutMainLoop();
	return 1;
}