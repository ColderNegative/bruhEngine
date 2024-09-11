#include "window.hpp"
#include "GLFW/glfw3.h"
#include <iostream>

using namespace render;

void Window::init(char *name, int sw, int sh) {
  m_scr_width = sw;
  m_scr_height = sh;

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  m_pwindow = glfwCreateWindow(m_scr_width, m_scr_height, name, NULL, NULL);
  if (m_pwindow == NULL) {
    std::cout << "err::render::m_pwindow::glfw | Failed to create window"
              << std::endl;
    glfwTerminate();
    exit(-1);
  }
  glfwMakeContextCurrent(m_pwindow);
  glfwSetFramebufferSizeCallback(m_pwindow, [&this](GLFWWindow m_pwindow, int width, int height) {
    glViewport(0, 0, width, height);
    this.width = width;
    this.height = height;
  });

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "err::render::m_pwindow::glad | Failed to initialize GLAD"
              << std::endl;
    exit(-1);
  }
}

void Window::draw() {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  glfwSwapBuffers(m_pwindow);
  glfwPollEvents();
}

void Window::poll() {
    if (m_should_close == false)
        m_should_close = glfwWindowShouldClose(m_pwindow);
}

