#include "LB/LB.hpp"

#include <memory>

int main()
{
  init();

  LBwindow test;

  Panel *panel1 = new Panel;
  Panel *panel2 = new Panel;

  // widget->setPos(vec2(300.0f));
  // widget->setSize(vec2(50.0f));

  panel1->width = 50;
  panel1->height = 50;

  panel2->width = 50;
  panel2->height = 100;

  panel1->colour = vec4(0.5f);

  test.addWidget(panel1);
  test.addWidget(panel2);


  test.setVisible(true);

  // test.setVisible(false);

  while(true)
  {
    glfwPollEvents();
  }

}