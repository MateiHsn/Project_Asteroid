#pragma once

#include <iostream>

class DefaultParameters {
private:
  const int screen_width;
  const int screen_height;
  const float multiplier;

  DefaultParameters ( ) = default;
  ~DefaultParameters ( ) = default;

  static DefaultParameters * DefPars;

public:
  static DefaultParameters & get_instance ( )const;

  static void set_window_dimensions ( int, int );
  DefaultParameters ( const DefaultParameters & ) = delete;
  DefaultParameters & operator = ( const DefaultParameters & ) = delete;

};

enum MenuStates { MENU, SETTINGS, PLAYING, PAUSE };