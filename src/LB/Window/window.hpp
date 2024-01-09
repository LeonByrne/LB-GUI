#pragma once

#include <GLFW/glfw3.h>
#include "../Input/handlers.hpp"

class LBwindow : keyhandler
{
private:
  /* data */
  GLFWwindow *window;

public:
  LBwindow();
  ~LBwindow();

  // Overidden functions
  virtual void keyPressed(int key);
  virtual void keyReleased(int key);
  virtual void keyHeld(int key);

  // virtual void mouseClick(int button, double xPos, double yPos);
  // virtual void mouseReleased(int button, double xPos, double yPos);
  // virtual void mouseMoved(double xPos, double yPos);
  // virtual void mouseScroll(double xPos, double yPos);
};
