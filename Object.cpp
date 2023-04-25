#include "Object.hpp"

Object::Object(int text_ID, int x, int y, int z, int id)
{
	_texture_ID = text_ID;
	_pos.x = x;
	_pos.y = y;
	_pos.z = z;
	_id = id;
}

Object::~Object()
{	
}
