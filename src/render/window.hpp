#pragma once

#include "../templates/singleton.hpp"
#include "include/glad.h"
#include "lib/glfw3.h"

namespace render {
class Window : public templates::Singleton<Window> {
public:
  GLFWwindow *m_pwindow;
  bool m_should_close;

  void init(char *name, int sw, int sh);
  void poll();
  void draw();
};
} // namespace render