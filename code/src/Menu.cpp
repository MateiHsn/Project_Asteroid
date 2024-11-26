#include "../headers/Menu.hpp"
#include "../headers/Player.hpp"
#include "../headers/DefaultParameters.hpp"
#include "Player.cpp"
#include "raylib.h"


void Menu::RunApp ( Player *& player ) {

  SetExitKey ( KEY_NULL );

  InitWindow ( DefaultParameters::get_instance ( )->get_width ( ),
               DefaultParameters::get_instance ( )->get_height ( ),
               "Project Asteroid" );

  SetTargetFPS ( 60 );

  bool exit_window = false;
  bool request_exit_window = false;

  while ( !exit_window ) {

    if ( WindowShouldClose ( ) || IsKeyPressed ( KEY_ESCAPE ) ) request_exit_window = true;

    BeginDrawing ( );

    ClearBackground ( BLACK );

    if ( request_exit_window ) {
      DrawRectangle ( 0,
                      DefaultParameters::get_instance ( )->get_height ( ) / 3,
                      DefaultParameters::get_instance ( )->get_width ( ),
                      DefaultParameters::get_instance ( )->get_height ( ) / 3,
                      WHITE );
      constexpr char exit_message [ ] = "Exit the game? [Y/N]";
      DrawText ( exit_message,
                 DefaultParameters::get_instance ( )->get_width ( ) / 2 - MeasureText ( exit_message, DefaultParameters::get_instance ( )->get_width ( ) / 40 )/2,
                 DefaultParameters::get_instance ( )->get_height ( ) / 2,
                 DefaultParameters::get_instance ( )->get_width ( ) / 40,
                 BLACK );

      if(IsKeyPressed(KEY_Y) ) {
        exit_window = true;
        continue;
      }
      if(IsKeyPressed(KEY_N)) {
        request_exit_window = false;
        continue;
      }


    } else {
      player->Update ( );
      player->Draw ( );
    }
    EndDrawing ( );

  }

}
