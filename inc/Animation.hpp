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

// ========================================================================== //
// class

class Animation {
private:
  std::vector<int> frames;
  
  
public:
  // -------------------------------------------------------------------------- //
  // CTor, DTor
  
  Animation(std::vector<int>         frames);
  Animation(std::vector<std::string> filenames);
  
  // -------------------------------------------------------------------------- //
  // output test
  
  void show(double fps = 60.0);
};

#endif
