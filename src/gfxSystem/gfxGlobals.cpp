// ========================================================================== //
// dependencies

// STL
#include <vector>
#include <string>

// own
#include "gfxSystem/gfxGlobals.hpp"

// ========================================================================== //
// module globals

using Image_t = CImg<unsigned char>;

CImgList   <unsigned char> store;
std::vector<std::string>   filenames;
int                        storeSize = 0;

int scrWidth = 800, scrHeight = 600;
Image_t showBuffer;
CImgDisplay display;
