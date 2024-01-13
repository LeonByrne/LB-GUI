#pragma once

#include <GLFW/glfw3.h>
#include "../Input/handlers.hpp"
#include "../Widgets/Widget.hpp"

#include <thread>
#include <vector>
#include <memory>

class LBwindow : keyhandler, mouseHandler
{
private:
  /* data */
  GLFWwindow *window;

  std::thread renderThread;
  float fpsTarget = 30;
  bool visible = false;

  std::vector<std::shared_ptr<Widget>> widgets;

  void draw();

public:
  LBwindow();
  ~LBwindow();

  void setVisible(bool visible);
  std::shared_ptr<Widget> addWidget(Widget &widget);
  std::shared_ptr<Widget> addWidget(Widget *widget);
  std::shared_ptr<Widget> addWidget(std::shared_ptr<Widget> &widget);

  // Overidden functions
  virtual void keyPressed(int key);
  virtual void keyReleased(int key);
  virtual void keyHeld(int key);

  virtual void mouseClick(int button, double xPos, double yPos);
  virtual void mouseReleased(int button, double xPos, double yPos);
  virtual void mouseMoved(double xPos, double yPos);
  virtual void mouseScroll(double xPos, double yPos);
};
