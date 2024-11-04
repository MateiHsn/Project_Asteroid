#include "Player.hpp"

void
Player::Draw() const
{
  DrawPolyLinesEx(this->PlayerPosition, this->Sides, this->Radius, 2, RED);
}

void
Player::Draw() const
{
  DrawPolyLinesEx(
    this->PlayerPosition, this->Sides, this->Radius, this->Rotation, 2, RED);
}

void
Player::ShowPos() const { std::cout << "X: " << this.PlayerPosition.x << " Y: "<<this.Player }

Vector2
Player::GetPos() const
{
  return this->PlayerPosition;
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

    if (IsKeyDown(KEY_RIGHT)) {
      this->Rotation += 2 * Multiplier;
      rotated = true;
    }
    if (IsKeyDown(KEY_LEFT)) {
      this->Rotation -= 2 * Multiplier;
      rotated = true;
    }
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