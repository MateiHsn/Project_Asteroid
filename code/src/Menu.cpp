#include "../headers/Menu.hpp"
#include "../headers/Player.hpp"
#include "../headers/DefaultParameters.hpp"
#include "../headers/Entity.hpp"
#include "../headers/Enemy.hpp"
#include "../headers/Projectile.hpp"
#include "../headers/CollisionBox.hpp"
#include "./Player.cpp"
#include "raylib.h"

#include <ctime>
#include <cstdlib>

void Menu::RunApp (const std::shared_ptr<Player> & player,
                  std::vector<std::shared_ptr<Entity>> & nps) {


  srand ( time ( nullptr ) );

  short ProjectileCounter = 0;
  short EnemyCounter = 0;

  SetExitKey ( KEY_NULL );

  InitWindow ( DefaultParameters::GetInstance ( )->GetRenderWidth ( ),
               DefaultParameters::GetInstance ( )->GetRenderHeight ( ),
               "Project Asteroid" );

  SetTargetFPS ( 60 );

  bool ExitWindow = false;
  bool RequestExitWindow = false;

  double start = GetTime ( );

  while ( !ExitWindow ) {

    double end = GetTime ( );

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
      constexpr char exit_message [ ] = "                 What do you want to do?\n"
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
      player->Update ( nps );
      player->Draw ( );
      
      for(auto i = nps.begin(); i != nps.end(); ++i ) {
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
        //
        // if((*i)->GetPos().x > DefaultParameters::GetInstance()->GetRenderWidth() ||
        //     ( *i )->GetPos ( ).x < 0 ||
        //     (*i)->GetPos().y < 0 ||
        //     ( *i )->GetPos ( ).y > DefaultParameters::GetInstance ( )->GetRenderHeight( ) ) {
        //   nps.erase ( i );
        // }
        end = GetTime ( );
        if ( start - end >= 3 ) nps.push_back ( std::make_shared<Enemy> ( Enemy ( player->GetPos ( ),
                                                                                  player->GetRotation ( ),
                                                                                  3,
                                                                                  player->GetRadius ( ),
                                                                                  5,
                                                                                  10 ) ) );
      }
    }
    EndDrawing ( );

  }

}

void Menu::UpdateState ( char new_state ){
  State = new_state;
  std::cout << "New state: "
    << static_cast< int >( State ) << '\n';
}

