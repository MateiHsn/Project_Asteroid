#include <iostream>
#include <raylib.h>
//#include <rlgl.h>
#include <raymath.h>

//variabilele globale trebuie mutate intr-o singura clasa + trebuie facut un singleton

static float ScreenWidth = 1920;
static float ScreenHeight = 1200;
static float DefaultRotation = 30;
//implicit, sprite-ul pt player e rotit
//la un unghi de 30 de grade spre stanga
//daca nu am adauga rotatia initiala
static int multiplier = 2;



enum
{
  MENU,
  SETTINGS,
  PLAYING,
  PAUSE,
  SHUTDOWN
};

class Projectile {
private:
  unsigned int ProjectileType;
  unsigned int ProjectileSpeed;
  unsigned int ProjectileDamage;
  Vector2 ProjectilePosition;

public:

  //constructori,destructori, operatori (pt milestone 1)

  Projectile() = default;

  Projectile(unsigned int ProjectileType, unsigned int ProjectileSpeed, unsigned int ProjectileDamage, Vector2 ProjectilePosition) {
    this->ProjectileType = ProjectileType;
    this->ProjectileSpeed = ProjectileSpeed;
    this->ProjectileDamage = ProjectileDamage;
    this->ProjectilePosition = ProjectilePosition;
  }

  Projectile(const Projectile& projectile) {
    this->ProjectileType = projectile.ProjectileType;
    this->ProjectileSpeed = projectile.ProjectileSpeed;
    this->ProjectileDamage = projectile.ProjectileDamage;
    this->ProjectilePosition = projectile.ProjectilePosition;
  }

  friend std::ostream& operator <<(std::ostream& out, const Projectile& projectile) {
    out << "Projectile type: " << projectile.ProjectileType << '\n';
    out << "Projectile damage: " << projectile.ProjectileDamage << '\n';
    out << "Projectile speed: " << projectile.ProjectileSpeed << '\n';
    out << "Pozitia proiectilului: " << projectile.ProjectilePosition.x << " " << projectile.ProjectilePosition.y << '\n';
    return out;
  }

  ~Projectile() {
    std::cout << "Proiectilul de tip " << this->ProjectileType << " a ratat sau a nimerit\n";
  }


  //update pozitie si rotatie player
  void Update(Vector2, float);
  void Draw();
  void Fire();

};



class Player {
private:
  std::string PlayerName;
  short PlayerLevel;
  unsigned short PlayerLives;
  float Rotation;
  Vector2 PlayerPosition;
public:

  Player() = default;

  Player(const std::string& PlayerName, short PlayerLevel, unsigned short PlayerLives, Vector2 PlayerPosition, float Rotation) {
    this->PlayerLevel = PlayerLevel;
    this->PlayerName = PlayerName;
    this->PlayerLives = PlayerLives;
    this->PlayerPosition = PlayerPosition;
    this->Rotation = Rotation;
  }

  Player& operator=(const Player& player) {
    this->PlayerName = player.PlayerName;
    this->PlayerLevel = player.PlayerLevel;
    this->PlayerLives = player.PlayerLives;
    this->PlayerPosition = player.PlayerPosition;
    this->Rotation = player.Rotation;

    return *this;
  }

  Player(const Player& obj) {
    this->PlayerLevel = obj.PlayerLevel;
    this->PlayerName = obj.PlayerName;
    this->PlayerLives = obj.PlayerLives;

  }

  friend std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "Player name: " << player.PlayerName << '\n';
    out << "Player level: " << player.PlayerLevel << '\n';
    out << "Player Lives " << player.PlayerLives << '\n';

    return out;
  }

  ~Player() {
    std::cout << "Jucatorul " << this->PlayerName << " a fost distrus\n";
  }


  void Draw()const;

  void Update();

  void ShowPos()const;
};



void Player::Draw() const {

  //DrawPoly(this->PlayerPosition,3,ScreenHeight/60.f,Rotation,RED);
  //DrawPoly() creeaza poligoane umplute


  //deseneaza direct poligonul doar din linii
  DrawPolyLinesEx(this->PlayerPosition, 3, ScreenHeight / 50.f, this->Rotation, 2., RED);

}

void Player::Update() {

  if (IsKeyDown(KEY_LEFT)) {
    std::cout << "Rotire la stanga\n";
    this->Rotation -= 5.f;
  }
  if (IsKeyDown(KEY_RIGHT)) {
    std::cout << "Rotire la dreapta\n";
    this->Rotation += 5.f;
  }

  //la miscarea inainte/inapoi trebuie scazut 120 din unghiul dupa care se orienteaza sprite-ul
  //pentru ca in mod normal incrementarea lui x/y duce la miscarea in dreapta/jos
  //(la fel si la mersul inapoi)
  //de asemenea argumentul de Rotation din DrawPolyLinesEx() foloseste RADIANI si nu grade
  //cu DEG2RAD din raylib

  if (IsKeyDown(KEY_UP)) {
    std::cout << "UP apasat\n";
    this->PlayerPosition.x += cos((this->Rotation - 120) * DEG2RAD) * multiplier;//fiecare update e alterat de multiplier
    this->PlayerPosition.y += sin((this->Rotation - 120) * DEG2RAD) * multiplier;//care va fi ajustabil pt toate tipurile de miscari
  }

  if (IsKeyDown(KEY_DOWN)) {
    std::cout << "DOWN apasat\n";
    this->PlayerPosition.x -= cos((this->Rotation - 120) * DEG2RAD) * multiplier;
    this->PlayerPosition.y -= sin((this->Rotation - 120) * DEG2RAD) * multiplier;
  }

  if (IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)) {
    std::cout << "Trage\n";
  }

  //check pentru ca jucatorul sa nu iasa din fereastra
  //il muta fix la margine

  if (this->PlayerPosition.x < 0)this->PlayerPosition.x = 0;
  if (this->PlayerPosition.x > ScreenWidth)this->PlayerPosition.x = ScreenWidth;
  if (this->PlayerPosition.y < 0)this->PlayerPosition.y = 0;
  if (this->PlayerPosition.y > ScreenHeight)this->PlayerPosition.y = ScreenHeight;

  this->Draw();
  this->ShowPos();
}

void Player::ShowPos() const{
  std::cout << PlayerPosition.x << ' ' << PlayerPosition.y << '\n';
}


class Enemy {
private:
  short HealthPoints;
  std::string EnemyName;
  short EnemyLevel;
  unsigned short EnemySpeed;

public:

  Enemy() = default;

  Enemy(const std::string& EnemyName, short HealthPoints, short EnemyLevel, unsigned short EnemySpeed) {
    this->EnemyName = EnemyName;
    this->EnemyLevel = EnemyLevel;
    this->HealthPoints = HealthPoints;
    this->EnemySpeed = EnemySpeed;
  }

  Enemy(const Enemy& obj) {
    this->EnemyName = obj.EnemyName;
    this->EnemyLevel = obj.EnemyLevel;
    this->HealthPoints = obj.HealthPoints;
    this->EnemySpeed = obj.EnemySpeed;
  }

  ~Enemy() {
    std::cout << "Inamicul " << this->EnemyName << " a fost distrus\n";
  }

  friend std::ostream& operator<<(std::ostream& out, const Enemy& enemy) {
    out << "Enemy name: " << enemy.EnemyName << '\n';
    out << "Enemy level: " << enemy.EnemyLevel << '\n';
    out << "Enemy HP: " << enemy.HealthPoints << '\n';
    out << "Enemy speed: " << enemy.EnemySpeed << '\n';

    return out;
  }

};

class Menu {
private:
  unsigned int state;
public:

  Menu() {
    std::cout << "Aplicatia a fost deschisa\n";
  }

  Menu(unsigned int state) {
    this->state = state;
  }

  void RunApp(Player&);

  ~Menu() {
    std::cout << "Aplicatia a fost inchisa\n";
  }
};

void Menu::RunApp(Player& player) {//la baza e game loop-ul
  
  InitWindow(ScreenWidth, ScreenHeight, "Project Asteroid");

  SetTargetFPS(60);
  HideCursor();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    player.Update();//apelul functiei care actualizeaza tot despre jucator

    EndDrawing();
  }

  CloseWindow();

}

int main() {
  Menu meniu;

  //aici sunt doar apelurile functiilor utilizarea constructorilor si a operatorilor supraincarcati
  //aici am apelat doar meniu.RunApp(p1) pentru ca restul functiilor sunt apelat in interiorul buclei de joc

  Player p1(std::string("Gigel"), 1, 5, { ScreenWidth / 2.f, ScreenHeight / 2.f }, DefaultRotation);
  std::cout << p1;

  meniu.RunApp(p1);

  Player p2 = p1;
  std::cout << p2;

  Enemy e1(std::string("Dorel"), 2, 1, 10);
  std::cout << e1;


  Projectile pr1(1, 10, 100, Vector2{ ScreenHeight / 2.f, ScreenWidth / 2.f });
  std::cout << pr1;


  return 0;
}