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
#include "AnimationStore.hpp"
  
// ========================================================================== //
// local macro

#define THROWTEXT(msg) ("RUNTIME EXCEPTION IN "s + (__PRETTY_FUNCTION__) + "\n"s + msg)

#define CHECK_STORE_INDEX(ID) {if ( (ID < 0) || (ID >= AnimationStoreSize) ) {throw std::out_of_range(THROWTEXT("  Invalid AnimationStore ID: "s + std::to_string(ID)));}}


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
const Animation                & getAnimation (const int storeID) {
  CHECK_STORE_INDEX(storeID);
  
  return AnimationStore[storeID];
}
// .......................................................................... //
const std::vector<std::string> & getAnimationFilenames() {return AnimationFilenames;}
// .......................................................................... //
const int                      & getAnimationStoreSize() {return AnimationStoreSize;}

// ========================================================================== //
// store state control

int AnimationStore_load (const std::string & filename) {
  // attempts to load animation description as from filename into memory
  // returns store ID on success
  // throws an error, otherwise.
  // if filename already in store, does not load it twice, but repeats older ID
  
  if (!fs::exists(filename)) {
    throw std::runtime_error(THROWTEXT(
      "  file not found: '"s + filename + "'"
    ));
  }
  
  // check whether filename already in store
  int storeID = AnimationStore_find(filename);
  
  if ( storeID == -1 ) {                                                        // not yet in store -- add
    auto newAni = Animation(filename);
    AnimationStore.push_back(newAni);
    AnimationFilenames.push_back(filename);
    return AnimationStoreSize++;
    
  } else {                                                                      // otherwise -- repeat old ID
    return storeID;
    
  }
  
}
// .......................................................................... //
int AnimationStore_find (const std::string & filename) {
  auto inStoreIterator = std::find(AnimationFilenames.begin(), AnimationFilenames.end(), filename);
  
  if ( inStoreIterator == AnimationFilenames.end() )  {return -1;} 
  else                                                {return std::distance(AnimationFilenames.begin(), inStoreIterator);}
}
// .......................................................................... //
void AnimationStore_advanceFrames() {
  for (auto & ani : AnimationStore) {ani.advanceFrame();}
}
