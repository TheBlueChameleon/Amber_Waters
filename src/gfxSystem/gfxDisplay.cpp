// ========================================================================== //
// dependencies

// STL
#include <iostream>
#include <exception>

#include <string>
  using namespace std::string_literals;
#include <algorithm>

// own
#include "gfxSystem/gfxGlobals.hpp"

// ========================================================================== //
// local macro

#define THROWTEXT(msg) ("RUNTIME EXCEPTION IN "s + (__PRETTY_FUNCTION__) + "\n"s + msg)

// ========================================================================== //
// display

void initDisplay(const std::string & title, int newScrWidth, int newScrHeight) {
  if ( (newScrWidth < 1) || (newScrHeight < 1) ) {
    throw std::invalid_argument(THROWTEXT(
      "  Invalid display size: "s + std::to_string(scrWidth) + "x" + std::to_string(scrHeight)
    ));
  }
  
  scrWidth  = newScrWidth;
  scrHeight = newScrHeight;
  
  display.resize(scrWidth, scrHeight);
  display.set_title(title.data());
  /*= CImgDisplay(
    scrWidth, scrHeight,
    title.data(),
    0
  );*/
  
  showBuffer = Image_t(scrWidth, scrHeight, 1, 3, 0);
}
// -------------------------------------------------------------------------- //
