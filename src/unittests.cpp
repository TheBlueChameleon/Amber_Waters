// ========================================================================== //
// dependencies

// STL
#include <exception>
#include <cassert>

#include <iostream>

#include <vector>
#include <string>

// own
#include "gfxSystem.hpp"
#include "Animation.hpp"

// ========================================================================== //

void unittest_gfxSystem() {
  std::vector<std::string> dataFiles = {
    "./gfx-unittest/sea01.png",
    "./gfx-unittest/sea02.png",
    "./gfx-unittest/sea03.png",
    "./gfx-unittest/sea04.png",
    "./gfx-unittest/sea05.png",
    "./gfx-unittest/sea01.png"
  };
  
  std::cout << "### GFX SYSTEM UNIT TEST" << std::endl;
  
  initDisplay("GFX SYSTEM UNIT TEST");
  
  
  std::cout << "loading gfx files..." << std::flush;
    
    for (auto & file : dataFiles) {loadImageToStore(file);}
    
  std::cout << "done!" << std::endl;
  
  
  
  std::cout << "showing one image in the store..." << std::flush;
  
    showImage(0);

  std::cout << "done!" << std::endl;
  
  
  
  std::cout << "showcasing drawing primitives..." << std::flush;
    
    clearDisplay(gfxColor::WHITE);
    
    putImage (0,  10, 10);
    putImage (1,  60, 10);
    putImage (2, -40, 60);
    putImage (3,  60, 60);
    
    GfxBox_t box = {
      100, 100,
      300, 200,
      {255,   0,   0},
      {255, 255,   0},
      {255, 255, 255},
      2,
      7
    };
    drawBoxedText("lorem ipsum", box);
    
    fadeTransition(2000);
    
    showDisplay(true);
    
  std::cout << "done" << std::endl;
}
// -------------------------------------------------------------------------- //
void unittest_Animation() {
  std::vector<std::string> dataFiles = {
    "./gfx-unittest/sea01.png",
    "./gfx-unittest/sea02.png",
    "./gfx-unittest/sea03.png",
    "./gfx-unittest/sea04.png",
    "./gfx-unittest/sea05.png"
  };
  
  Animation ani(dataFiles);
  
  ani.show();
}
