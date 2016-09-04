#include <GL/glut.h>

static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;

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
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	    VerticalLine();
		HorizontalLine();
	glEnd();
	glFlush();
}

void Initialize()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WINDOW_WIDTH / 2, WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2, -200, 200);
	glMatrixMode(GL_MODELVIEW);
	//glTranslatef(50.0, -50.0, 0.0); // x,y,z
	glScalef(0.9, 0.9, 1.0); //scale x,y,z
	glRotatef(15, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv)
{
	//Инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //GLUT_SINGLE статическое изображение, нет анимации
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Lesson 2");
	glutDisplayFunc(Draw);
	Initialize();
	glutMainLoop();
	return 1;
}