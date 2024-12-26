#include "../headers/Enemy.hpp"
#include "../headers/DefaultParameters.hpp"
#include "../headers/Entity.hpp"
#include "./Entity.cpp"


Enemy::Enemy ( Vector2 new_position,
               int new_rotation,
               int new_sides,
               float new_radius,
               int new_enemy_level,
               int new_enemy_health_points ) :
  NonPlayer ( new_position,
              new_rotation,
              new_sides ),
  CollisionBox ( new_radius ),
  EnemyLevel ( new_enemy_level ),
  EnemyHealthPoints ( new_enemy_health_points ) { }



void Enemy::Draw() const {



}


