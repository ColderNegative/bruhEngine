#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace core {
  class Input {
    protected:
      static Input* input_;

    public:
      void add_key();
      void proccess_input();
      static Input* get_instance(GLFWwindow* window);
      static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    
    private:
      GLFWwindow* window;
  };
}
