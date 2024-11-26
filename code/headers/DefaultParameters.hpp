#pragma once

#include <iostream>

class DefaultParameters {
private:
  int screen_width;
  int screen_height;
  float multiplier;

  static DefaultParameters * def_parameters;

  DefaultParameters ( ) = default;
  ~DefaultParameters ( ) = default;


public:

  static DefaultParameters * & get_instance();

  static void set_window_dimensions ( int, int );
  static void set_mul ( float );
  static int get_width ( );
  static int get_height ( );
  static float get_mul ( );

  DefaultParameters ( const DefaultParameters & ) = delete;
  DefaultParameters & operator = ( const DefaultParameters & ) = delete;

};

enum MenuStates { MENU, SETTINGS, PLAYING, PAUSE };