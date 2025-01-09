#pragma once

#include <memory>
#include <string>
#include <typeinfo>
#include "./Entity.hpp"
#include "./Projectile.hpp"
#include "./Enemy.hpp"


class EntityFactory{
public:
  virtual ~EntityFactory ( ) = default;
  virtual std::shared_ptr<Entity> Create ( )const = 0;

  virtual std::shared_ptr<Entity> Create ( int new_damage,
                        Vector2 new_position,
                        int new_rotation,
                        float new_radius,
                        int new_sides)const = 0;
  virtual void Op ( )const {
    std::shared_ptr<Entity> e = this->Create ( );

    std::shared_ptr<Projectile> e1 = std::dynamic_pointer_cast<Projectile>(e);
    std::shared_ptr<Enemy> e2 = std::dynamic_pointer_cast<Enemy>(e);

    if( e1 ) {
      std::cout << "Created: Projectile " << typeid( e1 ).name ( ) << '\n';
    }
    if(e2) {
      std::cout << "Created: Enemy " << typeid( e2 ).name ( ) << '\n';
    }
  }

};

class ProjectileFactory : public EntityFactory {
public:

  ProjectileFactory ( ) :EntityFactory ( ) { }

  std::shared_ptr<Entity> Create ( )const override;

  std::shared_ptr<Entity> Create(int new_damage,
                                  Vector2 new_position,
                                  int new_rotation,
                                  float new_radius,
                                  int new_sides) const override;

};

class EnemyFactory : public EntityFactory {
public:
  std::shared_ptr<Entity> Create ( )const override;

  std::shared_ptr<Entity> Create ( int new_damage,
                                   Vector2 new_position,
                                   int new_rotation,
                                   float new_radius,
                                   int new_sides ) const override;
};