#include "Widget.hpp"

#include <GL/gl.h>

Widget::Widget() : minSize(-INFINITY), maxSize(INFINITY)
{

}

Widget::~Widget()
{

}

/**
 * @brief Try to set it to the specified size, fails if outside min/max sizes
 * 
 * @param size 
 * @return vec2 The size it is actually set to
 */
vec2 Widget::setSize(const vec2 &size)
{
	if(size.x > maxSize.x)
	{
		this->size.x = maxSize.x;
	} else if(size.x < minSize.x)
	{
		this->size.x = minSize.x;
	} else
	{
		this->size.x = size.x;
	}

	if(size.y > maxSize.y)
	{
		this->size.y = maxSize.y;
	} else if(size.y < minSize.y)
	{
		this->size.y = minSize.y;
	} else
	{
		this->size.y = size.y;
	}

	return this->size;
}

void Widget::setPos(const vec2 &pos)
{
	this->pos = pos;
}

void Widget::draw()
{
	glViewport(pos.x, pos.y, size.x, size.y);
	glScissor(pos.x, pos.y, size.x, size.y);

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}