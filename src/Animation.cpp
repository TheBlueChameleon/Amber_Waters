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

#define ADVANCEFRAME() {++currentFrame; currentFrame -= (currentFrame == frameCount) * frameCount;}

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
  
  frames     = frameIDs;
  frameCount = frameIDs.size();
}
// .......................................................................... //
Animation::Animation(std::vector<std::string> filenames) {
  for (auto & file : filenames) {frames.push_back( gfxStore_load(file) );}
  frameCount = frames.size();
}

// ========================================================================== //
// getter / setter

int                      Animation::getFrameCount() const {return frameCount;}
// .......................................................................... //
const std::vector<int> & Animation::getFrames    () const {return frames;}

// ========================================================================== //
// onscreen features

void Animation::show(double fps) {
  int delay = 1000 / fps;
  
  GfxBox_t box = {
    getScrWidth() - 100, getScrHeight() - 20,
    getScrWidth() -   0, getScrHeight() -  0,
    gfxColor::BLUE,
    gfxColor::WHITE,
    gfxColor::WHITE,
    1,
    3
  };
  
  display_flush();
  
  while (!display_is_closed() && !display_is_any_key() ) {
    
    putImage( frames[currentFrame] );
    
    drawBoxedText("fps: "s + std::to_string(display_frames_per_second()), box);
    
    showDisplay();
    
    ADVANCEFRAME();
    cimg_wait(delay);
  }
}
