#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H
#include <raylib.h>
#include <iostream>

static float Multiplier = 2.f;

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
  Player()=default;

  Player(const std::string& player_name,
         short player_level,
         short player_lives,
         float rotation,
         const Vector2& player_position,
         float radius,
         int sides)
    : PlayerName(player_name)
    , PlayerLevel(player_level)
    , PlayerLives(player_lives)
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
  ~Player()=default;

  void Draw()const;
  void Update();
  Vector2 GetPos() const;
  void ShowPos() const;
};

#endif