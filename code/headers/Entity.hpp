#pragma once

#include <raylib.h>

class Entity {
protected:
  Vector2 Position;
  int Rotation;
  int Sides;
public:

  Entity ( Vector2 new_position,
           int new_rotation,
           int new_sides )
    : Position ( new_position )
    , Rotation ( new_rotation )
    , Sides ( new_sides ) { }

  // virtual void Draw ( )const = 0;

  virtual ~Entity ( ) = default;

};