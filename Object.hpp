#ifndef OBJECT_HPP
# define OBJECT_HPP

# include "ft_vox.hpp"

typedef struct	s_pos
{
	int			x;
	int			y;
	int			z;
}				t_pos;

class Object
{
private:
	t_pos	_pos;
	int		_texture_ID;
	int		_id;

protected:
	Object();
	Object &operator = (Object const &origin);
	Object(Object const &srcs);

public:
	Object(int texture_ID, int x, int y, int z, int id);

	~Object();
};

std::ostream& operator<<( std::ostream& out, const Object& in );

#endif