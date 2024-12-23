#include "../headers/NonPlayer.hpp"

NonPlayer::NonPlayer ( Vector2 new_position,
                       int new_rotation,
                       int new_sides ) :
  Entity ( new_position,
           new_rotation,
           new_sides ) { }

NonPlayer::NonPlayer ( const NonPlayer & other ) :
  Entity ( other.Position, other.Rotation, other.Sides ) { }


  

