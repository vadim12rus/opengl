#include <GL/glut.h>

static const int WINDOW_WIDTH = 640;
static const int WINDOW_HEIGHT = 480;

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	    glVertex2f(0.0, 0.0);
	glEnd();
	glFlush();
}

void Initialize()
{
	glClearColor(1.0, 0.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-WINDOW_WIDTH / 2, WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2, -0.5, 0.5);
}

int main(int argc, char** argv)
{
	//Инициализация
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //GLUT_SINGLE статическое изображение, нет анимации
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Lesson 1");
	glutDisplayFunc(Draw);
	Initialize();
	glutMainLoop();
	return 1;
}