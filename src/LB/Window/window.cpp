#include "window.hpp"

#include "../Input/handlers.hpp"

#include <iostream>

LBwindow::LBwindow(/* args */)
{
  window = glfwCreateWindow(100, 100, "todo", nullptr, nullptr);

  glfwSetCursorPosCallback(window, cursor_position_callback);
  glfwSetMouseButtonCallback(window, mouse_button_callback);
  glfwSetKeyCallback(window, key_callback);

  glfwSetWindowUserPointer(window, this);
}

LBwindow::~LBwindow()
{
  glfwDestroyWindow(window);
}

void LBwindow::keyPressed(int key)
{
  std::cout << key << std::endl;
}

void LBwindow::keyReleased(int key)
{

}

void LBwindow::keyHeld(int key)
{

}