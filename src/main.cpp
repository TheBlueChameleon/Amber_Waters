// ========================================================================== //
// dependencies

// STL
#include <iostream>

#include <vector>
#include <string>

// own
#include "unittests.hpp"
#include "gfxSystem.hpp"

// ========================================================================== //
// proc

int main () {
//   unittest_gfxSystem();
//   unittest_Animation();
  
  initDisplay("foo bar");
  std::cout << keycode::KC_F2 << std::endl;
  
  return 0;
}
