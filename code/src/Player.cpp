#include "../headers/Player.h"

Player::Player ( const std::string & player_name
         , short player_level
         , short player_lives
         , float rotation
         , const Vector2 & player_position
         , float radius
         , int sides )
  :PlayerName ( player_name )
  , PlayerLevel ( player_level )
  , PlayerLives ( player_lives )
  , Rotation ( rotation )
  , PlayerPosition ( player_position )
  , Radius ( radius )
  , Sides ( sides ) {
  std::cout << "A aparut jucatorul " << PlayerName << '\n';
}

Player::Player ( const Player & other )
  :PlayerName ( other.PlayerName )
  , PlayerLevel ( other.PlayerLevel )
  , PlayerLives ( other.PlayerLives )
  , Rotation ( other.Rotation )
  , PlayerPosition ( other.PlayerPosition )
  , Radius ( other.Radius )
  , Sides ( other.Sides ) {
  std::cout << "A fost copiat " << PlayerName << "\n";
}


Vector2 Player::GetPos ( )const override{
  return this->PlayerPosition;
}
int Player::GetRotation ( )const override{
  return this->Rotation;
}

void Player::Update ( std::vector<Projectile> ) {

  bool rotated = false; // cand playerul se misca inainte sau inapoi, daca nu se
                    // previne intrarea
  // in ultima pereche de checkuri pentru rotatie, aceasta se va face de 2 ori
  // deci jucatorul se va roti de 2 ori mai mult daca se misca inainte sau inapoi
  // (ar merge lasat feature si nu bug???? hmmmmm...)
  // de aia exista bool-ul de mai sus

  if ( IsKeyDown ( KEY_UP ) ) {
    this->PlayerPosition.x +=
      cos ( ( this->Rotation - 90 ) * DEG2RAD ) * 2.5 * Multiplier;
    this->PlayerPosition.y +=
      sin ( ( this->Rotation - 90 ) * DEG2RAD ) * 2.5 * Multiplier;
  }
  if ( IsKeyDown ( KEY_DOWN ) ) {
    this->PlayerPosition.x -=
      cos ( ( this->Rotation - 90 ) * DEG2RAD ) * 2.5 * Multiplier;
    this->PlayerPosition.y -=
      sin ( ( this->Rotation - 90 ) * DEG2RAD ) * 2.5 * Multiplier;

    if ( IsKeyDown ( KEY_RIGHT ) ) {
      this->Rotation -= 2.5 * Multiplier;
      rotated = true;
    }
    if ( IsKeyDown ( KEY_LEFT ) ) {
      this->Rotation += 2.5 * Multiplier;
      rotated = true;
    }
  }

  if ( !rotated ) {
    if ( IsKeyDown ( KEY_RIGHT ) ) {
      this->Rotation += 2.5 * Multiplier;
    }
    if ( IsKeyDown ( KEY_LEFT ) ) {
      this->Rotation -= 2.5 * Multiplier;
    }
  }

  if ( this->Rotation >= 360 )
    this->Rotation -= 360;

  if ( this->Rotation <= -360 )
    this->Rotation += 360;

  if ( IsKeyPressed ( KEY_ENTER ) || IsKeyPressed ( KEY_SPACE ) ) {
    // Projectile p1 ( 1, 10, 10, this->PlayerPosition );
    std::cout << "\n--Trage--\n";
  }

  // pentru ca jucatorul sa nu iasa din fereastra
  // trebuie impuse limite superioare/inferioare pentru unde poate ajunge
  // caracterul

  if ( this->PlayerPosition.x < Radius / 2. )
    this->PlayerPosition.x = Radius / 2.;

  if ( this->PlayerPosition.x > ScreenWidth - Radius / 2. )
    this->PlayerPosition.x = ScreenWidth - Radius / 2.;

  if ( this->PlayerPosition.y < Radius / 2. )
    this->PlayerPosition.y = Radius / 2.;

  if ( this->PlayerPosition.y > ScreenHeight - Radius / 2. )
    this->PlayerPosition.y = ScreenHeight - Radius / 2.;

  this->ShowPos ( );

}

