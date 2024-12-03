#include "../headers/Player.hpp"
#include "../headers/DefaultParameters.hpp"
#include "../headers/CollisionBox.hpp"
#include <stdlib.h>
#include <string>
#include <cmath>

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
  , CollisionBox ( new_radius ) {
  std::cout << "A aparut jucatorul " << PlayerName << '\n';
}

Player::Player ( const Player & other )
  : PlayerName ( other.PlayerName )
  , PlayerLevel ( other.PlayerLevel )
  , PlayerLives ( other.PlayerLives )
  , Entity ( other.Position, other.Rotation, other.Sides )
  , CollisionBox ( other.Radius ) {

  std::cout << "A fost copiat " << PlayerName << "\n";
}


Vector2 Player::GetPos ( )const {
  return this->Position;
}
int Player::GetRotation ( )const {
  return this->Rotation;
}

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
               this->Position.x + DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 50 * cos ( ( this->Rotation - 90 ) * DEG2RAD ),
               this->Position.y + DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 50 * sin ( ( this->Rotation - 90 ) * DEG2RAD ),
               WHITE );
  }
}

/// @brief Updates the position and rotation of the player.

void Player::Update ( ){

  bool rotated = false;

  if ( IsKeyDown ( KEY_UP ) ) {
    this->Position.x +=
      cos ( ( this->Rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
    this->Position.y +=
      sin ( ( this->Rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
  }
  if ( IsKeyDown ( KEY_DOWN ) ) {
    this->Position.x -=
      cos ( ( this->Rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
    this->Position.y -=
      sin ( ( this->Rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );

    if ( IsKeyDown ( KEY_RIGHT ) ) {
      this->Rotation -= 4 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
      rotated = true;
    }
    if ( IsKeyDown ( KEY_LEFT ) ) {
      this->Rotation += 4 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
      rotated = true;
    }
  }

  if ( !rotated ) {
    if ( IsKeyDown ( KEY_RIGHT ) ) {
      this->Rotation += 4 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
    }
    if ( IsKeyDown ( KEY_LEFT ) ) {
      this->Rotation -= 4 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
    }
  }

  if ( this->Rotation >= 180 )
    this->Rotation -= 360;

  if ( this->Rotation <= -180 )
    this->Rotation += 360;

  // trigger for projectile creation 

  if ( IsMouseButtonPressed ( MOUSE_BUTTON_LEFT ) || IsKeyPressed ( KEY_ENTER ) || IsKeyPressed ( KEY_SPACE ) ) {
    std::cout << "\n\n----Trage----\n\n";
  }

  // if clauses that limit the player's movement to the inside of the render window

  if ( this->Position.x < Radius / 2. )
    this->Position.x = Radius / 2.;

  if ( this->Position.x > DefaultParameters::GetInstance ( )->GetRenderWidth ( ) - Radius / 2. )
    this->Position.x = DefaultParameters::GetInstance ( )->GetRenderWidth ( ) - Radius / 2.;

  if ( this->Position.y < Radius / 2. )
    this->Position.y = Radius / 2.;

  if ( this->Position.y > DefaultParameters::GetInstance ( )->GetRenderHeight ( ) - Radius / 2. )
    this->Position.y = DefaultParameters::GetInstance ( )->GetRenderHeight ( ) - Radius / 2.;

}