#include "../headers/EntityManager.hpp"

#include "../headers/Projectile.hpp"
#include "../headers/Enemy.hpp"

std::shared_ptr <Entity> ProjectileFactory::Create() const{
  return std::shared_ptr <Projectile> ( new Projectile ( ) );
}

std::shared_ptr <Entity> EnemyFactory::Create ( )const {
  return std::shared_ptr <Enemy> ( new Enemy ( ) );
}
