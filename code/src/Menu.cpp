#include "../headers/Menu.hpp"
#include "../headers/Player.hpp"
#include "../headers/DefaultParameters.hpp"
#include "./Player.cpp"
#include "raylib.h"


void Menu::RunApp (const std::shared_ptr<Entity> & player ) {

  SetExitKey ( KEY_NULL );

  InitWindow ( DefaultParameters::GetInstance ( )->GetRenderWidth ( ),
               DefaultParameters::GetInstance ( )->GetRenderHeight ( ),
               "Project Asteroid" );

  SetTargetFPS ( 60 );

  bool ExitWindow = false;
  bool RequestExitWindow = false;

  while ( !ExitWindow ) {

    if ( WindowShouldClose ( ) || IsKeyPressed ( KEY_ESCAPE ) ) {
      RequestExitWindow = true;
      UpdateState ( PAUSE );
    }
    BeginDrawing ( );


    if ( RequestExitWindow ) {
      DrawRectangle ( 0,
                      DefaultParameters::GetInstance ( )->GetRenderHeight ( ) * 2 / 5,
                      DefaultParameters::GetInstance ( )->GetRenderWidth ( ),
                      DefaultParameters::GetInstance ( )->GetRenderHeight ( ) / 6,
                      WHITE );
      constexpr char exit_message [ ] = "                  What do you want to do?\n"
        "[Q (quit game)/ E (keep playing)/ M (change multiplier) ]";
      DrawText ( exit_message,
                 DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 2 -
                 MeasureText ( exit_message, DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 40 ) / 2,
                 DefaultParameters::GetInstance ( )->GetRenderHeight ( ) * 2 / 5,
                 DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 40,
                 BLACK );


      if ( IsKeyPressed ( KEY_Q ) ) {
        ExitWindow = true;
        UpdateState ( EXIT );
        continue;
      }
      if ( IsKeyPressed ( KEY_E ) ) {
        RequestExitWindow = false;
        UpdateState ( PLAYING );
        continue;
      }
      if ( IsKeyPressed ( KEY_M ) ) {
        UpdateState ( SETTINGS );
        RequestExitWindow = false;
        Rectangle TextBox =
        { static_cast< float > ( DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 3 ),
        static_cast< float > ( DefaultParameters::GetInstance ( )->GetRenderHeight ( ) / 3 ),
        static_cast< float > ( DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 3 ),
        static_cast< float > ( DefaultParameters::GetInstance ( )->GetRenderHeight ( ) / 3 ) };

        constexpr char ChangeMessage [ ] = "New multiplier: ";
      }

    } else {
      ClearBackground ( BLACK );
      player->Update ( );
      player->Draw ( );
      
    }
    EndDrawing ( );

  }

}

void Menu::UpdateState ( char new_state ){
  State = new_state;
  std::cout << "New state: "
    << static_cast< int >( State ) << '\n';
}

