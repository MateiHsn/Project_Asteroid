#pragma once

#include "./Entity.hpp"

#include <vector>
#include <memory>
#include <iostream>
#include "raylib.h"

class NonPlayer : public Entity {
protected:

public:
  NonPlayer ( Vector2 new_position,
              int new_rotation,
              int new_sides)
  : Entity (new_position,
            new_rotation,
            new_sides){ }
  NonPlayer ( const NonPlayer &other)
  : Entity (other.Position,
            other.Rotation,
            other.Sides){ }
  
  virtual void Draw()const{ }
  
  virtual void Update(){ }
  
};
