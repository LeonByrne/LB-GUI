#pragma once

#include <GLFW/glfw3.h>
#include "../Input/handlers.hpp"
#include "../Widgets/Widget.hpp"
#include "../Container/Container.hpp"

#include <thread>
#include <vector>
#include <memory>

class LBwindow : keyhandler, mouseHandler, public Container
{
private:
  /* data */
  GLFWwindow *window;
  float width, height;

  std::thread renderThread;
  float fpsTarget = 30;
  bool visible = false;

  void draw();

public:
  LBwindow();
  ~LBwindow();

  void setVisible(bool visible);

  void resize(int width, int height);

  // Overidden functions
  virtual void keyPressed(int key);
  virtual void keyReleased(int key);
  virtual void keyHeld(int key);

  virtual void mouseClick(int button, double xPos, double yPos);
  virtual void mouseReleased(int button, double xPos, double yPos);
  virtual void mouseMoved(double xPos, double yPos);
  virtual void mouseScroll(double xPos, double yPos);
};
