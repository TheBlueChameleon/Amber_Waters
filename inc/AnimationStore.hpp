/* TODO
 * Put component description here
 */

#ifndef ANIMATIONSTORE_HPP
#define ANIMATIONSTORE_HPP

// ========================================================================== //
// dependencies

// STL
#include <vector>
#include <string>

// own
#include "Animation.hpp"

// ========================================================================== //
// module procs

// -------------------------------------------------------------------------- //
// getters

const std::vector<Animation>   & getAnimationStore    ();
const Animation                & getAnimation (const int storeID);
const std::vector<std::string> & getAnimationFilenames();
const int                      & getAnimationStoreSize();

// -------------------------------------------------------------------------- //
// store state control

int AnimationStore_load (const std::string & filename);
int AnimationStore_find (const std::string & filename);
void AnimationStore_advanceFrames();

#endif
