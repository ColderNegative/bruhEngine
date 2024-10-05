#include "src/render/window.hpp"
#include <iostream>

namespace render
{

  void Window::init(char *name, int sw, int sh)
  {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    this->m_pwindow = glfwCreateWindow(sw, sh, name, NULL, NULL);
    if (this->m_pwindow == NULL)
    {
      std::cout << "err::render::m_pwindow::glfw | Failed to create window"
                << std::endl;
      glfwTerminate();
      exit(-1);
    }
    glfwMakeContextCurrent(this->m_pwindow);
    glfwSetFramebufferSizeCallback(this->m_pwindow, [](GLFWwindow *p_window, int height, int width)
                                   { glViewport(0, 0, width, height); });

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      std::cout << "err::render::m_pwindow::glad | Failed to initialize GLAD"
                << std::endl;
      exit(-1);
    }
  }

  void Window::draw()
  {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(this->m_pwindow);
    glfwPollEvents();
  }

  void Window::poll()
  {
    if (m_should_close == false)
      m_should_close = glfwWindowShouldClose(this->m_pwindow);
  }

}