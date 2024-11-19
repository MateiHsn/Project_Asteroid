#pragma once

#include <iostream>

class DefaultParameters {
private:
  DefaultParameters ( ) = default;
  ~DefaultParameters ( ) = default;

  static DefaultParameters * DefPars;

public:
  static DefaultParameters & GetInstance ( );

  void ShowDefInfo() {
    
  }
  DefaultParameters ( const DefaultParameters & ) = delete;
  DefaultParameters & operator=( const DefaultParameters & ) = delete;

};

enum MenuStates { MENU, SETTINGS, PLAYING, PAUSE };