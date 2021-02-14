// ========================================================================== //
// dependencies

// STL
#include <exception>
#include <cassert>

#include <iostream>

#include <vector>
#include <string>

// LIB
#include "pugixml.hpp"

// own
#include "globals.hpp"
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
void unittest_Animation() {
  std::vector<std::string> dataFiles = {
    "./gfx-unittest/sea01.png",
    "./gfx-unittest/sea02.png",
    "./gfx-unittest/sea03.png",
    "./gfx-unittest/sea04.png",
    "./gfx-unittest/sea05.png"
  };
  
  std::cout << "### CLASS ANIMATION UNIT TEST" << std::endl;
  initDisplay("ANIMATION UNIT TEST");
  
  
  Animation ani(dataFiles);
  
  ani.show();
  
  std::cout << "### CLASS ANIMATION UNIT TEST DONE" << std::endl << std::endl;
}
// -------------------------------------------------------------------------- //
void unittest_XML () {
  {
    std::cout << "### LOADING AND VALIDATING GENERIC XML PROJECT FILES" << std::endl;
    
    try {
      auto doc = loadXML("non-existing-file");
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading non-existing file:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      auto doc = loadXML("xml-unittest/invalid-project-implicit.xml");
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file from wrong project:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      auto doc = loadXML("xml-unittest/invalid-project-missing-name.xml");
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file from undisclosed project:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      auto doc = loadXML("xml-unittest/invalid-project-explicit.xml");
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file from wrong but related project:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      auto doc = loadXML("xml-unittest/invalid-version-missing.xml");
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file with no version data:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      auto doc = loadXML("xml-unittest/invalid-version-major.xml");
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file from wrong major version:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      auto doc = loadXML("xml-unittest/invalid-version-minor.xml");
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file from wrong minor version:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    try {
      auto doc = loadXML("xml-unittest/invalid-version-text.xml");
    }
    catch (std::runtime_error & e) {
      std::cout << "prevented loading file from ill formed version:" << std::endl;
      std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    
    
    
    auto doc = loadXML("xml-unittest/tile-animation-reference.xml");
    std::cout << "project name: " << doc.child("project").attribute("name").value() << std::endl;
  }
}
