#pragma once

#include <string>

#include "Widget.hpp"

class Label : public Widget
{
private:
	/* data */
	std::string text;

public:
	Label(std::string text);
	~Label();

	virtual Label * copy();

	void draw() override;
};

