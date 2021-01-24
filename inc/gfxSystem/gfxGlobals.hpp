/* TODO
 * Put component description here
 */

#ifndef GFXGLOBALS_HPP
#define GFXGLOBALS_HPP

// ========================================================================== //
// dependencies

// STL
#include <vector>
#include <string>

// lib
#include <CImg.h>
  using namespace cimg_library;

// own
#include "gfxSystem.hpp"

// ========================================================================== //
// module definitions

using Image_t = CImg<unsigned char>;

// ========================================================================== //
// module globals

// -------------------------------------------------------------------------- //
// gfx store

extern CImgList   <unsigned char> store;
extern std::vector<std::string>   filenames;
extern int                        storeSize;

// -------------------------------------------------------------------------- //
// display

extern int scrWidth, scrHeight;
extern Image_t showBuffer;
extern CImgDisplay display;

#endif
