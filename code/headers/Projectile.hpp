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
  Projectile ( Vector2 new_position,
               int new_rotation,
               int new_sides,
               float new_radius,
               int new_projectile_damage,
               short new_projectile_type,
               int new_projectile_length = DefaultParameters::GetInstance()->GetRenderWidth()/40) :
    NonPlayer ( new_position,
                new_rotation,
                new_sides ),
    CollisionBox ( new_radius ),
    ProjectileDamage ( new_projectile_type ),
    ProjectileType ( new_projectile_type ),
    ProjectileLength ( new_projectile_length ) { }
  ~Projectile ( ) override= default;

  // void Draw ( ) const override { }

};