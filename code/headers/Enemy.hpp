#pragma once

#include "Entity.hpp"
#include "CollisionBox.hpp"
#include <cstdlib>
#include <ctime>


class Enemy :public Entity, public CollisionBox{
private:
  int EnemyLevel;
  int EnemyHealthPoints;
public:
  Vector2 GetPos ( )const override{ return Position; }
  int GetRotation ( )const override{ return Rotation; }

  ~Enemy ( ) override = default;
  Enemy ( ) = default;

  Enemy ( Vector2, int, int, float , int, int);
  void Draw()const override;
  void Update ( ) override;

};
