#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#ifndef RAYLIB_H
#include <raylib.h>
#endif // !RAYLIB_H

class Player {
private:
  std::string PlayerName;
  short PlayerLevel;
  short PlayerLives;
  float Rotation;
  Vector2 PlayerPosition;
  float Radius;
  int sides;

public:
  Player ( ) = default;

  Player(const std::string& player_name
          ,short player_level
          ,short player_lives
          ,float rotation
          ,const Vector2& player_position
          ,float radius
          ,int sides)
    :PlayerName(player_name)
    ,PlayerLevel(player_level)
    ,PlayerLives(player_lives)
    ,Rotation(rotation)
    ,PlayerPosition(player_position)
    ,Radius(radius)
    ,Sides(sides)
  {
    std::cout << "A aparut jucatorul " << PlayerName << '\n';
  }

  Player ( const Player & other )
    :PlayerName ( other.PlayerName )
    , PlayerLevel ( other.PlayerLevel )
    , PlayerLives ( other.PlayerLives )
    , Rotation ( other.Rotation )
    , PlayerPosition ( other.PlayerPosition )
    , Radius ( other.Radius )
    , Sides ( other.Sides ) {
    std::cout << "A fost copiat " << PlayerName << "\n";
  }

  void GetRotation ( )const;
  void GetPos ( )const;

};

#endif