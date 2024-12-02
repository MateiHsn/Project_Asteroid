#pragma once


#include "Entity.hpp"
#include "CollisionBox.hpp"

class Enemy :public Entity, public CollisionBox{
private:
  int enemy_level;
  int enemy_health_points;
public:
  
};
