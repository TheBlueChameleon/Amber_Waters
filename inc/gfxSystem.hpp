/* TODO
 * Put component description here
 */

#ifndef GFXSYSTEM_HPP
#define GFXSYSTEM_HPP

// ========================================================================== //
// dependencies

// STL
#include <string>

// ========================================================================== //
// gfx store

// -------------------------------------------------------------------------- //
// read metadata

int getStoreSize();

// -------------------------------------------------------------------------- //
// store manipulation
  
int loadImageToStore(const std::string & filename);

// -------------------------------------------------------------------------- //
// onscreen features

void  putImage(const int ID, int atX = 0, int atY = 0);
void showImage(const int ID, int atX = 0, int atY = 0, bool reset = false);

// ========================================================================== //
// display

void initDisplay(const std::string & title, int srcWidth = 800, int scrHeight = 600);

//void drawBoxedText(const std::string & text, )

#endif
