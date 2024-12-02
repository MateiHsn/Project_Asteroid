#include <iostream>
#include <memory>
#include "./code/headers/Menu.hpp"
#include "./code/headers/DefaultParameters.hpp"
#include "code/headers/Player.hpp"
#include "code/headers/Exceptions.hpp"

int main ( ) {

  int * x = new int;
  int * y = new int;
  float * m = new float;

  try {
dims:

    std::cout << "Render width : ";
    std::cin >> *x;

    std::cout << "Render height : ";
    std::cin >> *y;

    if ( *x <= 0 || *y <= 0 )throw InvalidDimensionsException ( );

    if ( *x < *y && *x > 0 && *y > 0 ) throw NonLandscapeDimensions ( );

mult:

    std::cout << "Multiplier [1 - 2] : ";
    std::cin >> *m;

    if ( *m < 1 || *m > 2.5 ) throw InvalidMultiplierException ( );

  } catch ( const NonLandscapeDimensions & err ) {
    std::cout << err.what ( );
    goto dims;
  } catch ( const InvalidDimensionsException & err ) {
    std::cout << err.what ( );
    goto dims;
  } catch ( const InvalidMultiplierException & err ) {
    std::cout << err.what ( );
    goto mult;
  }

  DefaultParameters::GetInstance ( )->SetRenderDimensions ( *x, *y );
  DefaultParameters::GetInstance ( )->SetMultiplier ( *m );

  delete x, delete y, delete m;

  std::shared_ptr<Player> p = std::make_shared<Player> ( Player ("Gigel",
                                                         1,
                                                         5,
                                                         0,
                                                         { static_cast< float >( DefaultParameters::GetInstance ( )->GetRenderWidth ( ) ) / 2,
                                                           static_cast< float >( DefaultParameters::GetInstance ( )->GetRenderHeight ( ) ) / 2 },
                                                         DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 60,
                                                         3) );


  std::unique_ptr<Menu> menu = std::make_unique<Menu> ( PLAYING );


  menu->RunApp ( p );

  return 0;
}