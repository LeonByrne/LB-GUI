#include "Widget.hpp"

#include <GL/gl.h>

Widget::Widget() : minSize(-INFINITY), maxSize(INFINITY)
{

}

Widget::~Widget()
{

}

void Widget::draw()
{
	glViewport(x, y, width, height);
	glScissor(x, y, width, height);

	glClearColor(colour.w, colour.x, colour.y, colour.z);
	glClear(GL_COLOR_BUFFER_BIT);
}


