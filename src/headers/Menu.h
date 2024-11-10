#ifndef OOP_MENU_H
#define OOP_MENU_H

#include <>
#include <raylib.h>
#include <iostream>

class Menu {
 private:
  char state;

 public:
  Menu() = default;

  Menu(char state) : state(state) {
    std::cout << "S-a creat meniul" << this->state << '\n';
  }

  friend std::ostream& operator<<(std::ostream& out, const Menu& obj) {
    return out << "State: " << obj.state;
  }

  static void RunApp(Player&);

  ~Menu() { std::cout << "Gata cu fotosinteza, la culcare toate lumea\n"; }
};

#endif