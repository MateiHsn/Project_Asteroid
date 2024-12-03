#pragma once

#include "./Entity.hpp"
#include "./CollisionBox.hpp"

#pragma once

class Projectile : public Entity, public CollisionBox {
private:
  int ProjectileDamage;
public:
  Projectile ( ) = default;
};