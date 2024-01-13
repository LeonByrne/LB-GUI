#pragma once

#include <memory>
#include <glm/glm.hpp>
using namespace glm;

class Widget
{
private:
	/* data */
	
	// The centre of it.
	vec2 pos;
	vec2 size;

	vec2 minSize;
	vec2 maxSize;

public:
	Widget(/* args */);

	~Widget();

	// makes a copy of the widget.
	virtual Widget* copy() = 0;

	virtual void draw();

	vec2 setSize(const vec2 &size);
	void setPos(const vec2 &pos);
};