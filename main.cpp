#include <iostream>
#include <raylib.h>

class Player{
private:
  std::string PlayerName;
  short PlayerLevel;
  unsigned short PlayerLives;
public:

  Player()=default;

  Player(const std::string& PlayerName,short PlayerLevel,unsigned short PlayerLives,short HealthPoints){
    this->PlayerLevel=PlayerLevel;
    this->PlayerName=PlayerName;
    this->PlayerLives=PlayerLives;
  }

  Player& operator=(const Player& player){
    this->PlayerName=player.PlayerName;
    this->PlayerLevel=player.PlayerLevel;

    return *this;
  }

  Player(const Player& obj){
    this->PlayerLevel=obj.PlayerLevel;
    this->PlayerName=obj.PlayerName;
    this->PlayerLives=obj.PlayerLives;
  }

  friend std::ostream & operator<<(std::ostream &out,const Player& player){
    out<<"Player name: "<<player.PlayerName<<'\n';
    out<<"Player level: "<<player.PlayerLevel<<'\n';
    out<<"Player Lives "<<player.PlayerLives<<'\n';

    return out;
  }

  ~Player(){
    std::cout<<"Jucatorul "<<this->PlayerName<<" a fost distrus\n";
  }

};

class Enemy{
private:
  short HealthPoints;
  std::string EnemyName;
  short EnemyLevel;
  unsigned short EnemySpeed;

public:

  Enemy()=default;

  Enemy(const std::string& EnemyName,short HealthPoints,short EnemyLevel,unsigned short EnemySpeed){
    this->EnemyName=EnemyName;
    this->EnemyLevel=EnemyLevel;
    this->HealthPoints=HealthPoints;
    this->EnemySpeed=EnemySpeed;
  }

  Enemy(const Enemy& obj){
    this->EnemyName=obj.EnemyName;
    this->EnemyLevel=obj.EnemyLevel;
    this->HealthPoints=obj.HealthPoints;
    this->EnemySpeed=obj.EnemySpeed;
  }

  ~Enemy(){
    std::cout<<"Inamicul "<<this->EnemyName<<" a fost distrus\n";
  }

  friend std::ostream& operator<<(std::ostream& out,const Enemy& enemy){
    out<<"Enemy name: "<<enemy.EnemyName<<'\n';
    out<<"Enemy level: "<<enemy.EnemyLevel<<'\n';
    out<<"Enemy HP: "<<enemy.HealthPoints<<'\n';
    out<<"Enemy speed: "<<enemy.EnemySpeed<<'\n';

    return out;
  }

};

class Projectile{
private:
  std::string ProjectileType;
  unsigned int ProjectileSpeed;
  unsigned int ProjectileDamage;
public:

  Projectile()=default;

  Projectile(const std::string& ProjectileType, unsigned int ProjectileSpeed, unsigned int ProjectileDamage){
    this->ProjectileType=ProjectileType;
    this->ProjectileSpeed=ProjectileSpeed;
    this->ProjectileDamage=ProjectileDamage;
  }

  Projectile(const Projectile& projectile){
    this->ProjectileType=projectile.ProjectileType;
    this->ProjectileSpeed=projectile.ProjectileSpeed;
    this->ProjectileDamage=projectile.ProjectileDamage;
  }

  friend std::ostream& operator <<(std::ostream& out, const Projectile& projectile){
    out<<"Projectile type: "<<projectile.ProjectileType<<'\n';
    out<<"Projectile damage: "<<projectile.ProjectileDamage<<'\n';
    out<<"Projectile speed: "<<projectile.ProjectileSpeed<<'\n';

    return out;
  }

  ~Projectile(){
    std::cout<<"Proiectilul de tip "<<this->ProjectileType<<" a ratat sau a nimerit\n";
  }

};

class Menu{

};

int main(){
  Player p1("Gigel",1,5,100);
  std::cout<<p1;

  Player p2=p1;
  std::cout<<p2;

  Enemy e1("Dorel",2,1,10);
  std::cout<<e1;

  Projectile pr1("Racheta",100,10);

  const int ScreenWidth = 1920;
  const int ScreenHeight = 1200;

  InitWindow(ScreenWidth,ScreenHeight,"Chicken Invaders");

  Vector2 PlayerPosition = {-100.0f,-100.0f};
  Color PlayerColor=RED;

  SetTargetFPS(60);
  while(!WindowShouldClose()){
      PlayerPosition=GetMousePosition();

      ClearBackground(RAYWHITE);
      DrawPoly(PlayerPosition,3,100.,30.,PlayerColor);

      EndDrawing();
  }

  CloseWindow();


  return 0;
}


