#ifndef OOP_PROJECTILE_H
#define OOP_PROJECTILE_H

#ifndef RAYLIB_H
#include <raylib.h>
#endif 

#include <iostream>


class Projectile {
private:
  char ProjectileType;
  char ProjectileSpeed;
  char ProjectileDamage;
  Vector2 ProjectilePosition;
  float Rotation;
public:
  Projectile ( );
  Projectile ( char projectile_type, char projectile_speed,
               char projectile_damage, const Vector2 & projectile_position,
               float rotation )
    : ProjectileType ( projectile_type ),
    ProjectileSpeed ( projectile_speed ),
    ProjectileDamage ( projectile_damage ),
    ProjectilePosition ( projectile_position ),
    Rotation ( rotation ) {
    std::cout << "S-a lansat proiectilul" << this->ProjectileType << '\n';
  }

  friend std::ostream & operator<<( std::ostream & out, const Projectile & obj ) {
    return out << "Projectile type: " << obj.ProjectileType
      << "\nProjectile speed: " << obj.ProjectileSpeed
      << "\nProjectile damage : " << obj.ProjectileDamage
      << "\nprojectile x: " << obj.ProjectilePosition.x
      << "\nProjectile y: " << obj.ProjectilePosition.y << '\n';
  }

  ~Projectile ( ) {
    std::cout << "Proiectilul " << this->ProjectileType << " a nimerit\n";
  }

  void Update ( );
  void Draw ( );

};

#endif