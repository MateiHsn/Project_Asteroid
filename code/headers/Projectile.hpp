#pragma once
#include <memory>
#include <vector>

#include "./Entity.hpp"
#include "./CollisionBox.hpp"
#include "./NonPlayer.hpp"
#include "./DefaultParameters.hpp"

class Projectile : public NonPlayer, public CollisionBox {
private:
  int ProjectileDamage;
  short ProjectileType;
  int ProjectileLength;
public:
  Projectile ( ) = default;

  ~Projectile ( ) override= default;


};