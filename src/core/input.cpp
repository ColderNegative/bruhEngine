#include "src/render/window.hpp"
#include <functional>
#include <iostream>
#include "src/core/input.hpp"
#include "include/glad.h"
#include "lib/glfw3.h"

namespace core {

void Input::init() {
    auto& window = render::Window::get_instance();
    glfwSetKeyCallback(window.m_pwindow, key_callback);
}

void Input::set_cursor_mode(CursorMode mode) {
  auto &window = render::Window::get_instance();
  switch (mode) {
      case unlimited:
        glfwSetInputMode(window.m_pwindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        break;
      case limited:
        glfwSetInputMode(window.m_pwindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        break;
      default:
        break;
  }
}

void Input::add_key_func(Key key, std::function<void()> func) {
    m_key_func_table.insert_or_assign(key, func);
}

Key Input::get_glfw_key(int key) {
    switch (key) {
        case GLFW_KEY_ESCAPE:
            return ESC;
        default:
            std::cout << "err::core::input::invald key \n";
            exit(-1);
    }
}

void core::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    auto& input = Input::get_instance();
    auto func = input.get_key_func(Input::get_glfw_key(key));
    func();
}

}