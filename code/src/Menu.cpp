#include "../headers/Menu.hpp"
#include "../headers/Player.hpp"
#include "../headers/DefaultParameters.hpp"
#include "../headers/Entity.hpp"
#include "../headers/Enemy.hpp"
#include "../headers/Projectile.hpp"
#include "../headers/CollisionBox.hpp"
#include "./Player.cpp"
#include "../headers/EntityManager.hpp"
#include "./TemplateFunction.cpp"
#include "raylib.h"
#include <ctime>
#include <cstdlib>

/// <summary>
/// Runs most game logic, including calling entity factory methods and managing inputs from the player, as well as calling update methods for entities.
/// </summary>
/// <param name="player"></param>
/// <param name="nps"></param>

void Menu::RunApp (const std::shared_ptr<Player> & player,
                  std::vector<std::shared_ptr<Entity>> & nps) {

  EntityFactory * enemy_creator = new EnemyFactory();

  SetExitKey ( KEY_NULL );

  InitWindow ( DefaultParameters::GetInstance ( )->GetRenderWidth ( ),
               DefaultParameters::GetInstance ( )->GetRenderHeight ( ),
               "Project Asteroid" );

  SetTargetFPS ( 60 );

  double start = GetTime ( );

  while ( State != EXIT) {

    double end = GetTime ( );

    if ( WindowShouldClose ( ) || IsKeyPressed ( KEY_ESCAPE ) ) {
      UpdateState ( PAUSE );
    }

    BeginDrawing ( );
    ClearBackground ( BLACK );
    if ( State == PAUSE ) {
      DrawRectangle ( 0,
                      DefaultParameters::GetInstance ( )->GetRenderHeight ( ) * 2 / 5,
                      DefaultParameters::GetInstance ( )->GetRenderWidth ( ),
                      DefaultParameters::GetInstance ( )->GetRenderHeight ( ) / 6,
                      WHITE );
      constexpr char exit_message [ ] ="      What do you want to do?\n"
                                       "[ Q (quit game) / E (keep playing) ]";
      DrawText ( exit_message,
                 DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 2 -
                 MeasureText ( exit_message, DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 40 ) / 2,
                 DefaultParameters::GetInstance ( )->GetRenderHeight ( ) * 2 / 5,
                 DefaultParameters::GetInstance ( )->GetRenderWidth ( ) / 40,
                 BLACK );


      if ( IsKeyPressed ( KEY_Q ) ) {
        UpdateState ( EXIT );
        continue;
      }
      if ( IsKeyPressed ( KEY_E ) ) {
        UpdateState ( PLAYING );
        continue;
      }
    } else {
      player->Update ( nps );
      player->Draw ( );
      
      for(auto i = nps.begin(); i != nps.end();) {
        std::shared_ptr<Enemy> e = std::dynamic_pointer_cast< Enemy >( *i );
        if ( e != nullptr ) {
          ( *i )->Update ( );
          ( *i )->Draw ( );
        }
        std::shared_ptr<Projectile> p = std::dynamic_pointer_cast< Projectile >( *i );
        if ( p != nullptr ) {
          ( *i )->Update ( );
          ( *i )->Draw ( );
        }

        end = GetTime ( );
        if ( start - end >= 3 ) { nps.push_back ( enemy_creator->Create ( ) ); start = GetTime ( ); };

        if ( e && StillInWindow ( *e ) == false ) { i = nps.erase ( i ); continue; }
        if ( p && StillInWindow ( *p ) == false ) { i = nps.erase ( i ); continue; }

        ++i;

      }
    }
    EndDrawing ( );
  }
}


/// <summary>
/// Updates the state of the Menu for the RunApp method.
/// </summary>
/// <param name="new_state"></param>
void Menu::UpdateState ( char new_state ){
  State = new_state;
  std::cout << "New state: "
    << static_cast< int >( State ) << '\n';
}

