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

  Enemy ( Vector2 new_position,
          int new_rotation,
          int new_sides,
          float new_radius,
          int new_enemy_level,
          int new_enemy_health_points);
  void Draw()const override;
  void Update ( ) override;

};
