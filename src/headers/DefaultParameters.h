#ifndef OOP_DEFAULTPARAMETERS_H
#define OOP_DEFAULTPARAMETERS_H

#include <iostream>

class DefaultParameters {
private:
  int ScreenWidth;
  int ScreenHeight;
  float DefaultRotation=30;
  float Multiplier;

  static DefaultParameters * Def;

  DefaultParameters ( );

public:

  DefaultParameters ( const DefaultParameters & obj ) = delete;

  static DefaultParameters * GetInstance ( ) {
    return InstancePtr;
  }

  void SetMultiplier ( float NewMultiplier ) :Multiplier ( NewMultiplier ) { }
  void SetWindowDimensions ( int NewScreenWidth,
                             int NewScreenHeight ) :
    ScreenWidth ( NewScreenWidth ),
    ScreenHeight ( NewScreenheight ) { }

};

enum MenuStates{ MENU, SETTINGS, PLAYING, PAUSE };

#endif // 
