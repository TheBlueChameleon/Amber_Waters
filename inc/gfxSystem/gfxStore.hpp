/* TODO
 * Put component description here
 */

#ifndef GFXSTORE_HPP
#define GFXSTORE_HPP

// ========================================================================== //
// dependencies

#include <string>
#include <utility>

// ========================================================================== //
// gfx store

// -------------------------------------------------------------------------- //
// getter

int getStoreSize();

std::pair<int, int> getImageDimensions(const int ID);

// -------------------------------------------------------------------------- //
// store state control
  
int gfxStore_load (const std::string & filename);

// -------------------------------------------------------------------------- //
// onscreen features

void  putImage(const int ID, int atX = 0, int atY = 0);
void showImage(const int ID);

#endif
