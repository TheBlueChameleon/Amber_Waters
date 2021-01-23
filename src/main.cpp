#include <iostream>

#include "GfxStore.hpp"

int main () {
  std::cout << "runtime." << std::endl;
  
  GfxStore store;
  
  std::cout << store.addImage("sea01.png") << std::endl;
  std::cout << store.addImage("sea01.png") << std::endl;
  
  store.showImage(0);
  
  std::cout << "done" << std::endl;
  return 0;
}
