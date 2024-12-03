#pragma once

#include "Entity.hpp"
#include "CollisionBox.hpp"

class Enemy :public Entity, public CollisionBox{
private:
  int EnemyLevel;
  int EnemyHealthPoints;
public:
  Vector2 GetPos ( )const override { return Position; }
  int GetRotation ( )const override { return 0; }

  void Update ( )override;
  void Draw ( )const override;
};
