// ========================================================================== //
// dependencies

// STL
#include <vector>
#include <string>
  using namespace std::string_literals;
#include <algorithm>

// lib
#include <CImg.h>
  using namespace cimg_library;

// own
#include "GfxStore.hpp"

// ========================================================================== //
// local macro

#define THROWTEXT(msg) ("RUNTIME EXCEPTION IN "s + (__PRETTY_FUNCTION__) + "\n"s + msg)

// ========================================================================== //
// CTor / DTor

// ========================================================================== //
// list manipulation

int GfxStore::getSize() const {return N;}
// -------------------------------------------------------------------------- //
int GfxStore::addImage(const std::string & filename) {
  // attempts to load filename into memory
  // returns store ID on success
  // throws an error, otherwise.
  // if filena already in store, does not load it twice, but repeats older ID
  
  // TODO: check whether file exists on disc
  
  
  
  // check whether filename already in store
  auto inStoreIterator = std::find(filenames.begin(), filenames.end(), filename);
  
  if ( inStoreIterator == filenames.end() ) {     // not yet in store -- add
    auto & newImg = store.insert(1);
    newImg.load(filename.data());
    
    filenames.push_back(filename);
    
    return N++;
  }
  else {
    return std::distance(filenames.begin(), inStoreIterator);
  }
  
}
 

// ========================================================================== //
// onscreen features

void GfxStore::showImage(const int ID, const int scrWidth, const int scrHeight) const {
  
  CImgDisplay display(
    400, 300,
    "Animation Preview -- press any key to quit",
    0
  );
  
  
  store(ID).display(display, true, nullptr, true);
}
// -------------------------------------------------------------------------- //
const std::string GfxStore::to_string() const {
  return "tbd"s;
}
