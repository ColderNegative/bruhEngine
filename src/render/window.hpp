#pragma once
#include "../templates/singleton.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace render {
class Window : public templates::Singleton<Window> {
public:
  GLFWwindow *m_pwindow;
  unsigned int m_scr_width;
  unsigned int m_scr_height;
  bool m_should_close;

  void init(char *name, int sw, int sh);
  void poll();
  void draw();
};
