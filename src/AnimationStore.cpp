// ========================================================================== //
// dependencies

// STL
#include <vector>
#include <string>
  using namespace std::string_literals;
#include <algorithm>

#include <filesystem>
  namespace fs = std::filesystem;

// own
#include "Animation.hpp"
  
// ========================================================================== //
// local macro

#define THROWTEXT(msg) ("RUNTIME EXCEPTION IN "s + (__PRETTY_FUNCTION__) + "\n"s + msg)

// ========================================================================== //
// Animation Store globals

std::vector<Animation>   AnimationStore;
std::vector<std::string> AnimationFilenames;
int                      AnimationStoreSize;

// ========================================================================== //
// Animation Store procs

// -------------------------------------------------------------------------- //
// getters

const std::vector<Animation>   & getAnimationStore    () {return AnimationStore;}
// .......................................................................... //
const std::vector<std::string> & getAnimationFilenames() {return AnimationFilenames;}
// .......................................................................... //
const int                      & getAnimationStoreSize() {return AnimationStoreSize;}
