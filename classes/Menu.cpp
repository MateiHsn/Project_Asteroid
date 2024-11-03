#include "Menu.h"

Menu::Menu ( ) {
  std::cout << "Aplicatia a fost deschisa!\n";
}

Menu::Menu ( unsigned state ) {
  this->state = state;
}

Menu::~Menu ( ) {
  std::cout << "Aplicatia a fost inchisa\n";
}

//Menu::RunApp(Player )