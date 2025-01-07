#include "../headers/Projectile.hpp"
#include "../headers/CollisionBox.hpp"
#include "../src/CollisionBox.cpp"

void Projectile::Draw() const {

  DrawLineEx ( Position,
               { Position.x + cos ( ( Rotation - 90 ) * DEG2RAD ) * DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 30,
                 Position.y + sin ( ( Rotation - 90 ) * DEG2RAD ) * DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 30 },
               3,
               WHITE );

}

void Projectile::Update() {
  Position.x += cos ( ( Rotation - 90 ) * DEG2RAD ) * DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 30;
  Position.y += sin ( ( Rotation - 90 ) * DEG2RAD ) * DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 30;
}
