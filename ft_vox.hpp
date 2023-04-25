#ifndef FT_VOX_H
# define FT_VOX_H

#include <GL/freeglut.h>

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_vertex
{
	float		x;
	float		y;
	float		z;
}				t_vertex;

typedef struct		s_face
{
	int				*points;
	int				len;
	struct s_face	*next;
}					t_face;

#endif
