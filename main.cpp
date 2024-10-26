#include <iostream>

class Player{
private:
  short HealthPoints;
  std::string PlayerName;
  short PlayerLevel;
public:

  Player()=default;
  ~Player()=default;

  Player(short HealthPoints,const std::string& PlayerName,short PlayerLevel){
    this->HealthPoints=HealthPoints;
    this->PlayerLevel=PlayerLevel;
    this->PlayerName=PlayerName;
  }

  Player& operator=(const Player& player){
    this->PlayerName=player.PlayerName;
    this->PlayerLevel=player.PlayerLevel;
    this->HealthPoints=player.HealthPoints;

    return *this;
  }

  Player(const Player& obj){
    this->HealthPoints=obj.HealthPoints;
    this->PlayerLevel=obj.PlayerLevel;
    this->PlayerName=obj.PlayerName;
  }

  friend std::ostream & operator<<(std::ostream &out,const Player& player){
    out<<"Player name: "<<player.PlayerName<<'\n';
    out<<"Player level: "<<player.PlayerLevel<<'\n';
    out<<"Player HP: "<<player.HealthPoints<<'\n';

    return out;
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
  ~Enemy()=default;

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

  friend std::ostream& operator <<(std::ostream& out, const Projectile& projectile){
    out<<"Projectile type: "<<projectile.ProjectileType<<'\n';
    out<<"Projectile damage: "<<projectile.ProjectileDamage<<'\n';
    out<<"Projectile speed: "<<projectile.ProjectileType<<'\n';

    return out;
  }

};

class Menu{
};

int main(){
  return 0;
}


