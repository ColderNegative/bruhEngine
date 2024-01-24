#include <iostream>
#include <stdio.h>

#include "render/window.hpp"

int main() {

  std::cout << "The bruhEngine" << std::endl;

  render::Window window;

  window.loop();

  return 0;
}
