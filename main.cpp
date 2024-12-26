#include <iostream>
#include <memory>
#include <vector>

#include "code/headers/Exceptions.hpp"
#include "code/headers/Player.hpp"
#include "code/headers/DefaultParameters.hpp"
#include "code/headers/Menu.hpp"

int main() {
  int* x = new int;
  int* y = new int;
  float* m = new float;

  std::shared_ptr<Player> p = std::make_shared<Player> ( Player ( "Gigel",
                                                                  1,
                                                                  5,
                                                                  0,
                                                                  {
                                                                    static_cast< float >( DefaultParameters::GetInstance ( )->
                                                                      GetRenderWidth ( ) ) / 2,
                                                                    static_cast< float >( DefaultParameters::GetInstance ( )->
                                                                      GetRenderHeight ( ) ) / 2
                                                                  },
                                                                  DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 60,
                                                                  3 ) );

  std::unique_ptr<Menu> menu = std::make_unique<Menu> ( PLAYING );

  std::vector<std::shared_ptr<NonPlayer>> nps;

  nps.reserve ( 100 );

  menu->RunApp ( p, nps );

  DefaultParameters::FreeInstance ( );

  return 0;
}
