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

#include <cstring>
#include <utility>

// lib
#include "pugixml.hpp"

// own
#include "globals.hpp"
#include "gfxSystem.hpp"
#include "Animation.hpp"
#include "AnimationStore.hpp"

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
Animation::Animation(std::vector<std::string> filenames) {loadFrames    (filenames);}
// .......................................................................... //
Animation::Animation(            std::string  filename ) {loadDefinition(filename );}

// ========================================================================== //
// getter / setter

void                     Animation::reset() {
  frames.clear();
  frameCount   = 0;
  currentFrame = 0;
}
// -------------------------------------------------------------------------- //
int                      Animation::getFrameCount() const {return frameCount;}
// .......................................................................... //
int                      Animation::getCurrentFrame() const {return currentFrame;}
// .......................................................................... //
int                      Animation::getCurrentImageID() const {return frames[currentFrame];}
// .......................................................................... //
const std::vector<int> & Animation::getFrames () const {return frames;}
// -------------------------------------------------------------------------- //
void                     Animation::advanceFrame() {ADVANCEFRAME();}

// ========================================================================== //
// loader

void                     Animation::loadFrames(const std::vector<std::string> & filenames) {
  for (auto & file : filenames) {frames.push_back( gfxStore_load(file) );}
  frameCount += filenames.size();
}
// .......................................................................... //
void                     Animation::loadDefinition (const std::string & filename ) {
  auto doc = loadXML(filename, "animation");
  loadDefinition(doc);
}
// .......................................................................... //
void                     Animation::loadDefinition (const pugi::xml_node & doc) {
  auto root = doc.child("project");
  auto nodeAnimation = root.child("animation");
  
  auto ref = nodeAnimation.attribute("source");
  if ( ref ) {
    auto repetitions = nodeAnimation.attribute("repeat").as_int(1);
    auto storeID     = AnimationStore_load( ref.value() );
    for (auto i=0; i<repetitions; ++i) {addFromStore(storeID);}
  }
  
  std::vector<std::string> frames;
  std::string              current;
  
  for (auto node = nodeAnimation.first_child(); node; node = node.next_sibling()) {
    if        ( !std::strcmp(node.name(), "frame") ) {
      current = node.attribute("file").value();
      auto attr = node.attribute("repeat");
      for (auto i = 0; i < attr.as_int(1); ++i) {frames.push_back(current);}
      
    } else if ( !std::strcmp(node.name(), "animation") ) {
      ref = node.attribute("source");
      if ( ref ) {
        auto repetitions = node.attribute("repeat").as_int(1);
        auto storeID     = AnimationStore_load( ref.value() );
        for (auto i=0; i<repetitions; ++i) {addFromStore(storeID);}
      }
      
    }
    
  }
  
  loadFrames(frames);
}
// -------------------------------------------------------------------------- //
void                     Animation::addFromStore   (const int storeID) {
  const std::vector<int> & storeContent = getAnimation(storeID).frames;
  
  frames.insert( frames.end(), storeContent.begin(), storeContent.end() );
  frameCount += storeContent.size();
}

// ========================================================================== //
// onscreen features

void Animation::show(bool tiled, double fps) {
  int delay = 1000 / fps;
  
  if (!frameCount) {
    throw std::runtime_error(THROWTEXT(
      "    Attempted to show animation without frames"
    ));
  }
  
  auto scrWidth  = getScrWidth ();
  auto scrHeight = getScrHeight();
  
  GfxBox_t box = {
    scrWidth - 100, scrHeight - 20,
    scrWidth -   0, scrHeight -  0,
    gfxColor::BLUE,
    gfxColor::WHITE,
    gfxColor::WHITE,
    1,
    3
  };
  
  display_flush();
  
  while (!display_is_closed() && !display_is_any_key() ) {
    auto frameID = frames[currentFrame];
    
    if (tiled) {
      auto dimensions = getImageDimensions(frameID);
      
      for   (auto y = 0; y < scrHeight; y += dimensions.second) {
        for (auto x = 0; x < scrWidth ; x += dimensions.first ) {
          putImage( frameID, x, y );
        }
      }
      
    } else {
      putImage( frameID );
    }
    
    drawBoxedText("fps: "s + std::to_string(display_frames_per_second()), box);
    
    showDisplay();
    
    ADVANCEFRAME();
    cimg_wait(delay);
  }
}
// -------------------------------------------------------------------------- //
