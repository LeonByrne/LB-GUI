#include "LB/LB.hpp"

#include <memory>

int main()
{
  init();

  LBwindow test;

  Label *widget = new Label("test");

  widget->setPos(vec2(300.0f));
  widget->setSize(vec2(50.0f));
  test.addWidget(widget);


  test.setVisible(true);

  // test.setVisible(false);

  while(true)
  {
    glfwPollEvents();
  }

}