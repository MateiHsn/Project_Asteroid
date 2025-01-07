#pragma once
#include <memory>
#include <vector>

#include "./Entity.hpp"
#include "./CollisionBox.hpp"
#include "./DefaultParameters.hpp"

class Projectile : public Entity, public CollisionBox {
private:
  int ProjectileDamage;
public:
  Projectile ( int new_damage = 1,
               Vector2 new_position = { static_cast< float >( DefaultParameters::GetInstance ( )->GetRenderWidth ( ) ),
                                       static_cast< float >( DefaultParameters::GetInstance ( )->GetRenderHeight ( ) ) },
               int new_rotation = 0,
               float new_radius = 1,
               int new_sides = 1 ) :
    Entity ( new_position, new_rotation, new_sides ),
    CollisionBox ( new_radius ),
    ProjectileDamage ( new_damage ){ }


  void Draw ( ) const override;

  Vector2 GetPos ( )const override { return this->Position; }
  int GetRotation ( )const override{ return this->Rotation; }

  void Update ( ) override;

  ~Projectile ( ) override = default;


};