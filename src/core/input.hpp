#pragma once

#include <functional>
#include <map>

#include "src/templates/singleton.hpp"

namespace core {
enum Key {
  A,
  B,
  C,
  D,
  E,
  F,
  G,
  H,
  I,
  J,
  K,
  L,
  M,
  N,
  O,
  P,
  Q,
  R,
  S,
  T,
  W,
  U,
  X,
  Y,
  Z,
  CAPS,
  SHIFT,
  CRTL,
  ALT,
  SUPER,
  BACK,
  TAB,
  ESC,
};

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

class Input : public templates::Singleton<Input> {
public:
  void init();
  void set_cursor_mode(CursorMode mode);
  void poll_events() { return glfwPollEvents(); }
  void add_key_func(Key key, std::function<void()>);
  std::function<void()> get_key_func(Key key) { return m_key_func_table[key]; };
  CursorPos get_cursor_position();
  static Key get_glfw_key(int key);

private:
  std::map<Key, std::function<void()>> m_key_func_table;
};
void key_callback(GLFWwindow *window, int key, int scancode, int action,
                  int mods);
} // namespace core
