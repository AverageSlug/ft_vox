#include "ft_vox.hpp"

float	angle = 0.0;
float	lx = 0.0f, lz = -1.0f;
float	x = 0.0f, z = 0.0f;

void	display()
{
	glutSwapBuffers();
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, 1.0f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
		glTranslatef(0.0,0.0,-10);
		glColor3f(0,255,0);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(1.0,0.0,-10);
		glColor3f(255,0,0);
		glutSolidCube(1);
	glPopMatrix();
	glFlush();
}

void	key_presses(unsigned char key, int x, int y)
{
	(void)x;
	(void)y;
	if (key == 27)
		exit(0);
}

void	arrow_keys(int key, int x, int y)
{
	(void)x;
	(void)y;
	float	fraction = 0.1f;

	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			z -= lz * fraction;
			break;
	}
}

void	idle()
{
	glutPostRedisplay();
}

int		main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(192, 108);
	glutCreateWindow("42");
	// glutFullScreen();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0f,(GLfloat)1920/(GLfloat)1080, 1.0f, 320.0f);
	glMatrixMode(GL_MODELVIEW);
	glutDisplayFunc(display);
	glutKeyboardFunc(key_presses);
	glutSpecialFunc(arrow_keys);
	glEnable(GL_DEPTH_TEST);
	glutIdleFunc(idle);
	glutMainLoop();
}
