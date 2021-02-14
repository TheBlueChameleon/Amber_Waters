/* TODO
 * Put component description here
 */

#ifndef GFXDISPLAY_HPP
#define GFXDISPLAY_HPP

// ========================================================================== //
// dependencies

#include <string>

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
