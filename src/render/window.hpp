#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace render{
  class Window {
    protected:
      static Window* window_;

    public:
      GLFWwindow* window;

      static Window* get_instance();
      void loop();

    private:
      unsigned int scr_width = 800;
      unsigned int scr_height = 600;

      void framebuffer_size_callback(GLFWwindow* window, int width, int height);
  };
}

