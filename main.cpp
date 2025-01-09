#include <iostream>
#include <memory>
#include <vector>

#include "code/headers/Exceptions.hpp"
#include "code/headers/Player.hpp"
#include "code/headers/Projectile.hpp"
#include "code/headers/Enemy.hpp"
#include "code/headers/Entity.hpp"
#include "code/headers/DefaultParameters.hpp"
#include "code/headers/Menu.hpp"
#include "code/headers/EntityManager.hpp"
#include "code/src/TemplateFunction.cpp"

int Entity::EntityID = 0;

int main() {
  int* x = new int(0);
  int* y = new int(0);
  float* m = new float(0.f);

  while(true) {

    try {
      if ( !( *x ) ) {
        std::cout << "Render width: ";
        std::cin >> *x;
        if ( *x <= 0 ) throw NullNegativeDimensionsException ( );
      }

      if ( !( *y ) ) {
        std::cout << "Render height: ";
        std::cin >> *y;
        if ( *y <= 0 ) throw NullNegativeDimensionsException ( );
      }

      if ( *x <= *y )throw NonLandscapeDimensionsException ( );

      if ( !( *m ) ) {
        std::cout << "Game multiplier [2 - 2.5]:";
        std::cin >> *m;
        if ( *m < 2 || *m > 2.5 ) throw InvalidMultiplierException ( );
      }
    }
    catch ( NullNegativeDimensionsException & err ) {
      std::cout << err.what ( );
      *x = *y = 0;
      continue;
    }
    catch ( NonLandscapeDimensionsException & err ) {
      std::cout << err.what ( );
      *x = *y = 0;
      continue;
    }
    catch ( InvalidMultiplierException & err ) {
      *m = 0;
      std::cout << err.what ( );
      continue;
    }

    break;

  }

  DefaultParameters::GetInstance ( )->SetRenderDimensions ( *x, *y );
  DefaultParameters::GetInstance ( )->SetMultiplier ( *m );

  delete x, y, m;

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

  std::vector<std::shared_ptr<Entity>> nps;

  nps.reserve ( 100 );

  menu->RunApp ( p, nps );

  DefaultParameters::FreeInstance ( );

  return 0;
}
