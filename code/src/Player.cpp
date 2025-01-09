#include "../headers/Player.hpp"
#include "../headers/DefaultParameters.hpp"
#include "../headers/CollisionBox.hpp"
#include "../headers/Entity.hpp"
#include <string>
#include <cmath>
#include <memory>

#include "../headers/EntityManager.hpp"



Player::Player ( const std::string & new_player_name
                 , short new_player_level
                 , short new_player_lives
                 , int new_rotation
                 , const Vector2 & new_player_position
                 , float new_radius
                 , int new_sides )
  : PlayerName ( new_player_name )
  , PlayerLevel ( new_player_level )
  , PlayerLives ( new_player_lives )
  , Entity ( new_player_position, new_rotation, new_sides )
  , CollisionBox ( new_radius ) { }

Player::Player ( const Player & other )
  : PlayerName ( other.PlayerName )
  , PlayerLevel ( other.PlayerLevel )
  , PlayerLives ( other.PlayerLives )
  , Entity ( other.Position, other.Rotation, other.Sides )
  , CollisionBox ( other.Radius ) { }




/// <summary>
/// Returns the position of the Player object as a Vector2 struct variable.
/// </summary>
/// <returns>this->Position</returns>
Vector2 Player::GetPos ( )const { return this->Position; }



int Player::GetRotation ( )const { return this->Rotation; }

/// <summary>
/// Draws the player sprite.
/// </summary>
void Player::Draw ( )const {
  if ( this->Sides == 3 ) {
    DrawPolyLinesEx ( this->Position,
                      this->Sides,
                      this->Radius,
                      this->Rotation + 30,
                      3,
                      RED );
    DrawLine ( this->Position.x,
               this->Position.y,
               this->Position.x + DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 50 * cos (
                 ( this->Rotation - 90 ) * DEG2RAD ),
               this->Position.y + DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 50 * sin (
                 ( this->Rotation - 90 ) * DEG2RAD ),
               WHITE );
  }
}




/// <summary>
/// Updates the player's position and rotation and creates new projectiles if the player fires.
/// </summary>
/// <param name="nps"></param>
void Player::Update ( std::vector<std::shared_ptr<Entity>> & nps ) {

  bool rotated = false;

  if ( IsKeyDown ( KEY_UP ) || IsKeyDown ( KEY_A ) ) {
    Position.x +=
      cos ( ( Rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
    Position.y +=
      sin ( ( Rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
  }
  if ( IsKeyDown ( KEY_DOWN ) || IsKeyDown ( KEY_S ) ) {
    Position.x -=
      cos ( ( Rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
    Position.y -=
      sin ( ( Rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );

    if ( IsKeyDown ( KEY_RIGHT ) || IsKeyDown ( KEY_D ) ) {
      Rotation -= 4 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
      rotated = true;
    }
    if ( IsKeyDown ( KEY_LEFT ) || IsKeyDown ( KEY_A ) ) {
      Rotation += 4 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
      rotated = true;
    }
  }

  if ( !rotated ) {
    if ( IsKeyDown ( KEY_RIGHT ) || IsKeyDown ( KEY_D ) ) {
      Rotation += 4 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
    }
    if ( IsKeyDown ( KEY_LEFT ) || IsKeyDown ( KEY_A ) ) {
      Rotation -= 4 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
    }
  }

  if ( Rotation >= 180 )
    Rotation -= 360;

  if ( Rotation <= -180 )
    Rotation += 360;

  // if clauses that limit the player's movement to the inside of the render window

  if ( Position.x < Radius / 2. )
    Position.x = Radius / 2.;

  if ( Position.x > DefaultParameters::GetInstance ( )->GetRenderWidth ( ) - Radius / 2. )
    Position.x = DefaultParameters::GetInstance ( )->GetRenderWidth ( ) - Radius / 2.;

  if ( Position.y < Radius / 2. )
    Position.y = Radius / 2.;

  if ( Position.y > DefaultParameters::GetInstance ( )->GetRenderHeight ( ) - Radius / 2. )
    Position.y = DefaultParameters::GetInstance ( )->GetRenderHeight ( ) - Radius / 2.;

  // trigger for projectile creation 

  const std::shared_ptr<EntityFactory> Factory = std::make_unique<ProjectileFactory> ( ProjectileFactory ( ) );

  if ( IsKeyPressed ( KEY_SPACE ) || IsMouseButtonPressed ( MOUSE_BUTTON_LEFT ) ) {
    nps.push_back ( Factory->Create ( 1,
                                      this->Position,
                                      this->Rotation,
                                      this->Radius / 2,
                                      1 ) );

    nps.back ( )->Draw ( );
  }
}