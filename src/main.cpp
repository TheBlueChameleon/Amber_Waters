#include <iostream>

#include "gfxSystem.hpp"

int main () {
  std::cout << "runtime." << std::endl;
  
  initDisplay("title");
  
  std::cout << loadImageToStore("./gfx/frame01.png") << std::endl;
  std::cout << loadImageToStore("./gfx/frame02.png") << std::endl;
  std::cout << loadImageToStore("./gfx/frame03.png") << std::endl;
  std::cout << loadImageToStore("./gfx/frame04.png") << std::endl;
  std::cout << loadImageToStore("./gfx/frame05.png") << std::endl;
  //std::cout << loadImageToStore("./gfx/sea01.png") << std::endl;
  
  putImage (0, 10, 10);
  putImage (2, 60, 10);
  showImage(4, -10, 100);
  
  std::cout << "done" << std::endl;
  return 0;
}
