#pragma once
#include <string>
#include "./Entity.hpp"
#include "./CollisionBox.hpp"
#include "./NonPlayer.hpp"
#include "raylib.h"
#include <vector>

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

  int GetRotation ( )const;

  Vector2 GetPos ( )const;

  void Update ( std::vector<std::shared_ptr<NonPlayer>> &);

  void Draw()const();

};