#pragma once
#include <GLFW/glfw3.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class keyhandler
{
private:
  /* data */
public:
  virtual void keyPressed(int key) = 0;
  virtual void keyReleased(int key) = 0;
  virtual void keyHeld(int key) = 0;
};

class mouseHandler
{
private:
  /* data */
public:
  virtual void mouseClick(int button, double xPos, double yPos) = 0;
  virtual void mouseReleased(int button, double xPos, double yPos) = 0;
  virtual void mouseMoved(double xPos, double yPos) = 0;
  virtual void mouseScroll(double xPos, double yPos) = 0;
};