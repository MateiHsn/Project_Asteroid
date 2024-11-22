#pragma once

#ifndef RAYLIB_H
#include <raylib.h>
#endif // !RAYLIB_H

#include <iostream>

class Entity {
private:
  Vector2 Position;
  int Rotation;
public:
  Vector2 GetPos ( )const = 0;
  int Rotation ( )const = 0;
};