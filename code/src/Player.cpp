#include "../headers/Player.hpp"
#include "../headers/DefaultParameters.hpp"
#include "../headers/CollisionBox.hpp"
#include <stdlib.h>
#include <string>
#include <cmath>

Player::Player ( const std::string & new_player_name
                 , short new_player_level
                 , short new_player_lives
                 , float new_rotation
                 , const Vector2 & new_player_position
                 , float new_radius
                 , int new_sides )
  : PlayerName ( new_player_name )
  , PlayerLevel ( new_player_level )
  , PlayerLives ( new_player_lives )
  , Entity ( new_player_position, new_rotation, new_sides )
  ,CollisionBox(new_radius){
  std::cout << "A aparut jucatorul " << PlayerName << '\n';
}

Player::Player ( const Player & other )
  : PlayerName ( other.PlayerName )
  , PlayerLevel ( other.PlayerLevel )
  , PlayerLives ( other.PlayerLives )
  , Entity ( other.position, other.rotation, other.sides )
  , CollisionBox ( other.Radius ) {

  std::cout << "A fost copiat " << PlayerName << "\n";
}


Vector2 Player::GetPos ( )const {
  return this->position;
}
int Player::GetRotation ( )const {
  return this->rotation;
}

void Player::Draw ( )const {
  if ( this->sides == 3 ) {
    DrawPolyLinesEx ( this->position, 
                      this->sides, 
                      this->Radius, 
                      this->rotation + 30, 
                      3, 
                      RED );
    DrawLine ( this->position.x,
               this->position.y,
               this->position.x + DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 50 * cos ( ( this->rotation - 90 ) * DEG2RAD ),
               this->position.y + DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 50 * sin ( ( this->rotation - 90 ) * DEG2RAD ),
               WHITE );
  }
}

/// @brief Updates the position and rotation of the player.

void Player::Update ( ){

  bool rotated = false;

  if ( IsKeyDown ( KEY_UP ) ) {
    this->position.x +=
      cos ( ( this->rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
    this->position.y +=
      sin ( ( this->rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
  }
  if ( IsKeyDown ( KEY_DOWN ) ) {
    this->position.x -=
      cos ( ( this->rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
    this->position.y -=
      sin ( ( this->rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );

    if ( IsKeyDown ( KEY_RIGHT ) ) {
      this->rotation -= 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
      rotated = true;
    }
    if ( IsKeyDown ( KEY_LEFT ) ) {
      this->rotation += 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
      rotated = true;
    }
  }

  if ( !rotated ) {
    if ( IsKeyDown ( KEY_RIGHT ) ) {
      this->rotation += 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
    }
    if ( IsKeyDown ( KEY_LEFT ) ) {
      this->rotation -= 5 * DefaultParameters::GetInstance ( )->GetMultiplier ( );
    }
  }

  if ( this->rotation >= 180 )
    this->rotation -= 360;

  if ( this->rotation <= -180 )
    this->rotation += 360;

  // trigger for projectile creation 

  if ( IsMouseButtonPressed ( MOUSE_BUTTON_LEFT ) || IsKeyPressed ( KEY_ENTER ) || IsKeyPressed ( KEY_SPACE ) ) {
    std::cout << "\n\n----Trage----\n\n";
  }

  // if clauses that limit the player's movement to the inside of the render window

  if ( this->position.x < Radius / 2. )
    this->position.x = Radius / 2.;

  if ( this->position.x > DefaultParameters::GetInstance ( )->GetRenderWidth ( ) - Radius / 2. )
    this->position.x = DefaultParameters::GetInstance ( )->GetRenderWidth ( ) - Radius / 2.;

  if ( this->position.y < Radius / 2. )
    this->position.y = Radius / 2.;

  if ( this->position.y > DefaultParameters::GetInstance ( )->GetRenderHeight ( ) - Radius / 2. )
    this->position.y = DefaultParameters::GetInstance ( )->GetRenderHeight ( ) - Radius / 2.;

}