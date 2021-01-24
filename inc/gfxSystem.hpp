/* TODO
 * Put component description here
 */

#ifndef GFXSYSTEM_HPP
#define GFXSYSTEM_HPP

// ========================================================================== //
// dependencies

// STL
#include <string>

// ========================================================================== //
// gfx colors (gfxGlobals)

using GfxColor_t = unsigned char[3];

namespace gfxColor {
  extern const GfxColor_t BLACK;
  extern const GfxColor_t WHITE;
  extern const GfxColor_t BLUE ;
  extern const GfxColor_t GREEN;
  extern const GfxColor_t RED  ;
}

// ========================================================================== //
// gfx box (local)

struct GfxBox_t {
  int x1, y1;
  int x2, y2;
  
  const unsigned char * fillColor   = gfxColor::BLACK;
  const unsigned char * borderColor = gfxColor::BLACK;
  const unsigned char * textColor   = gfxColor::WHITE;
  
  int borderWidth = 0;
  int margin = 0;
};

// ========================================================================== //
// constants

namespace keycode {
  extern const unsigned int KC_ESC        ;
  extern const unsigned int KC_F1         ;
  extern const unsigned int KC_F2         ;
  extern const unsigned int KC_F3         ;
  extern const unsigned int KC_F4         ;
  extern const unsigned int KC_F5         ;
  extern const unsigned int KC_F6         ;
  extern const unsigned int KC_F7         ;
  extern const unsigned int KC_F8         ;
  extern const unsigned int KC_F9         ;
  extern const unsigned int KC_F10        ;
  extern const unsigned int KC_F11        ;
  extern const unsigned int KC_F12        ;
  extern const unsigned int KC_PAUSE      ;
  extern const unsigned int KC_1          ;
  extern const unsigned int KC_2          ;
  extern const unsigned int KC_3          ;
  extern const unsigned int KC_4          ;
  extern const unsigned int KC_5          ;
  extern const unsigned int KC_6          ;
  extern const unsigned int KC_7          ;
  extern const unsigned int KC_8          ;
  extern const unsigned int KC_9          ;
  extern const unsigned int KC_0          ;
  extern const unsigned int KC_BACKSPACE  ;
  extern const unsigned int KC_INSERT     ;
  extern const unsigned int KC_HOME       ;
  extern const unsigned int KC_PAGEUP     ;
  extern const unsigned int KC_TAB        ;
  extern const unsigned int KC_Q          ;
  extern const unsigned int KC_W          ;
  extern const unsigned int KC_E          ;
  extern const unsigned int KC_R          ;
  extern const unsigned int KC_T          ;
  extern const unsigned int KC_Y          ;
  extern const unsigned int KC_U          ;
  extern const unsigned int KC_I          ;
  extern const unsigned int KC_O          ;
  extern const unsigned int KC_P          ;
  extern const unsigned int KC_DELETE     ;
  extern const unsigned int KC_END        ;
  extern const unsigned int KC_PAGEDOWN   ;
  extern const unsigned int KC_CAPSLOCK   ;
  extern const unsigned int KC_A          ;
  extern const unsigned int KC_S          ;
  extern const unsigned int KC_D          ;
  extern const unsigned int KC_F          ;
  extern const unsigned int KC_G          ;
  extern const unsigned int KC_H          ;
  extern const unsigned int KC_J          ;
  extern const unsigned int KC_K          ;
  extern const unsigned int KC_L          ;
  extern const unsigned int KC_ENTER      ;
  extern const unsigned int KC_SHIFTLEFT  ;
  extern const unsigned int KC_Z          ;
  extern const unsigned int KC_X          ;
  extern const unsigned int KC_C          ;
  extern const unsigned int KC_V          ;
  extern const unsigned int KC_B          ;
  extern const unsigned int KC_N          ;
  extern const unsigned int KC_M          ;
  extern const unsigned int KC_SHIFTRIGHT ;
  extern const unsigned int KC_ARROWUP    ;
  extern const unsigned int KC_CTRLLEFT   ;
  extern const unsigned int KC_APPLEFT    ;
  extern const unsigned int KC_ALT        ;
  extern const unsigned int KC_SPACE      ;
  extern const unsigned int KC_ALTGR      ;
  extern const unsigned int KC_APPRIGHT   ;
  extern const unsigned int KC_MENU       ;
  extern const unsigned int KC_CTRLRIGHT  ;
  extern const unsigned int KC_ARROWLEFT  ;
  extern const unsigned int KC_ARROWDOWN  ;
  extern const unsigned int KC_ARROWRIGHT ;
  extern const unsigned int KC_PAD0       ;
  extern const unsigned int KC_PAD1       ;
  extern const unsigned int KC_PAD2       ;
  extern const unsigned int KC_PAD3       ;
  extern const unsigned int KC_PAD4       ;
  extern const unsigned int KC_PAD5       ;
  extern const unsigned int KC_PAD6       ;
  extern const unsigned int KC_PAD7       ;
  extern const unsigned int KC_PAD8       ;
  extern const unsigned int KC_PAD9       ;
  extern const unsigned int KC_PADADD     ;
  extern const unsigned int KC_PADSUB     ;
  extern const unsigned int KC_PADMUL     ;
  extern const unsigned int keyPADDIV     ;
}

// ========================================================================== //
// misc (gfxGlobals)

extern long          (* cimg_wait) (const unsigned int milliseconds );
extern unsigned long (* cimg_timer) (void);
extern unsigned long (* cimg_tic)  (void);
extern unsigned long (* cimg_toc)  (void);

// ========================================================================== //
// gfx store

// -------------------------------------------------------------------------- //
// getter

int getStoreSize();

// -------------------------------------------------------------------------- //
// store state control
  
int gfxStore_load (const std::string & filename);

// -------------------------------------------------------------------------- //
// onscreen features

void  putImage(const int ID, int atX = 0, int atY = 0);
void showImage(const int ID);

// ========================================================================== //
// display

// -------------------------------------------------------------------------- //
// getter

int getScrWidth ();
int getScrHeight();

// -------------------------------------------------------------------------- //
// display state control

void initDisplay(const std::string & title, int srcWidth = 800, int scrHeight = 600);
void showDisplay(bool eternally = false);

// -------------------------------------------------------------------------- //
// drawing primitives wrapper

void clearDisplay (const GfxColor_t color = gfxColor::BLACK);
void drawBoxedText(const std::string & text, const GfxBox_t box);

// -------------------------------------------------------------------------- //
// scene transitions (TODO)

void fadeTransition(const int timeInMS, const GfxColor_t color = gfxColor::BLACK);
void blurTransition(const int timeInMS);

// -------------------------------------------------------------------------- //
// exposed features

bool         display_is_closed         ()                                                                                                  ;
bool         display_is_event          ()                                                                                                  ;
bool         display_is_any_key        ()                                                                                                  ;
bool         display_is_key            (const unsigned int keycode)                                                                        ;
bool         display_is_key_sequence   (const unsigned int *const keycodes_sequence, const unsigned int length, const bool remove_sequence);
int          display_mouse_x           ()                                                                                                  ;
int          display_mouse_y           ()                                                                                                  ;
unsigned int display_button            ()                                                                                                  ;
int          display_wheel             ()                                                                                                  ;
unsigned int display_key               (const unsigned int pos)                                                                            ;
float        display_frames_per_second ()                                                                                                  ;
void         display_flush             ();


#endif

// .......................................................................... //
// -------------------------------------------------------------------------- //
// ========================================================================== //
