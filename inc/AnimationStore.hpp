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

// ========================================================================== //
// module globals

// NOTE: none of these need to be exposed.

// ========================================================================== //
// module procs

// -------------------------------------------------------------------------- //
// getters

const std::vector<Animation>   & getAnimationStore    ();
const std::vector<std::string> & getAnimationFilenames();
const int                      & getAnimationStoreSize();

// -------------------------------------------------------------------------- //
// store state control

// int gfxStroe_load (const std::string & filename) {
//   // attempts to load filename into memory
//   // returns store ID on success
//   // throws an error, otherwise.
//   // if filena already in store, does not load it twice, but repeats older ID
//   
//   if (!fs::exists(filename)) {
//     throw std::runtime_error(THROWTEXT(
//       "  file not found: '"s + filename + "'"
//     ));
//   }
//   
//   // check whether filename already in store
//   auto inStoreIterator = std::find(gfxFilenames.begin(), gfxFilenames.end(), filename);
//   
//   if ( inStoreIterator == gfxFilenames.end() ) {         // not yet in store -- add
//     auto newImg = Image_t(filename.data());
//     gfxStore.push_back(newImg);
//     
//     gfxFilenames.push_back(filename);
//     
//     return gfxStoreSize++;
//     
//   } else {                                         // otherwise -- repeat old ID
//     return std::distance(gfxFilenames.begin(), inStoreIterator);
//     
//   }
//   
// }

#endif
