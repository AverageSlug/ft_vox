#include "ft_vox.hpp"

float	lx = 0.0f, ly = 0.0f, lz = 0.0f;
float	x = 0.0f, y = 16.0f, z = 0.0f;
float	fraction = 0.1f;
int		speed;
float	angleLR = 0.0f, angleUD = 0.0f;
int		width = 0, height = 0;
bool	keys[4] = {false, false, false, false};

void	display()
{
	glutSwapBuffers();
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x, y, z, x+lx, y+ly, z+lz, 0.0f, 1.0f, 0.0f);
	for (int k = -16; k < 16; k++)
		for (int j = 0; j < 8; j++)
			for (int i = -16; i < 16; i++)
			{
				glPushMatrix();
					glTranslatef(i,j,k);
					glColor3f(0,255,0);
					glutSolidCube(1);
				glPopMatrix();
			}
	glFlush();
}

void	key_presses(unsigned char key, int xx, int yy)
{
	(void)xx;
	(void)yy;

	if (key == 'w' && !speed)
		speed = 1;
	if (key == 'q')
		keys[0] = true;
	if (key == 'd')
		keys[1] = true;
	if (key == 'z')
		keys[2] = true;
	if (key == 's')
		keys[3] = true;
	if (key == 27)
		exit(0);
	glutPostRedisplay();
}

void	key_releases(unsigned char key, int xx, int yy)
{
	(void)xx;
	(void)yy;
	if (key == 'w')
		speed = 0;
	if (key == 'q')
		keys[0] = false;
	if (key == 'd')
		keys[1] = false;
	if (key == 'z')
		keys[2] = false;
	if (key == 's')
		keys[3] = false;
	glutPostRedisplay();
}

void	move_camera(int xx, int yy)
{
	angleLR += 0.0005f * float(xx - width / 2);
	angleUD += 0.0005f * float(yy - height / 2);
	if (angleUD > 1.5)
		angleUD = 1.5;
	if (angleUD < -1.5)
		angleUD = -1.5;
	lx = cos(angleUD) * sin(angleLR);
	ly = -sin(angleUD);
	lz = cos(angleUD) * -cos(angleLR);
	glutPostRedisplay();
}

void	idle()
{
	if (speed == 1)
	{
		fraction = abs(fraction - 2.0f) + 0.1f;
		speed = 2;
	}
	if (((keys[0] ^ keys[1]) && (keys[2] || keys[3])) || ((keys[0] || keys[1]) && (keys[2] ^ keys[3])))
		fraction /= 1.41f;
	if (keys[0])
	{
		x += lz * fraction;
		z -= lx * fraction;
	}
	if (keys[1])
	{
		x -= lz * fraction;
		z += lx * fraction;
	}
	if (keys[2])
	{
		x += lx * fraction;
		y += ly * fraction;
		z += lz * fraction;
	}
	if (keys[3])
	{
		x -= lx * fraction;
		y -= ly * fraction;
		z -= lz * fraction;
	}
	if (((keys[0] ^ keys[1]) && (keys[2] || keys[3])) || ((keys[0] || keys[1]) && (keys[2] ^ keys[3])))
		fraction *= 1.41f;
	glutWarpPointer(width / 2, height / 2);
}

int		main(int argc, char** argv)
{
	glutInit(&argc, argv);
	width = glutGet(GLUT_SCREEN_WIDTH), height = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("42");
	glutFullScreen();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0f,(GLfloat)width/(GLfloat)height, 1.0f, 320.0f);
	glMatrixMode(GL_MODELVIEW);
	glutDisplayFunc(display);
	glutPassiveMotionFunc(move_camera);
	glutKeyboardFunc(key_presses);
	glutKeyboardUpFunc(key_releases);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glutIdleFunc(idle);
	glutMainLoop();
}
