#pragma once
#include <functional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace core {
  class Input {
    enum KeyState {
      press,
      release,
      repeat,
    };

    enum CursorMode {
      limited,
      unlimited,
    };

    struct CursorPos {
      double xpos;
      double ypos;
    };

    protected:
      static Input* input_;

    public:
      static Input* get_instance(GLFWwindow* window);
      KeyState get_state(char* key_val);
      void add_callback(char* key_val, std::function<void()> key_func);
      void set_cursor_mode(CursorMode mode);
      CursorPos get_cursor_position();
  };

  void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
  void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
}
