#pragma once


#include "Player.hpp"

#include <iostream>


/// @brief Class that describes the game window / menu.
class Menu {
private:
  char state; ///@brief State of the app from the MenuStates enum.

public:
  Menu ( ) = default;

  Menu ( char state ) : state ( state ) {
    std::cout << "S-a creat meniul " << static_cast< int >( this->state ) << '\n';
  }

  friend std::ostream & operator<<( std::ostream & out, const Menu & obj ) {
    return out << "State: " << obj.state;
  }

  /// @brief Opens the window and starts the game.
  void RunApp (const std::shared_ptr<Player> & );


  ///@brief Change the state of the menu based on inputs.
  void UpdateState ( char );

  ~Menu ( ) { std::cout << "Gata cu fotosinteza, la culcare toate lumea\n"; }
};

