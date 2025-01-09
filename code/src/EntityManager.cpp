#include "../headers/EntityManager.hpp"
#include "../headers/DefaultParameters.hpp"
#include "../headers/Entity.hpp"
#include "../headers/Projectile.hpp"
#include "../headers/Enemy.hpp"

std::shared_ptr <Entity> ProjectileFactory::Create ( ) const {
  return std::make_shared<Projectile> ( Projectile ( 10, {
    static_cast< float >( DefaultParameters::GetInstance ( )->GetRenderWidth ( ) ) / 2,
                                                         static_cast< float >( DefaultParameters::GetInstance ( )->GetRenderHeight ( ) ) / 2 },
                                                         0,
                                                         30,
                                                         1 ) );
}

std::shared_ptr<Entity> ProjectileFactory::Create ( int new_damage,
                                                    Vector2 new_position,
                                                    int new_rotation,
                                                    float new_radius,
                                                    int new_sides ) const {
  return std::make_shared<Projectile> ( Projectile ( new_damage,
                                                 new_position,
                                                 new_rotation,
                                                 new_radius,
                                                 new_sides ) );
}


std::shared_ptr<Entity> EnemyFactory::Create(int new_damage,
                                              Vector2 new_position,
                                              int new_rotation,
                                              float new_radius,
                                              int new_sides) const {
  return std::make_shared<Enemy> ( Enemy ( new_position,
                                           new_rotation,
                                           new_sides,
                                           new_radius,
                                           1,
                                           10 ) );
}


std::shared_ptr <Entity> EnemyFactory::Create ( )const {
  return std::make_shared <Enemy> ( Enemy ( { static_cast< float >( DefaultParameters::GetInstance ( )->GetRenderWidth ( ) ) / 2,
                                               static_cast< float >( DefaultParameters::GetInstance ( )->GetRenderHeight ( ) ) / 2 },
                                            0,
                                            3,
                                            DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 50,
                                            1,
                                            10
  ) );
}
