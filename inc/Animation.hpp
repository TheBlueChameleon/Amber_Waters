/* TODO
 * Put component description here
 */

#ifndef ANIMATION_HPP
#define ANIMATION_HPP

// ========================================================================== //
// dependencies

// STL
#include <vector>
#include <string>

// LIB
#include "pugixml.hpp"

// ========================================================================== //
// class

class Animation {
private:
  std::vector<int> frames;
  int              frameCount   = 0;
  int              currentFrame = 0;
  
  
public:
  // ------------------------------------------------------------------------ //
  // CTor, DTor
  
  Animation(std::vector<int>         frames);
  Animation(std::vector<std::string> filenames);                                // expects a vector of picture file names
  Animation(std::string              filename);                                 // expects an XML file name identifying a valid Animation description
  
  // ------------------------------------------------------------------------ //
  // getter / setter
  
  void reset();
  
  int                      getFrameCount() const;
  int                      getCurrentFrame() const;
  int                      getCurrentImageID() const;
  const std::vector<int> & getFrames() const;
  
  void advanceFrame();
  
  // ------------------------------------------------------------------------ //
  // loader
  
  void loadFrames     (const std::vector<std::string> & filenames);
  void loadDefinition (const std::string              & filename );
  void loadDefinition (const pugi::xml_node           & node);
  
  // ------------------------------------------------------------------------ //
  // onscreen features
  
  void show(bool tiled = false, double fps = 60.0);
};

#endif
