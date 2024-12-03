#pragma once

#include <raylib.h>

#include <iostream>

class Entity {
protected:
  Vector2 Position;
  int Rotation;
  int Sides;
public:

  Entity ( Vector2 new_position,
           int new_rotation,
           int new_sides );

  virtual Vector2 GetPos ( )const = 0;
  virtual int GetRotation ( )const = 0;

  virtual void Update ( ) = 0;
  virtual void Draw ( )const = 0;

  Entity ( ) = default;
  virtual ~Entity ( ) = default;

};