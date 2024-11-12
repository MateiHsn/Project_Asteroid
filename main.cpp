#include <iostream>
#include <raylib.h>
// #include <raymath.h>
#include <cmath>

static float ScreenWidth = 1280;
static float ScreenHeight = 720;
static float DefaultRotation = 30;

// Implicit, sprite-ul face un unghi de 30 de grade
// cu verticala

static float Multiplier = 2.f; // de variabila asta depinde factorul de multiplicare al tuturor variatilor
//

//Inceput implementare clasa singleton pentru a nu a mai tine parametrii impliciti ca variabile globale

class DefaultParameters {
  private:
  float ScreenWidth;
  float ScreenHeight;
  float DefaultRotation;
  float Multiplier;
  static DefaultParameters * InstancePtr;
  DefaultParameters ( );

  public:

  DefaultParameters ( float ScreenWidth = 1920,
                      float ScreenHeight = 1080,
                      float DefaultRotation = 30,
                      float Multiplier = 2 )
    : ScreenWidth ( ScreenWidth )
    , ScreenHeight ( ScreenHeight )
    , DefaultRotation ( DefaultRotation )
    , Multiplier ( Multiplier ) { }

  DefaultParameters ( const DefaultParameters & obj ) = delete;

};

enum { MENU, SETTINGS, PLAYING, PAUSE, SHUTDOWN };

class Projectile
{
private:
  unsigned ProjectileType;
  unsigned ProjectileSpeed;
  unsigned ProjectileDamage;
  Vector2 ProjectilePosition;

public:
  Projectile() = default;

  Projectile(unsigned projectile_type,
             unsigned projectile_speed,
             unsigned projectile_damage,
             const Vector2& projectile_position)
    : ProjectileType(projectile_type)
    , ProjectileSpeed(projectile_speed)
    , ProjectileDamage(projectile_damage)
    , ProjectilePosition(projectile_position)
  {
    std::cout << "S-a creat proiectilul " << this->ProjectileType << '\n';
  }

  Projectile(const Projectile& other)
    : ProjectileType(other.ProjectileType)
    , ProjectileSpeed(other.ProjectileSpeed)
    , ProjectileDamage(other.ProjectileDamage)
    , ProjectilePosition(other.ProjectilePosition)
  {
    std::cout << "S-a copiat proiectilul " << this->ProjectileType << '\n';
  }

  Projectile& operator=(const Projectile& other)
  {
    if (this == &other)
      return *this;
    ProjectileType = other.ProjectileType;
    ProjectileSpeed = other.ProjectileSpeed;
    ProjectileDamage = other.ProjectileDamage;
    ProjectilePosition = other.ProjectilePosition;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Projectile& obj)
  {
    return os << "ProjectyleType: " << obj.ProjectileType
              << "\nProjectyleSpeed: " << obj.ProjectileSpeed
              << "\nProjectileDamage: " << obj.ProjectileDamage
              << "\nProjectilePosition.x: " << obj.ProjectilePosition.x
              << "\nProjectilePosition.y: " << obj.ProjectilePosition.y << '\n';
  }

  ~Projectile() { std::cout << "Proiectilul a fost ratat\n"; }
};

class Player
{
private:
  std::string PlayerName;
  short PlayerLevel;
  short PlayerLives;
  float Rotation;
  Vector2 PlayerPosition;
  float Radius;
  int Sides;

public:
  Player() = default;

  Player(const std::string& player_name,
         short player_level,
         short player_live,
         float rotation,
         const Vector2& player_position,
         float radius,
         int sides)
    : PlayerName(player_name)
    , PlayerLevel(player_level)
    , PlayerLives(player_live)
    , Rotation(rotation)
    , PlayerPosition(player_position)
    , Radius(radius)
    , Sides(sides)
  {
    std::cout << "A fost creat jucatorul " << this->PlayerName << '\n';
  }

  Player(const Player& other)
    : PlayerName{ other.PlayerName }
    , PlayerLevel{ other.PlayerLevel }
    , PlayerLives{ other.PlayerLives }
    , Rotation{ other.Rotation }
    , PlayerPosition{ other.PlayerPosition }
    , Radius{ other.Radius }
    , Sides{ other.Sides }
  {
    std::cout << "A fost copiat jucatorul " << this->PlayerName << '\n';
  }

  Player& operator=(const Player& other)
  {
    if (this == &other)
      return *this;
    PlayerName = other.PlayerName;
    PlayerLevel = other.PlayerLevel;
    PlayerLives = other.PlayerLives;
    Rotation = other.Rotation;
    PlayerPosition = other.PlayerPosition;
    Radius = other.Radius;
    Sides = other.Sides;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Player& obj)
  {
    return os << "PlayerName: " << obj.PlayerName << '\n'
              << " PlayerLevel: " << obj.PlayerLevel << '\n'
              << " PlayerLive: " << obj.PlayerLives << '\n'
              << " Rotation: " << obj.Rotation << '\n'
              << " PlayerPosition: " << obj.PlayerPosition.x << ' '
              << obj.PlayerPosition.y << '\n'
              << " Radius: " << obj.Radius << '\n'
              << " Sides: " << obj.Sides << '\n';
  }

  ~Player() { std::cout << "Jucator distrus\n"; }

  void Draw() const;

  void Update();

  Vector2 GetPos() const;

  void ShowPos() const;
};


void
Player::Draw() const
{
  DrawPolyLinesEx(
    this->PlayerPosition, this->Sides, this->Radius, this->Rotation, 2, RED);
}

void
Player::Update()
{
  bool rotated = 0; // cand playerul se misca inainte sau inapoi, daca nu se
                    // previne intrarea
  // in ultima pereche de checkuri pentru rotatie, aceasta se va face de 2 ori
  // deci jucatorul se va roti de 2 ori mai mult daca se misca inainte-inapoi
  // (ar merge lasat feature si nu bug???? hmmmmm...)
  // de aia exista bool-ul asta
  if (IsKeyDown(KEY_UP)) {
    this->PlayerPosition.x +=
      cos((this->Rotation - 120) * DEG2RAD) * 1.5 * Multiplier;
    this->PlayerPosition.y +=
      sin((this->Rotation - 120) * DEG2RAD) * 1.5 * Multiplier;
    /*
    if (IsKeyDown(KEY_RIGHT)) {
      this->Rotation += 2 * Multiplier;
      rotated = true;
    }
    if (IsKeyDown(KEY_LEFT)) {
      this->Rotation -= 2 * Multiplier;
      rotated = true;
    }
    */
  }
  if (IsKeyDown(KEY_DOWN)) {
    this->PlayerPosition.x -=
      cos((this->Rotation - 120) * DEG2RAD) * 1.5 * Multiplier;
    this->PlayerPosition.y -=
      sin((this->Rotation - 120) * DEG2RAD) * 1.5 * Multiplier;

    if (IsKeyDown(KEY_RIGHT)) {
      this->Rotation -= 2 * Multiplier;
      rotated = true;
    }
    if (IsKeyDown(KEY_LEFT)) {
      this->Rotation += 2 * Multiplier;
      rotated = true;
    }
  }

  if (!rotated) {
    if (IsKeyDown(KEY_RIGHT)) {
      this->Rotation += 2 * Multiplier;
    }
    if (IsKeyDown(KEY_LEFT)) {
      this->Rotation -= 2 * Multiplier;
    }
  }

  if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
    Projectile p1(1, 10, 10, this->PlayerPosition);
    std::cout << "\n\n\n--Trage--\n\n\n";
  }

  // pentru ca jucatorul sa nu iasa din fereastra
  // trebuie impuse limite superioare/inferioare pentru unde poate ajunge
  // caracterul

  if (this->PlayerPosition.x < Radius / 2.)
    this->PlayerPosition.x = Radius / 2.;
  if (this->PlayerPosition.x > ScreenWidth - Radius / 2.)
    this->PlayerPosition.x = ScreenWidth - Radius / 2.;
  if (this->PlayerPosition.y < Radius / 2.)
    this->PlayerPosition.y = Radius / 2.;
  if (this->PlayerPosition.y > ScreenHeight - Radius / 2.)
    this->PlayerPosition.y = ScreenHeight - Radius / 2.;

  this->Draw();
  this->ShowPos();
}

void
Player::ShowPos() const
{
  std::cout << "Pozitie: " << this->PlayerPosition.x << ' '
            << this->PlayerPosition.y << '\n';
}

Vector2
Player::GetPos() const
{
  return this->PlayerPosition;
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
    if (this == &other)
      return *this;
    EnemyName = other.EnemyName;
    HealthPoints = other.HealthPoints;
    EnemyLevel = other.EnemyLevel;
    EnemySpeed = other.EnemySpeed;
    return *this;
  }

  friend std::ostream & operator<<( std::ostream & os, const Enemy & obj ) {
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

  friend std::ostream & operator<<( std::ostream & os, const Menu & obj ) {
    return os << "state: " << obj.state;
  }

  static void RunApp ( Player & );

  ~Menu ( ) { std::cout << "Gata cu fotosinteza, la culcare toata lumea!\n"; };
};

void
Menu::RunApp ( Player & player ) {
  SetExitKey ( KEY_NULL );

  bool ExitWindowRequested = false;
  bool ExitWindow = false;

  InitWindow ( ScreenWidth, ScreenHeight, "Project Asteroid" );
  SetTargetFPS ( 60 );
  HideCursor ( );

  while (!ExitWindow) {
    if (WindowShouldClose ( ) || IsKeyPressed ( KEY_ESCAPE )) ExitWindowRequested = true;

    if (ExitWindowRequested) {
      if (IsKeyPressed ( KEY_Y ))
        ExitWindow = true;
      if (IsKeyPressed ( KEY_N ))
        ExitWindowRequested = false;
    }

    BeginDrawing ( );

    if (ExitWindowRequested) {
      DrawRectangle (
        0, ScreenHeight / 3., ScreenWidth, ScreenHeight / 10., RAYWHITE );
      DrawText ( "Are you sure you want to exit the game? [Y/N]",
                 ScreenWidth / 2,
                 ScreenHeight * 9 / 24,
                 30,
                 BLACK );
    }
    else {
      player.Update ( ); // apel catre functia de update pentru player
    }


    ClearBackground ( BLACK );

    EndDrawing ( );
  }

  CloseWindow ( );
}

int
main ( ) {

  Player p1 ( "Gigel",
              1,
              5,
              DefaultRotation,
              { ScreenWidth / 2.f, ScreenHeight / 2.f },
              ScreenWidth / 60.,
              3 );

  std::cout << p1;

  Menu meniu ( 1 );

  Menu::RunApp ( p1 );

  Player * p2 = &p1;

  std::cout << p2;

  Enemy e1 ( "Dorel", 10, 2, 100 );

  std::cout << e1;

  Projectile pr1 ( 1, 10, 50, p1.GetPos ( ) );
  std::cout << pr1;
}




