#include "window.hpp"

#include "../Input/handlers.hpp"

#include <iostream>

LBwindow::LBwindow(/* args */)
{
  // Set window hints to make the window invisible
  glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

  window = glfwCreateWindow(800, 800, "todo", nullptr, nullptr);
  width = 800;
  height = 800;

  glfwSetCursorPosCallback(window, cursor_position_callback);
  glfwSetMouseButtonCallback(window, mouse_button_callback);
  glfwSetKeyCallback(window, key_callback);
  
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  glfwSetWindowUserPointer(window, this);
}

LBwindow::~LBwindow()
{
  if(renderThread.joinable()) renderThread.join();

  glfwDestroyWindow(window);
}

/**
 * @brief Will make the window either visible and start rendering or invisible and stop rendering
 * 
 * @param visible 
 */
void LBwindow::setVisible(bool visible)
{
  // No action if already visible/invisible
  if(this->visible == visible)
  {
    return;
  }

  this->visible = visible;

  if(visible)
  {
    glfwShowWindow(this->window);
    this->renderThread = std::thread(&LBwindow::draw, this);
  } else
  {
    renderThread.join();
    glfwHideWindow(this->window);
  }
}

void LBwindow::resize(int width, int height)
{
  this->width = width;
  this->height = height;

  std::cout << "width: " << width << ", height: " << height << std::endl;
}

/**
 * @brief Draws the window and the widgets within, should not be called by the user at all.
 * 
 */
void LBwindow::draw()
{
  glfwMakeContextCurrent(this->window);

  while(this->visible)
  {
    double startTime = glfwGetTime();

    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);

    glScissor(200, 200, 100, 100);
		glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_SCISSOR_TEST);
    // In this section we draw the widgets within
    int x = 0;
    int y = 0;
    int maxHeight = 0;
    int spacing = 5;
    std::vector<std::shared_ptr<Widget>> row;
    for(auto& widget : widgets)
    {
      if(x + widget->width > width)
      {
        x = 0;
        y += maxHeight;
        maxHeight = 0;
      }

      if(widget->height > maxHeight)
      {
        for(auto& prev : widgets)
        {
          if(prev->y == y)
          {
            prev->y += (widget->height - maxHeight) / 2;
          }
        }

        maxHeight = widget->height;
      }

      widget->x = x;
      widget->y = y + (maxHeight - widget->height) / 2;

      x += widget->width;
    }

    for(int i = 0; i < widgets.size(); i++)
    {
      widgets[i]->draw();
    }

    // std::cout << "drawing" << std::endl;

    glfwSwapBuffers(window);

    double endTime = glfwGetTime();
    double timeElapsed = endTime - startTime;
    
    std::this_thread::sleep_for(std::chrono::duration<double>((1 / fpsTarget) - timeElapsed));
  }

  // std::cout << "done";
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

void LBwindow::mouseClick(int button, double xPos, double yPos)
{

}

void LBwindow::mouseReleased(int button, double xPos, double yPos)
{

}

void LBwindow::mouseMoved(double xPos, double yPos)
{

}

void LBwindow::mouseScroll(double xPos, double yPos)
{

}