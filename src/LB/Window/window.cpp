#include "window.hpp"

#include "../Input/handlers.hpp"

#include <iostream>

LBwindow::LBwindow(/* args */)
{
  // Set window hints to make the window invisible
  glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

  window = glfwCreateWindow(800, 800, "todo", nullptr, nullptr);

  glfwSetCursorPosCallback(window, cursor_position_callback);
  glfwSetMouseButtonCallback(window, mouse_button_callback);
  glfwSetKeyCallback(window, key_callback);

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

/**
 * @brief Adds a copy of a Widget to the window and returns a pointer to the copy
 * 
 * @param widget The widget you wish to add
 * @return std::shared_ptr<Widget> pointer to the widget for further modification and/or usage
 */
std::shared_ptr<Widget> LBwindow::addWidget(Widget &widget)
{
  std::shared_ptr<Widget> ptr(widget.copy());
  widgets.push_back(ptr);

  return ptr;
}

/**
 * @brief Widget must create via new, must not be used elsewhere except through returned value
 * 
 * @param widget The widget you wish to add
 * @return std::shared_ptr<Widget> pointer to the widget for further modification and/or usage
 */
std::shared_ptr<Widget> LBwindow::addWidget(Widget *widget)
{
  std::shared_ptr<Widget> ptr(widget);
  widgets.push_back(ptr);

  return ptr;
}

/**
 * @brief Adds widget to the window
 * 
 * @param widget The widget you wish to add
 * @return std::shared_ptr<Widget> pointer to the widget for further modification and/or usage
 */
std::shared_ptr<Widget> LBwindow::addWidget(std::shared_ptr<Widget> &widget)
{
  widgets.push_back(widget);
  return widget;
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

    // Test

    glEnable(GL_SCISSOR_TEST);
    glScissor(100, 100, 100, 100);
		glClearColor(0.4f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // In this section we drwa the widgets within
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