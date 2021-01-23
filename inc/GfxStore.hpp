/* TODO
 * Put component description here
 */

#ifndef GFXSTORE_HPP
#define GFXSTORE_HPP

// ========================================================================== //
// dependencies

// STL
#include <vector>
#include <string>

// lib
#include <CImg.h>

// ========================================================================== //
// class

class GfxStore {
private:
  cimg_library::CImgList<unsigned char> store;
  std::vector           <std::string>   filenames;
  int                                   N = 0;
  
public:
  // ------------------------------------------------------------------------ //
  // store manipulation
  
  int getSize() const;
  
  int addImage(const std::string & filename);
  
  // ------------------------------------------------------------------------ //
  // onscreen features
  
  void showImage(const int ID, const int scrWidth = -1, const int scrHeight = -1) const;
  
  const std::string to_string() const;
};

#endif
