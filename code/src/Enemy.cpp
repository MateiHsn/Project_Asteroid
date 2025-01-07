#include "../headers/Enemy.hpp"
#include "../headers/DefaultParameters.hpp"
#include "../headers/Entity.hpp"
#include "./Entity.cpp"


#include <cstdlib>
#include <ctime>

Enemy::Enemy ( Vector2 new_position,
               int new_rotation,
               int new_sides,
               float new_radius,
               int new_enemy_level,
               int new_enemy_health_points ) :
  Entity ( new_position,
           new_rotation,
           new_sides ),
  CollisionBox ( new_radius ),
  EnemyLevel ( new_enemy_level ),
  EnemyHealthPoints ( new_enemy_health_points ) { }


void Enemy::Draw ( ) const {
  
  srand ( time ( nullptr ) );

  DrawPolyLinesEx ( Position, 3 * rand ( ) % 8, Radius, Rotation, 3, WHITE );

}

void Enemy::Update() {

  Position.x += cos ( ( Rotation - 90 ) * DEG2RAD ) * DefaultParameters::GetInstance ( )->GetMultiplier ( );
  Position.y += sin ( ( Rotation - 90 ) * DEG2RAD ) * DefaultParameters::GetInstance ( )->GetMultiplier ( );

}



