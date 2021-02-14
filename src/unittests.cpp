// ========================================================================== //
// dependencies

// STL
#include <exception>
#include <cassert>

#include <iostream>

#include <vector>
#include <string>
  using namespace std::string_literals;

// LIB
#include "pugixml.hpp"

// own
#include "globals.hpp"
#include "gfxSystem.hpp"
#include "Animation.hpp"

// ========================================================================== //
// Class Unit Tests

void unittest_Animation() {
//   Stock Code -- replaced by XML facility
//   std::vector<std::string> dataFiles = {
//     "./gfx-unittest/sea01.png",
//     "./gfx-unittest/sea02.png",
//     "./gfx-unittest/sea03.png",
//     "./gfx-unittest/sea04.png",
//     "./gfx-unittest/sea05.png"
//   };
//   Animation ani(dataFiles);
  
  std::vector<std::string> empty;
  
  std::cout << "### CLASS ANIMATION UNIT TEST" << std::endl;
  initDisplay("ANIMATION UNIT TEST");
  
  try {
    Animation noFrames(empty);
    noFrames.show();
  }
  catch (std::runtime_error & e) {
    std::cout << "prevented showing empty animation:" << std::endl;
    std::cout << e.what() << std::endl;
  }
  
  Animation ani("./xml-unittest/animation-pure.xml");
  
  ani.show();
  
  std::cout << "### CLASS ANIMATION UNIT TEST DONE" << std::endl << std::endl;
}
// -------------------------------------------------------------------------- //

// ========================================================================== //
// System Unit Tests

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
    
    for (auto & file : dataFiles) {gfxStore_load(file);}
    
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
      gfxColor::RED,
      gfxColor::GREEN,
      gfxColor::WHITE,
      2,
      7
    };
    drawBoxedText("lorem ipsum", box);
    
    
    showDisplay(true);
    
    fadeTransition( 500);
    
  std::cout << "done" << std::endl;
  
  
  std::cout << "### GFX SYSTEM UNIT TEST DONE" << std::endl << std::endl;
}
// -------------------------------------------------------------------------- //
void unittest_AnimationStore() {
  
}
// -------------------------------------------------------------------------- //
void unittest_input () {
  initDisplay("Input test window");
  
  GfxBox_t
    boxPressEsc    = {0,   0, 200, 20, gfxColor::RED},
    boxMouseCoords = {0,  20, 200, 40};
  
  bool done = false;
  while (not done) {
    done = display_is_key (keycode::KC_ESC);
    
    drawBoxedText("Press ESC to continue", boxPressEsc);
    drawBoxedText(
      "Mouse at ("s + std::to_string(display_mouse_x()) + ", "+ std::to_string(display_mouse_y()) + ", "+ std::to_string(display_button()) + ")", 
      boxMouseCoords
    );
    
    showDisplay();
    cimg_wait(1);
    
  }
}
// -------------------------------------------------------------------------- //
void unittest_XML () {
  {
    std::cout << "### LOADING AND VALIDATING GENERIC XML PROJECT FILES" << std::endl;
    
    try {
      [[maybe_unused]] auto doc = loadXML("non-existing-file");
      std::cout << "!!! FAILED TO DETECT INVALID SITUATION" << std::endl;
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading non-existing file:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      [[maybe_unused]] auto doc = loadXML("xml-unittest/invalid-project-implicit.xml");
      std::cout << "!!! FAILED TO DETECT INVALID SITUATION" << std::endl;
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file from wrong project:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      [[maybe_unused]] auto doc = loadXML("xml-unittest/invalid-project-missing-name.xml");
      std::cout << "!!! FAILED TO DETECT INVALID SITUATION" << std::endl;
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file from undisclosed project:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      [[maybe_unused]] auto doc = loadXML("xml-unittest/invalid-project-explicit.xml");
      std::cout << "!!! FAILED TO DETECT INVALID SITUATION" << std::endl;
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file from wrong but related project:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      [[maybe_unused]] auto doc = loadXML("xml-unittest/invalid-version-missing.xml");
      std::cout << "!!! FAILED TO DETECT INVALID SITUATION" << std::endl;
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file with no version data:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      [[maybe_unused]] auto doc = loadXML("xml-unittest/invalid-version-major.xml");
      std::cout << "!!! FAILED TO DETECT INVALID SITUATION" << std::endl;
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file from wrong major version:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      [[maybe_unused]] auto doc = loadXML("xml-unittest/invalid-version-minor.xml");
      std::cout << "!!! FAILED TO DETECT INVALID SITUATION" << std::endl;
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file from wrong minor version:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      [[maybe_unused]] auto doc = loadXML("xml-unittest/invalid-version-text.xml");
      std::cout << "!!! FAILED TO DETECT INVALID SITUATION" << std::endl;
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file from ill formed version:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      [[maybe_unused]] auto doc = loadXML("xml-unittest/tile-animation-reference.xml", "other content");
      std::cout << "!!! FAILED TO DETECT INVALID SITUATION" << std::endl;
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading with non-matching content:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    auto doc = loadXML("xml-unittest/tile-animation-reference.xml");
    std::cout << "found following first level nodes" << std::endl;
    for (auto node = doc.first_child(); node; node = node.next_sibling()) {
      std::cout << "* " << node.name() << std::endl;
    }
  }
}
