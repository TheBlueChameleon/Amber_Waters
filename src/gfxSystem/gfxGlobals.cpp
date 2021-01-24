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

// -------------------------------------------------------------------------- //
// gfxColors globals

namespace gfxColor {
  const GfxColor_t BLACK = {  0,   0,   0};
  const GfxColor_t WHITE = {255, 255, 255};
  const GfxColor_t BLUE  = {  0,   0, 255};
  const GfxColor_t GREEN = {  0, 255,   0};
  const GfxColor_t RED   = {255,   0,   0};
}

// .......................................................................... //

namespace keycode {
  const unsigned int KC_ESC        = cimg_library::cimg::keyESC;
  const unsigned int KC_F1         = cimg_library::cimg::keyF1;
  const unsigned int KC_F2         = cimg_library::cimg::keyF2;
  const unsigned int KC_F3         = cimg_library::cimg::keyF3;
  const unsigned int KC_F4         = cimg_library::cimg::keyF4;
  const unsigned int KC_F5         = cimg_library::cimg::keyF5;
  const unsigned int KC_F6         = cimg_library::cimg::keyF6;
  const unsigned int KC_F7         = cimg_library::cimg::keyF7;
  const unsigned int KC_F8         = cimg_library::cimg::keyF8;
  const unsigned int KC_F9         = cimg_library::cimg::keyF9;
  const unsigned int KC_F10        = cimg_library::cimg::keyF10;
  const unsigned int KC_F11        = cimg_library::cimg::keyF11;
  const unsigned int KC_F12        = cimg_library::cimg::keyF12;
  const unsigned int KC_PAUSE      = cimg_library::cimg::keyPAUSE;
  const unsigned int KC_1          = cimg_library::cimg::key1;
  const unsigned int KC_2          = cimg_library::cimg::key2;
  const unsigned int KC_3          = cimg_library::cimg::key3;
  const unsigned int KC_4          = cimg_library::cimg::key4;
  const unsigned int KC_5          = cimg_library::cimg::key5;
  const unsigned int KC_6          = cimg_library::cimg::key6;
  const unsigned int KC_7          = cimg_library::cimg::key7;
  const unsigned int KC_8          = cimg_library::cimg::key8;
  const unsigned int KC_9          = cimg_library::cimg::key9;
  const unsigned int KC_0          = cimg_library::cimg::key0;
  const unsigned int KC_BACKSPACE  = cimg_library::cimg::keyBACKSPACE;
  const unsigned int KC_INSERT     = cimg_library::cimg::keyINSERT;
  const unsigned int KC_HOME       = cimg_library::cimg::keyHOME;
  const unsigned int KC_PAGEUP     = cimg_library::cimg::keyPAGEUP;
  const unsigned int KC_TAB        = cimg_library::cimg::keyTAB;
  const unsigned int KC_Q          = cimg_library::cimg::keyQ;
  const unsigned int KC_W          = cimg_library::cimg::keyW;
  const unsigned int KC_E          = cimg_library::cimg::keyE;
  const unsigned int KC_R          = cimg_library::cimg::keyR;
  const unsigned int KC_T          = cimg_library::cimg::keyT;
  const unsigned int KC_Y          = cimg_library::cimg::keyY;
  const unsigned int KC_U          = cimg_library::cimg::keyU;
  const unsigned int KC_I          = cimg_library::cimg::keyI;
  const unsigned int KC_O          = cimg_library::cimg::keyO;
  const unsigned int KC_P          = cimg_library::cimg::keyP;
  const unsigned int KC_DELETE     = cimg_library::cimg::keyDELETE;
  const unsigned int KC_END        = cimg_library::cimg::keyEND;
  const unsigned int KC_PAGEDOWN   = cimg_library::cimg::keyPAGEDOWN;
  const unsigned int KC_CAPSLOCK   = cimg_library::cimg::keyCAPSLOCK;
  const unsigned int KC_A          = cimg_library::cimg::keyA;
  const unsigned int KC_S          = cimg_library::cimg::keyS;
  const unsigned int KC_D          = cimg_library::cimg::keyD;
  const unsigned int KC_F          = cimg_library::cimg::keyF;
  const unsigned int KC_G          = cimg_library::cimg::keyG;
  const unsigned int KC_H          = cimg_library::cimg::keyH;
  const unsigned int KC_J          = cimg_library::cimg::keyJ;
  const unsigned int KC_K          = cimg_library::cimg::keyK;
  const unsigned int KC_L          = cimg_library::cimg::keyL;
  const unsigned int KC_ENTER      = cimg_library::cimg::keyENTER;
  const unsigned int KC_SHIFTLEFT  = cimg_library::cimg::keySHIFTLEFT;
  const unsigned int KC_Z          = cimg_library::cimg::keyZ;
  const unsigned int KC_X          = cimg_library::cimg::keyX;
  const unsigned int KC_C          = cimg_library::cimg::keyC;
  const unsigned int KC_V          = cimg_library::cimg::keyV;
  const unsigned int KC_B          = cimg_library::cimg::keyB;
  const unsigned int KC_N          = cimg_library::cimg::keyN;
  const unsigned int KC_M          = cimg_library::cimg::keyM;
  const unsigned int KC_SHIFTRIGHT = cimg_library::cimg::keySHIFTRIGHT;
  const unsigned int KC_ARROWUP    = cimg_library::cimg::keyARROWUP;
  const unsigned int KC_CTRLLEFT   = cimg_library::cimg::keyCTRLLEFT;
  const unsigned int KC_APPLEFT    = cimg_library::cimg::keyAPPLEFT;
  const unsigned int KC_ALT        = cimg_library::cimg::keyALT;
  const unsigned int KC_SPACE      = cimg_library::cimg::keySPACE;
  const unsigned int KC_ALTGR      = cimg_library::cimg::keyALTGR;
  const unsigned int KC_APPRIGHT   = cimg_library::cimg::keyAPPRIGHT;
  const unsigned int KC_MENU       = cimg_library::cimg::keyMENU;
  const unsigned int KC_CTRLRIGHT  = cimg_library::cimg::keyCTRLRIGHT;
  const unsigned int KC_ARROWLEFT  = cimg_library::cimg::keyARROWLEFT;
  const unsigned int KC_ARROWDOWN  = cimg_library::cimg::keyARROWDOWN;
  const unsigned int KC_ARROWRIGHT = cimg_library::cimg::keyARROWRIGHT;
  const unsigned int KC_PAD0       = cimg_library::cimg::keyPAD0;
  const unsigned int KC_PAD1       = cimg_library::cimg::keyPAD1;
  const unsigned int KC_PAD2       = cimg_library::cimg::keyPAD2;
  const unsigned int KC_PAD3       = cimg_library::cimg::keyPAD3;
  const unsigned int KC_PAD4       = cimg_library::cimg::keyPAD4;
  const unsigned int KC_PAD5       = cimg_library::cimg::keyPAD5;
  const unsigned int KC_PAD6       = cimg_library::cimg::keyPAD6;
  const unsigned int KC_PAD7       = cimg_library::cimg::keyPAD7;
  const unsigned int KC_PAD8       = cimg_library::cimg::keyPAD8;
  const unsigned int KC_PAD9       = cimg_library::cimg::keyPAD9;
  const unsigned int KC_PADADD     = cimg_library::cimg::keyPADADD;
  const unsigned int KC_PADSUB     = cimg_library::cimg::keyPADSUB;
  const unsigned int KC_PADMUL     = cimg_library::cimg::keyPADMUL;
  const unsigned int KC_PADDIV     = cimg_library::cimg::keyPADDIV;
}

// -------------------------------------------------------------------------- //
// gfxStore globals

CImgList <unsigned char>   gfxStore;
std::vector<std::string>   gfxFilenames;
int                        gfxStoreSize = 0;

// -------------------------------------------------------------------------- //
// gfxDisplay globals

int scrWidth = 800, scrHeight = 600;
Image_t showBuffer;
CImgDisplay display;

// -------------------------------------------------------------------------- //
// misc

long          (* cimg_wait)   (const unsigned int milliseconds ) = cimg_library::cimg::wait;
unsigned long (* cimg_timeer) (void)                             = cimg_library::cimg::time;
unsigned long (* cimg_tic)    (void)                             = cimg_library::cimg::tic;
unsigned long (* cimg_toc)    (void)                             = cimg_library::cimg::toc;
