#include "Container.hpp"

#include "../Widgets/Widget.hpp"

Container::Container(/* args */)
{
}

Container::~Container()
{
}

// /**
//  * @brief Adds a copy of a Widget to the window and returns a pointer to the copy
//  * 
//  * @param widget The widget you wish to add
//  * @return std::shared_ptr<Widget> pointer to the widget for further modification and/or usage
//  */
// std::shared_ptr<Widget> Container::addWidget(Widget &widget)
// {
//   std::shared_ptr<Widget> ptr(new Widget(widget));
//   widgets.push_back(ptr);

//   return ptr;
// }

/**
 * @brief Widget must create via new, must not be used elsewhere except through returned value
 * 
 * @param widget The widget you wish to add
 * @return std::shared_ptr<Widget> pointer to the widget for further modification and/or usage
 */
void Container::addWidget(Widget *widget)
{
  widgets.push_back(widget);
}

// /**
//  * @brief Adds widget to the window
//  * 
//  * @param widget The widget you wish to add
//  * @return std::shared_ptr<Widget> pointer to the widget for further modification and/or usage
//  */
// std::shared_ptr<Widget> Container::addWidget(std::shared_ptr<Widget> &widget)
// {
//   widgets.push_back(widget);
//   return widget;
// }


void Container::removeWidget(const Widget *widget)
{
  for(auto it = widgets.begin(); it != widgets.end(); it++)
  {
    if(*it == widget)
    {
      widgets.erase(it);
      return;
    }
  }

}

