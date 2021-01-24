// ========================================================================== //
// dependencies

// STL
#include <iostream>
#include <exception>

#include <string>
  using namespace std::string_literals;

#include <cmath>
#include <algorithm>

// own
#include "gfxSystem/gfxGlobals.hpp"

// ========================================================================== //
// local macro

#define THROWTEXT(msg) ("RUNTIME EXCEPTION IN "s + (__PRETTY_FUNCTION__) + "\n"s + msg)

// ========================================================================== //
// globals control

void initDisplay(const std::string & title, int newScrWidth, int newScrHeight) {
  if ( (newScrWidth < 1) || (newScrHeight < 1) ) {
    throw std::invalid_argument(THROWTEXT(
      "  Invalid display size: "s + std::to_string(scrWidth) + "x" + std::to_string(scrHeight)
    ));
  }
  
  scrWidth  = newScrWidth;
  scrHeight = newScrHeight;
  
  display.resize(scrWidth, scrHeight);
  display.set_title(title.data());
  
  showBuffer = Image_t(scrWidth, scrHeight, 1, 3, 0);
  display.display( showBuffer );
}
// .......................................................................... //
void showDisplay(bool eternally) {
  display.display( showBuffer );
  display.show();
  if (eternally) {while (!display.is_closed() && !display.is_keyESC() ) {cimg::wait(20);}}
}
// .......................................................................... //

// -------------------------------------------------------------------------- //

// ========================================================================== //
// drawing primitives wrapper

void clearDisplay(const GfxColor_t color) {
  showBuffer.draw_rectangle(
           0,         0, 0,
    scrWidth, scrHeight, 0,
    color
  );
}
// .......................................................................... //
void drawBoxedText(const std::string & text, const GfxBox_t box) {
  showBuffer.draw_rectangle(
    box.x1, box.y1, 0,
    box.x2, box.y2, 0,
    box.borderColor
  );
  
  showBuffer.draw_rectangle(
    box.x1 + box.borderWidth, box.y1 + box.borderWidth, 0,
    box.x2 - box.borderWidth, box.y2 - box.borderWidth, 0,
    box.fillColor
  );
  
  showBuffer.draw_text(
    box.x1 + box.margin, box.y1 + box.margin,
    text.data(),
    box.textColor
  );
}

// ========================================================================== //
// scene transitions

void fadeTransition(const int timeInMS, const GfxColor_t color) {
  const int steps = 50;
  
  float opacity = 1.0 - std::pow(0.05, 1.0 / steps);
  
  for (int i = 0; i < steps; ++i) {
    showBuffer.draw_rectangle(
            0,          0, 0,
      scrWidth, scrHeight, 0,
      color,
      opacity
    );
    
    display.display( showBuffer );
    display.show();
    
    cimg::wait(timeInMS / steps);
  }
  
  clearDisplay(color);
}

// ========================================================================== //
// exposed features

bool         display_is_closed         ()                                                                                                   {return display.is_closed();}
bool         display_is_event          ()                                                                                                   {return display.is_event();}
bool         display_is_any_key        ()                                                                                                   {return display.is_key();}
bool         display_is_key            (const unsigned int keycode)                                                                         {return display.is_key(keycode);}
bool         display_is_key_sequence   (const unsigned int *const keycodes_sequence, const unsigned int length, const bool remove_sequence) {
  return display.is_key_sequence(keycodes_sequence, length, remove_sequence);
}
int          display_mouse_x           ()                                                                                                   {return display.mouse_x();}
int          display_mouse_y           ()                                                                                                   {return display.mouse_y();}
unsigned int display_button            ()                                                                                                   {return display.button();}
int          display_wheel             ()                                                                                                   {return display.wheel();}
unsigned int display_key               (const unsigned int pos)                                                                             {return display.key(pos);}
float        display_frames_per_second ()                                                                                                   {return display.frames_per_second();}
void         display_flush             ()                                                                                                   {       display.flush();}
