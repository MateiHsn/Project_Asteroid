#include <iostream>
#include <raylib.h>
#include <string>
#include <iosfwd>
#include <cmath>
#include <vector>
#include <memory>

static int screen_width = 1600;
static int screen_height = 1000;

// Implicit, sprite-ul face un unghi de 30 de grade
// cu verticala

static float Multiplier = 2.f; // defineste factorul de amplificare al tuturor modificarilor din bucla de joc

enum MenuStates { MENU, SETTINGS, PLAYING, PAUSE, SHUTDOWN };

class Entity {
private:
  Vector2 Position;
  int Rotation;
public:

  virtual void GetPos ( )const = 0;
  virtual void GetRotation ( )const = 0;

};

class Projectile {
private:
  unsigned projectile_type;
  unsigned projectile_speed;
  unsigned projectile_damage;
  Vector2 projectile_position;

public:
  Projectile ( ) = default;

  Projectile ( unsigned projectile_type,
               unsigned projectile_speed,
               unsigned projectile_damage,
               const Vector2 & projectile_position )
    : projectile_type ( projectile_type )
    , projectile_speed ( projectile_speed )
    , projectile_damage ( projectile_damage )
    , projectile_position ( projectile_position ) {
    std::cout << "S-a creat proiectilul " << this->projectile_type << '\n';
  }

  Projectile ( const Projectile & other )
    : projectile_type ( other.projectile_type )
    , projectile_speed ( other.projectile_speed )
    , projectile_damage ( other.projectile_damage )
    , projectile_position ( other.projectile_position ) {
    std::cout << "S-a copiat proiectilul " << this->projectile_type << '\n';
  }

  Projectile & operator=( const Projectile & other ) {
    if ( this == &other )
      return *this;
    projectile_type = other.projectile_type;
    projectile_speed = other.projectile_speed;
    projectile_damage = other.projectile_damage;
    projectile_position = other.projectile_position;
    return *this;
  }

  static friend std::ostream & operator<<( std::ostream & os, const Projectile & obj ) {
    return os << "ProjectyleType: " << obj.projectile_type
      << "\nProjectyleSpeed: " << obj.projectile_speed
      << "\nProjectileDamage: " << obj.projectile_damage
      << "\nProjectilePosition.x: " << obj.projectile_position.x
      << "\nProjectilePosition.y: " << obj.projectile_position.y << '\n';
  }

  ~Projectile ( ) { std::cout << "Proiectilul a fost ratat\n"; }
};

class Player {
private:
  std::string player_name;
  short player_level;
  short player_lives;
  int rotation;
  Vector2 player_position;
  float radius;
  int sides;

public:
  Player ( ) = default;

  Player ( const std::string & player_name,
           short player_level,
           short player_live,
           int rotation,
           const Vector2 & player_position,
           float radius,
           int sides )
    : player_name ( player_name )
    , player_level ( player_level )
    , player_lives ( player_live )
    , rotation ( rotation )
    , player_position ( player_position )
    , radius ( radius )
    , sides ( sides ) {
    std::cout << "A fost creat jucatorul " << this->player_name << '\n';
  }

  Player ( const Player & other )
    : player_name { other.player_name }
    , player_level { other.player_level }
    , player_lives { other.player_lives }
    , rotation { other.rotation }
    , player_position { other.player_position }
    , radius { other.radius }
    , sides { other.sides } {
    std::cout << "A fost copiat jucatorul " << this->player_name << '\n';
  }

  Player & operator=( const Player & other ) {
    if ( this == &other )
      return *this;
    player_name = other.player_name;
    player_level = other.player_level;
    player_lives = other.player_lives;
    rotation = other.rotation;
    player_position = other.player_position;
    radius = other.radius;
    sides = other.sides;
    return *this;
  }

  static friend std::ostream & operator<<( std::ostream & os, const Player & obj ) {
    return os << "PlayerName: " << obj.player_name << '\n'
      << " PlayerLevel: " << obj.player_level << '\n'
      << " PlayerLive: " << obj.player_lives << '\n'
      << " Rotation: " << obj.rotation << '\n'
      << " PlayerPosition: " << obj.player_position.x << ' '
      << obj.player_position.y << '\n'
      << " Radius: " << obj.radius << '\n'
      << " Sides: " << obj.sides << '\n';
  }

  ~Player ( ) { std::cout << "Jucator distrus\n"; }

  void Draw ( ) const;

  void Update ( );

  Vector2 GetPos ( ) const;

  void ShowPos ( ) const;
};


void
Player::Draw ( ) const {
  DrawPolyLinesEx (
    this->player_position, this->sides, this->radius, this->rotation + 30, 2, RED );
  DrawLineV ( this->player_position,
              { this->player_position.x + static_cast< float >( screen_width / 40 ) * cos ( ( rotation - 90 ) * DEG2RAD ),
                 this->player_position.y + static_cast< float >( screen_width / 40 ) * sin ( ( rotation - 90 ) * DEG2RAD ) },
              WHITE );
}

void
Player::Update ( ) {

  bool rotated = false; // cand playerul se misca inainte sau inapoi, daca nu se
                    // previne intrarea
  // in ultima pereche de checkuri pentru rotatie, aceasta se va face de 2 ori
  // deci jucatorul se va roti de 2 ori mai mult daca se misca inainte sau inapoi
  // (ar merge lasat feature si nu bug???? hmmmmm...)
  // de aia exista bool-ul de mai sus

  if ( IsKeyDown ( KEY_UP ) ) {
    this->player_position.x +=
      cos ( ( this->rotation - 90 ) * DEG2RAD ) * 2.5 * Multiplier;
    this->player_position.y +=
      sin ( ( this->rotation - 90 ) * DEG2RAD ) * 2.5 * Multiplier;
  }
  if ( IsKeyDown ( KEY_DOWN ) ) {
    this->player_position.x -=
      cos ( ( this->rotation - 90 ) * DEG2RAD ) * 2.5 * Multiplier;
    this->player_position.y -=
      sin ( ( this->rotation - 90 ) * DEG2RAD ) * 2.5 * Multiplier;

    if ( IsKeyDown ( KEY_RIGHT ) ) {
      this->rotation -= 2.5 * Multiplier;
      rotated = true;
    }
    if ( IsKeyDown ( KEY_LEFT ) ) {
      this->rotation += 2.5 * Multiplier;
      rotated = true;
    }
  }

  if ( !rotated ) {
    if ( IsKeyDown ( KEY_RIGHT ) ) {
      this->rotation += 2.5 * Multiplier;
    }
    if ( IsKeyDown ( KEY_LEFT ) ) {
      this->rotation -= 2.5 * Multiplier;
    }
  }

  if ( this->rotation >= 180 )
    this->rotation -= 360;

  if ( this->rotation <= -180 )
    this->rotation += 360;

  if ( IsKeyPressed ( KEY_ENTER ) || IsKeyPressed ( KEY_SPACE ) ) {
    // Projectile p1 ( 1, 10, 10, this->PlayerPosition );
    std::cout << "\n--Trage--\n";
  }

  // pentru ca jucatorul sa nu iasa din fereastra
  // trebuie impuse limite superioare/inferioare pentru unde poate ajunge
  // caracterul

  if ( this->player_position.x < radius / 2. )
    this->player_position.x = radius / 2.;

  if ( this->player_position.x > screen_width - radius / 2. )
    this->player_position.x = screen_width - radius / 2.;

  if ( this->player_position.y < radius / 2. )
    this->player_position.y = radius / 2.;

  if ( this->player_position.y > screen_height - radius / 2. )
    this->player_position.y = screen_height - radius / 2.;

  this->ShowPos ( );
}

void
Player::ShowPos ( ) const {
  std::cout << "Pozitie: " << this->player_position.x << ' '
    << this->player_position.y << "   Rotatie" << this->rotation << '\n';
}

Vector2
Player::GetPos ( ) const {
  return this->player_position;
}

class Enemy {
private:
  std::string EnemyName;
  short HealthPoints;
  short EnemyLevel;
  short EnemySpeed;

public:
  Enemy ( ) = default;

  Enemy ( const std::string & enemy_name,
          short health_points,
          short enemy_level,
          short enemy_speed )
    : EnemyName ( enemy_name )
    , HealthPoints ( health_points )
    , EnemyLevel ( enemy_level )
    , EnemySpeed ( enemy_speed ) {
    std::cout << "Inamicul " << this->EnemyName << " a fost creat\n";
  }

  Enemy ( const Enemy & other )
    : EnemyName { other.EnemyName }
    , HealthPoints { other.HealthPoints }
    , EnemyLevel { other.EnemyLevel }
    , EnemySpeed { other.EnemySpeed } {
    std::cout << "S-a copiat inamicul " << this->EnemyName << '\n';
  }

  Enemy & operator=( const Enemy & other ) {
    if ( this == &other )
      return *this;
    EnemyName = other.EnemyName;
    HealthPoints = other.HealthPoints;
    EnemyLevel = other.EnemyLevel;
    EnemySpeed = other.EnemySpeed;
    return *this;
  }

  static friend std::ostream & operator<<( std::ostream & os, const Enemy & obj ) {
    return os
      << "EnemyName: " << obj.EnemyName
      << "\nHealthPoints: " << obj.HealthPoints
      << "\nEnemyLevel: " << obj.EnemyLevel
      << "\nEnemySpeed: " << obj.EnemySpeed;
  }

  ~Enemy ( ) { std::cout << "Inamic Distrus\n"; }
};

class Menu {
private:
  char state;

public:
  Menu ( ) = default;

  Menu ( char state )
    : state ( state ) {
    std::cout << "S-a creat meniul " << this->state << '\n';
  }

  void UpdateMenuState ( char new_state );

  static friend std::ostream & operator<<( std::ostream & os, const Menu & obj ) {
    return os << "state: " << obj.state;
  }

  void RunApp ( std::shared_ptr<Player> &, std::vector<Projectile> & );

  ~Menu ( ) { std::cout << "Gata cu fotosinteza, la culcare toata lumea!\n"; };
};

void
Menu::RunApp ( std::shared_ptr<Player> & player, std::vector<Projectile> & projectile_vector ) {

  SetExitKey ( KEY_NULL );

  bool ExitWindowRequested = false;
  bool ExitWindow = false;
  InitWindow ( screen_width, screen_height, "Project Asteroid" );
  SetTargetFPS ( 90 ); // am pus 90 deoarece display-ul meu e pe 90Hz :P
  HideCursor ( ); // inca nu am implementat meniul propriu-zis ca sa am nevoie de un cursor
  // cursorul o sa fie un sprite (nu-l voi lasa pe cel default)

  // tot ce e descris in while
  // defineste felul in care este manipulata iesirea din fereastra/joc

  while ( !ExitWindow ) {
    BeginDrawing ( );
    if ( WindowShouldClose ( ) || IsKeyPressed ( KEY_ESCAPE ) )
      ExitWindowRequested = true,
      UpdateMenuState ( PAUSE );

    if ( ExitWindowRequested ) {
      if ( IsKeyPressed ( KEY_Y ) )
        ExitWindow = true;
      if ( IsKeyPressed ( KEY_N ) )
        ExitWindowRequested = false,
        UpdateMenuState ( PLAYING );
    }

    BeginDrawing ( );

    if ( ExitWindowRequested ) {
      const char * ExitMessage = "Are you sure you want to exit the game? [Y/N]";
      DrawRectangle (
        0, screen_height / 3., screen_width, screen_height / 10., RAYWHITE );
      DrawText ( ExitMessage,
                 screen_width / 2 - MeasureText ( ExitMessage, 30 ) / 2,
                 screen_height * 9 / 24,
                 30,
                 BLACK );
    } else {
      ClearBackground ( BLACK );
      player->Update ( ); // apel catre functia de update pentru player
      player->Draw ( ); // apel metoda 
    }
    EndDrawing ( );

  }

  CloseWindow ( );
}

void Menu::UpdateMenuState ( char new_state ) {
  this->state = new_state;
  std::cout << "Noua stare a meniului " << this->state + '0' << '\n';
}


int
main ( ) {

  std::shared_ptr < Player > player ( new Player("Gigel",
                                      1,
                                      5,
                                      0,
                                      {static_cast<float>(screen_width/2), static_cast<float>(screen_height/2)},
                                      screen_width/60,
                                      3));
                                      
  std::vector <Projectile> projectile_vector;

  projectile_vector.push_back ( Projectile ( 1, 10, 50, player->GetPos ( ) ) );

  std::shared_ptr < Menu > menu = std::make_unique<Menu> ( 1 );

  menu->RunApp ( player, projectile_vector );

}