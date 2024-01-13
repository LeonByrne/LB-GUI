#pragma once

#include "Widget.hpp"

class Canvas : public Widget
{
private:
	/* data */
public:
	Canvas(/* args */);
	~Canvas();

	virtual void draw();
};

