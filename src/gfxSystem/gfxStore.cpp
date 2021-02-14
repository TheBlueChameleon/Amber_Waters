// ========================================================================== //
// dependencies

// STL
#include <iostream>
#include <exception>

#include <vector>
#include <string>
  using namespace std::string_literals;
#include <algorithm>

#include <filesystem>
  namespace fs = std::filesystem;

// lib
#include <CImg.h>
  using namespace cimg_library;

// own
#define GFXSYSTEM_INTERNALS
#include "gfxSystem.hpp"

// ========================================================================== //
// local macro

#define THROWTEXT(msg) ("RUNTIME EXCEPTION IN "s + (__PRETTY_FUNCTION__) + "\n"s + msg)

// ========================================================================== //
// gfx store

// -------------------------------------------------------------------------- //
// getter

int getStoreSize() {return gfxStoreSize;}

// -------------------------------------------------------------------------- //
// store state control

int gfxStore_load (const std::string & filename) {
  // attempts to load filename into memory
  // returns store ID on success
  // throws an error, otherwise.
  // if filena already in store, does not load it twice, but repeats older ID
  
  if (!fs::exists(filename)) {
    throw std::runtime_error(THROWTEXT(
      "  file not found: '"s + filename + "'"
    ));
  }
  
  // check whether filename already in store
  auto inStoreIterator = std::find(gfxFilenames.begin(), gfxFilenames.end(), filename);
  
  if ( inStoreIterator == gfxFilenames.end() ) {         // not yet in store -- add
    auto newImg = Image_t(filename.data());
    gfxStore.push_back(newImg);
    
    gfxFilenames.push_back(filename);
    
    return gfxStoreSize++;
    
  } else {                                         // otherwise -- repeat old ID
    return std::distance(gfxFilenames.begin(), inStoreIterator);
    
  }
  
}
 
// -------------------------------------------------------------------------- //
// onscreen features

void  putImage(const int ID, int atX, int atY) {
  if ( (ID < 0) || (ID >= gfxStoreSize) ) {
    throw std::out_of_range(THROWTEXT(
      "  Invalid GfxStore ID: "s + std::to_string(ID)
    ));
  }
  
  showBuffer.draw_image(atX, atY, gfxStore(ID) );
}
// .......................................................................... //
void showImage(const int ID) {
  display.flush();
  display.display( gfxStore(ID) );
  while (!display.is_closed() && !display.is_key() ) {cimg::wait(20);}
}
// -------------------------------------------------------------------------- //
