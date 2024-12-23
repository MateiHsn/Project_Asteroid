#include "../headers/DefaultParameters.hpp"
#include <iostream>
#include <memory>

DefaultParameters * DefaultParameters::DefPars = nullptr;

///@brief Returns the static pointer that contains the default parameters.

DefaultParameters * & DefaultParameters::GetInstance ( ) {
  if ( DefPars == nullptr ) DefPars = new DefaultParameters( );
  return DefPars;
}

void DefaultParameters::FreeInstance ( ) { delete DefPars; }

///@brief Sets new window dimensions.
///
void DefaultParameters::SetRenderDimensions ( int new_width = 1600 , int new_height = 1000 ) {
  DefPars->RenderWidth= new_width;
  DefPars->RenderHeight= new_height;
  std::cout
    << "New window dimensions: "
    << DefPars->RenderWidth << "x"
    << DefPars->RenderHeight << '\n';
}

///@brief Sets a new multiplier
void DefaultParameters::SetMultiplier ( float new_multiplier = 2.0 ) {

  DefPars->Multiplier = new_multiplier;
  std::cout << "New multiplier: "
    << DefPars->Multiplier
    << '\n';
}

///@brief Returns the window's width.
int DefaultParameters::GetRenderWidth() {
  return DefPars->RenderWidth;
}

///@brief Returns the window's height. 
int DefaultParameters::GetRenderHeight() {
  return DefPars->RenderHeight;
}

///@brief Returns the game's multiplier.
float DefaultParameters::GetMultiplier ( ) {
  return DefPars->Multiplier;
}