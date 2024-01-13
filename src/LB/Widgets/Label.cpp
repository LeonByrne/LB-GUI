#include "Label.hpp"

Label::Label(std::string text)
{
	this->text = text;
}

Label::~Label()
{
}

Label * Label::copy()
{
	Label *label = new Label(text);

	// TODO copy any other things that need to be copied

	return label;
}

void Label::draw()
{
	Widget::draw();
}