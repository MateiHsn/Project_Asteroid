#include <iostream>
#include <memory>
#include "./code/headers/Menu.hpp"
#include "./code/headers/DefaultParameters.hpp"
#include "code/headers/Player.hpp"



int main ( ) {

  std::shared_ptr<Menu> menu = std::make_shared<Menu> ( 1 );

  DefaultParameters::get_instance ( )->set_window_dimensions ( 1600, 1000 );
  DefaultParameters::get_instance ( )->set_mul ( 1.5 );

  Player * p1 = new Player ( "Gigel",
                             1,
                             5,
                             0,
                             { static_cast< float >( DefaultParameters::get_instance ( )->get_width ( ) ) / 2,
                               static_cast< float >( DefaultParameters::get_instance ( )->get_height ( ) ) / 2 },
                             DefaultParameters::get_instance ( )->get_width ( ) / 60,
                             3 );


  menu->RunApp ( p1 );

  delete p1;

  return 0;
}
