#pragma once

#include "Entity.hpp"
#include "CollisionBox.hpp"
#include "NonPlayer.hpp"
#include <cstdlib>
#include <ctime>


class Enemy :public NonPlayer, public CollisionBox{
private:
  int EnemyLevel;
  int EnemyHealthPoints;
public:
  Vector2 GetPos ( )const { return Position; }
  int GetRotation ( )const { return Rotation; }

  ~Enemy ( ) = default ;
  Enemy ( ) = default;

  Enemy ( Vector2, int, int, float , int, int);

  void Draw()const override;
  
};
