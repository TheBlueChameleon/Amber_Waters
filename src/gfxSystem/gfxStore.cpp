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
#include "gfxSystem.hpp"
#include "gfxSystem/gfxGlobals.hpp"

// ========================================================================== //
// local macro

#define THROWTEXT(msg) ("RUNTIME EXCEPTION IN "s + (__PRETTY_FUNCTION__) + "\n"s + msg)

// ========================================================================== //
// gfx store

// -------------------------------------------------------------------------- //
// read metadata

int getStoreSize() {return storeSize;}

// -------------------------------------------------------------------------- //
// list manipulation

int loadImageToStore(const std::string & filename) {
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
  auto inStoreIterator = std::find(filenames.begin(), filenames.end(), filename);
  
  if ( inStoreIterator == filenames.end() ) {         // not yet in store -- add
    auto newImg = Image_t(filename.data());
    store.push_back(newImg);
    
    filenames.push_back(filename);
    
    return storeSize++;
    
  } else {                                         // otherwise -- repeat old ID
    return std::distance(filenames.begin(), inStoreIterator);
  }
  
}
 
// -------------------------------------------------------------------------- //
// onscreen features

void  putImage(const int ID, int atX, int atY) {
  if ( (ID < 0) || (ID >= storeSize) ) {
    throw std::out_of_range(THROWTEXT(
      "  Invalid GfxStore ID: "s + std::to_string(ID)
    ));
  }
  
  showBuffer.draw_image(atX, atY, store(ID) );
}
// .......................................................................... //
void showImage(const int ID, int atX, int atY, bool reset) {
  if (reset) {showBuffer.fill(0);}
  
  putImage(ID, atX, atY);
  
  display.display( showBuffer );
  //display.show();
  
  while (!display.is_closed() && !display.is_keyESC() ) {
    cimg::wait(20);
  }
}
// -------------------------------------------------------------------------- //
