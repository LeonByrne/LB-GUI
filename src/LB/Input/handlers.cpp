#include "handlers.hpp"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  keyhandler *handler = (keyhandler *) glfwGetWindowUserPointer(window);

  // No handler assigned
  // TODO possibly log this since it would be an error
  if(handler == nullptr)
  {
    return;
  }

  if(action == GLFW_PRESS)
  {
    handler->keyPressed(key);
  } else if(action == GLFW_RELEASE)
  {
    handler->keyReleased(key);
  } else if(action == GLFW_REPEAT)
  {
    handler->keyHeld(key);
  }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
  mouseHandler *handler = (mouseHandler *) glfwGetWindowUserPointer(window);

  // No handler assigned
  // TODO possibly log this since it would be an error
  if(handler == nullptr)
  {
    return;
  }

  handler->mouseMoved(xpos, ypos);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
  mouseHandler *handler = (mouseHandler *) glfwGetWindowUserPointer(window);

  // No handler assigned
  // TODO possibly log this since it would be an error
  if(handler == nullptr)
  {
    return;
  }

  double xPos, yPos;
  glfwGetCursorPos(window, &xPos, &yPos);

  if(action == GLFW_PRESS)
  {
    handler->mouseClick(button, xPos, yPos);
  } else if(action == GLFW_RELEASE)
  {
    handler->mouseReleased(button, xPos, yPos);
  }
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
  mouseHandler *handler = (mouseHandler *) glfwGetWindowUserPointer(window);

  // No handler assigned
  // TODO possibly log this since it would be an error
  if(handler == nullptr)
  {
    return;
  }

  handler->mouseScroll(xoffset, yoffset);  
}
