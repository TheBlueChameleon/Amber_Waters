/* TODO: File descrption
 * Implementation of the FO_Plot class of the FileOutput Module
 */

// ========================================================================== //
// dependencies

// STL
#include <iostream>
#include <exception>

#include <string>
  using namespace std::string_literals;

// own
#include "gfxSystem.hpp"
#include "Animation.hpp"

// ========================================================================== //
// local macro

#define THROWTEXT(msg) ("RUNTIME EXCEPTION IN "s + (__PRETTY_FUNCTION__) + "\n"s + msg)

// ========================================================================== //
// CTor / DTor

Animation::Animation(std::vector<int> frameIDs) {
  auto storeSize = getStoreSize();
  
  for (auto & frame : frameIDs) {
    if ( (frame < 0) || (frame >= storeSize) ) {
      throw std::invalid_argument(THROWTEXT(
        "  Invalid frame ID: "s + std::to_string(frame)
      ));
    }
  }
  
  frames = frameIDs;
}
// .......................................................................... //
Animation::Animation(std::vector<std::string> filenames) {
  for (auto & file : filenames) {frames.push_back( loadImageToStore(file) );}
}

// ========================================================================== //
// output test

void Animation::show(double fps) {
  std::cout << "before wait" << std::endl;
  
  cimg_wait(1000);
  
  std::cout << "post wait" << std::endl;
//   while (!display.is_closed() && !display.is_keyESC() ) {
//     
//     auto frameID = frames[0];
//     putImage( store(frameID) );
//     showDisplay();
//     
//     cimg::wait(20);
//   }
}
