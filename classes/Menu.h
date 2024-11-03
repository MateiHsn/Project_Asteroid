#ifndef OOP_MENU_H
#define OOP_MENU_H
#include <raylib.h>
#include <iostream>

class Menu {
private:
  unsigned state;

public:
  Menu(){};

  Menu(unsigned){};

  void RunApp(player&){};

  ~Menu(){};
};

#endif