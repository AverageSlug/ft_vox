#include "ft_vox.hpp"

float	lx = 0.0f, ly = 0.0f, lz = -1.0f;
float	x = 0.0f, y = 1.0f, z = 0.0f;
float	angleLR = 0.0f, angleUD = 0.0f;

void	display()
{
	glutSwapBuffers();
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, y, z, x+lx, y+ly, z+lz, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
		glTranslatef(0,0,-10);
		glColor3f(0,255,0);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(10,0,0);
		glColor3f(255,0,0);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,0,10);
		glColor3f(0,0,255);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,-10,0);
		glColor3f(255,255,0);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0,10,0);
		glColor3f(0,255,255);
		glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-10,0,0);
		glColor3f(255,0,255);
		glutSolidCube(1);
	glPopMatrix();
	glFlush();
}

void	key_presses(unsigned char key, int xx, int yy)
{
	(void)xx;
	(void)yy;
	if (key == 27)
		exit(0);
}

void	arrow_keys(int key, int xx, int yy)
{
	(void)xx;
	(void)yy;
	float	fraction = 0.1f;

	switch (key) {
		case GLUT_KEY_LEFT :
			x += lz * fraction;
			z -= lx * fraction;
			break;
		case GLUT_KEY_RIGHT :
			x -= lz * fraction;
			z += lx * fraction;
			break;
		case GLUT_KEY_UP :
			x += lx * fraction;
			y += ly * fraction;
			z += lz * fraction;
			break;
		case GLUT_KEY_DOWN :
			x -= lx * fraction;
			y -= ly * fraction;
			z -= lz * fraction;
			break;
	}
}

void	move_camera(int xx, int yy)
{
	angleLR += 0.0005f * float(xx - 960);
	angleUD += 0.0005f * float(yy - 540);
	if (angleUD > 1.5)
		angleUD = 1.5;
	if (angleUD < -1.5)
		angleUD = -1.5;
	lx = cos(angleUD) * sin(angleLR);
	ly = -sin(angleUD);
	lz = cos(angleUD) * -cos(angleLR);
}

void	idle()
{
	glutWarpPointer(960, 540);
	glutPostRedisplay();
}

int		main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(16, 9);
	glutCreateWindow("42");
	glutFullScreen();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0f,(GLfloat)1920/(GLfloat)1080, 1.0f, 320.0f);
	glMatrixMode(GL_MODELVIEW);
	glutDisplayFunc(display);
	glutSpecialFunc(arrow_keys);
	glutPassiveMotionFunc(move_camera);
	glutKeyboardFunc(key_presses);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glutIdleFunc(idle);
	glutMainLoop();
}
