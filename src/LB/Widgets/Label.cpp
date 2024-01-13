#include "Label.hpp"

Label::Label(std::string text)
{
	this->text = text;
}

Label::~Label()
{
}

void Label::draw()
{
	Widget::draw();
}