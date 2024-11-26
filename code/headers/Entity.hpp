#pragma once

#ifndef RAYLIB_H
#include <raylib.h>
#endif // !RAYLIB_H

#include <iostream>

class Entity {
protected:
  Vector2 position;
  int rotation;
public:

  Entity ( Vector2 new_position, int new_rotation ) :position ( new_position )
    , rotation ( new_rotation ) { }

  virtual Vector2 GetPos ( )const = 0;
  virtual int GetRotation ( )const = 0;
};