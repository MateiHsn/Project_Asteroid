#include "../headers/Player.hpp"
#include "../headers/DefaultParameters.hpp"

Player::Player ( const std::string & new_player_name
                 , short new_player_level
                 , short new_player_lives
                 , float new_rotation
                 , const Vector2 & new_player_position
                 , float new_radius
                 , int new_sides )
  : player_name( new_player_name )
  , player_level ( new_player_level )
  , player_lives( new_player_lives )
  , Entity( new_player_position , new_rotation)
  , radius ( new_radius )
  , sides ( new_sides ) {
  std::cout << "A aparut jucatorul " << player_name << '\n';
}

Player::Player ( const Player & other )
  : player_name ( other.player_name )
  , player_level ( other.player_level )
  , player_lives ( other.player_lives )
  // , rotation ( other.rotation )
  // , position ( other.position )
  , Entity ( other.position, other.rotation )
  , radius ( other.radius )
  , sides ( other.sides ) {
  std::cout << "A fost copiat " << player_name << "\n";
}


Vector2 Player::GetPos ( )const {
  return this->position;
}
int Player::GetRotation ( )const {
  return this->rotation;
}

void Player::Draw ( )const {
  if ( this->sides == 3 )
    DrawPolyLinesEx ( this->position, this->sides, this->radius, this->rotation + 30, 3, RED );
}

void Player::Update ( ) {

  bool rotated = false; // cand playerul se misca inainte sau inapoi, daca nu se
                    // previne intrarea
  // in ultima pereche de checkuri pentru rotatie, aceasta se va face de 2 ori
  // deci jucatorul se va roti de 2 ori mai mult daca se misca inainte sau inapoi
  // (ar merge lasat feature si nu bug???? hmmmmm...)
  // de aia exista bool-ul de mai sus

  if ( IsKeyDown ( KEY_UP ) ) {
    this->position.x +=
      cos ( ( this->rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::get_instance ( )->get_mul ( );
    this->position.y +=
      sin ( ( this->rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::get_instance ( )->get_mul ( );
  }
  if ( IsKeyDown ( KEY_DOWN ) ) {
    this->position.x -=
      cos ( ( this->rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::get_instance ( )->get_mul ( );
    this->position.y -=
      sin ( ( this->rotation - 90 ) * DEG2RAD ) * 5 * DefaultParameters::get_instance ( )->get_mul ( );

    if ( IsKeyDown ( KEY_RIGHT ) ) {
      this->rotation -= 5 * DefaultParameters::get_instance ( )->get_mul ( );
      rotated = true;
    }
    if ( IsKeyDown ( KEY_LEFT ) ) {
      this->rotation += 5 * DefaultParameters::get_instance ( )->get_mul ( );
      rotated = true;
    }
  }

  if ( !rotated ) {
    if ( IsKeyDown ( KEY_RIGHT ) ) {
      this->rotation += 5 * DefaultParameters::get_instance ( )->get_mul ( );
    }
    if ( IsKeyDown ( KEY_LEFT ) ) {
      this->rotation -= 5 * DefaultParameters::get_instance ( )->get_mul ( );
    }
  }

  if ( this->rotation >= 360 )
    this->rotation -= 360;

  if ( this->rotation <= -360 )
    this->rotation += 360;

  if ( IsKeyPressed ( KEY_ENTER ) || IsKeyPressed ( KEY_SPACE ) ) {
    // Projectile p1 ( 1, 10, 10, this->PlayerPosition );
    std::cout << "\n--Trage--\n";
  }

  // pentru ca jucatorul sa nu iasa din fereastra
  // trebuie impuse limite superioare/inferioare pentru unde poate ajunge
  // caracterul

  if ( this->position.x < radius / 2. )
    this->position.x = radius / 2.;

  if ( this->position.x > DefaultParameters::get_instance ( )->get_width ( ) - radius / 2. )
    this->position.x = DefaultParameters::get_instance ( )->get_width ( ) - radius / 2.;

  if ( this->position.y < radius / 2. )
    this->position.y = radius / 2.;

  if ( this->position.y > DefaultParameters::get_instance ( )->get_height ( ) - radius / 2. )
    this->position.y = DefaultParameters::get_instance ( )->get_height ( ) - radius / 2.;

  this->show_pos ( );

}

void Player::show_pos ( ) const {
  std::cout << "Pozitie "
    << this->position.x << ' '
    << this->position.y << '\t'
    << "Rotatie " <<
    this->rotation << '\n';
}

