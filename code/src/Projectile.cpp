#include "../headers/Projectile.h"

void Projectile::Update ( ) {

  this->ProjectilePosition.x += 30 * cos ( ( Rotation - 120 ) * DEG2RAD );
  this->ProjectilePosition.y += 30 * sin ( ( Rotation - 120 ) * DEG2RAD );

}