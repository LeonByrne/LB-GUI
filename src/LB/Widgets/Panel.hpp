#pragma once

#include "Widget.hpp"

#include "../Container/Container.hpp"

#include <vector>

class Panel : public Widget, public Container
{
private:
	/* data */
public:
	Panel(/* args */);
	~Panel();

	virtual void draw();
};

