#pragma once
#include <string>
#include "./Entity.hpp"
// #include "./Projectile.hpp"
#include <vector>

#ifndef RAYLIB_H
#include <raylib.h>
#endif // !RAYLIB_H
#include <iostream>

class Player : public Entity {
private:
  std::string player_name;
  short player_level;
  short player_lives;
  float radius;
  int sides;

public:
  Player ( ) = default;

  Player ( const std::string & player_name,
           short player_level,
           short player_lives,
           float rotation,
           const Vector2 & player_position,
           float radius,
           int sides );
  Player ( const Player & other );

  void Draw ( )const;

  int GetRotation ( )const;

  Vector2 GetPos ( )const;

  void show_pos ( ) const;

  void Update ( );
};

