#pragma once

class Widget;

#include <vector>
#include <memory>

class Container
{
protected:
	/* data */
	std::vector<Widget *> widgets;

public:
	Container(/* args */);
	~Container();

  // std::shared_ptr<Widget> addWidget(Widget &widget);
  void addWidget(Widget *widget);
  // std::shared_ptr<Widget> addWidget(std::shared_ptr<Widget> &widget);

	// void removeWidget(const Widget &widget);
	void removeWidget(const Widget *widget);
};

