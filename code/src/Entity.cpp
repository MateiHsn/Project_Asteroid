#include "../headers/Entity.hpp"

Entity::Entity ( Vector2 new_position,
                 int new_rotation,
                 int new_sides )
  :Position ( new_position )
  , Rotation ( new_rotation )
  , Sides ( new_sides ) { }

void Entity::Draw() const {  }

Vector2 Entity::GetPos ( ) const { return Position; }

int Entity::GetRotation ( ) const { return Rotation; }

void Entity::Update() {  }