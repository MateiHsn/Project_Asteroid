#pragma once

#include <memory>
#include <string>
#include <typeinfo>
#include "./Projectile.hpp"
#include "./Enemy.hpp"


class EntityFactory{
public:
  virtual ~EntityFactory ( ) = default;
  virtual std::shared_ptr<Entity> Create ( )const = 0;
  virtual void Op ( )const {
    std::shared_ptr<Entity> e = this->Create ( );
    std::cout << "Created: " << typeid( e ).name();
  }
};

class ProjectileFactory : public EntityFactory {
public:
  std::shared_ptr<Entity> Create ( )const override;
};

class EnemyFactory : public EntityFactory {
public:
  std::shared_ptr<Entity> Create ( )const override;
};