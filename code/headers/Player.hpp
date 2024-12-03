#pragma once
#include <string>
#include "./Entity.hpp"
#include "./CollisionBox.hpp"
// #include "./Projectile.hpp"
#include "raylib.h"

class Player : public Entity, public CollisionBox{
private:
  std::string PlayerName;
  short PlayerLevel;
  short PlayerLives;

public:
  Player ( ) = default;

  Player ( const std::string &, short, short, int, const Vector2 &, float, int );

  Player ( const Player & );

  void Draw ( )const override;

  int GetRotation ( )const override;

  Vector2 GetPos ( )const override;

  void Update ( ) override;


};

