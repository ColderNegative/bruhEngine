#include "render/window.hpp"
#include "core/input.hpp"
#include <iostream>
#include <ostream>

void esc_key_func() {
    auto& window = render::Window::get_instance();
    window.m_should_close = true;
}

int main() {

  std::cout << "The bruhEngine" << std::endl;

  auto& window = render::Window::get_instance();
  auto& input = core::Input::get_instance();

  window.init("bruhEngine", 1280, 720);
  input.init();

  while (!window.m_should_close) {
      input.set_cursor_mode(core::limited);
      input.add_key_func(core::ESC, &esc_key_func);
      window.draw();
      window.poll();
  }

  return 0;
}
