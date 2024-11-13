#include <headers/Menu.h>

static void Menu::RunApp(Player& player) {
  SetExitKey(KEY_NULL);

  bool ExitWindowRequested = false;
  bool ExitWindow = false;

  InitWindow(1920, 1080, "Project Asteroid");
  SetTargetFPS(60);
  HideCursor();

  while (!ExitWindow) {
    if (!WindowShouldClose() || IsKeyPressed(KEY_ESCAPE))
      ExitWindowRequested = true;

    if (ExitWindowRequested) {
      if (IsKeyPressed(KEY_Y)) ExitWindow = true;
      if (IsKeyPressed(KEY_N)) ExitWindowRequested = false;
    }

    BeginDrawing();
    if (ExitWindowRequested) {
      DrawRectangle(0, GetScreenHeight() / 3, GetScreenWidth(),
                    GetScreenHeight() / 3, WHITE);
      std::string ExitMessage = "Exit the game??? [Y/N]";
      DrawText("Exit the game??? [Y/N]",
               GetScreenWidth() / 2 + MeasureText(ExitMessage, 30) / 2,
               GetScreenHeight() / 2, 30, BLACK);
    } else {
      player.Update();
    }
  }
}

