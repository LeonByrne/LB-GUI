#pragma once

#include <memory>
#include <glm/glm.hpp>
using namespace glm;

class Widget
{
private:
	/* data */

protected:
	vec2 minSize;
	vec2 maxSize;

public:
	// These are manipulated by their containers freely, best left public for this
	int x, y;
	int width, height;

	// Background colour
	vec4 colour;

public:
	Widget(/* args */);
	~Widget();

	virtual void draw();
};