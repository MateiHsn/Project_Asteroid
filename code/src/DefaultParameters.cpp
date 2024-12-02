#include "../headers/DefaultParameters.hpp"
#include <iostream>
DefaultParameters * DefaultParameters::DefParams = new DefaultParameters();

///@brief Returns the static pointer that contains the default parameters.
DefaultParameters*& DefaultParameters::GetInstance() {
  if ( !DefParams ) DefParams = new DefaultParameters;
  return DefParams;
}

///@brief Sets new window dimensions.
void DefaultParameters::SetRenderDimensions ( int new_width = 1600 , int new_height = 1000 ) {
  DefParams->ScreenWidth= new_width;
  DefParams->ScreenHeight= new_height;
  std::cout
    << "New window dimensions: "
    << DefParams->ScreenWidth << "x"
    << DefParams->ScreenHeight << '\n';
}


///@brief Sets a new multiplier
void DefaultParameters::SetMultiplier ( float new_multiplier = 2.0 ) {

  DefParams->Multiplier = new_multiplier;
  std::cout << "New multiplier: "
    << DefParams->Multiplier
    << '\n';
}

///@brief Returns the window's width.
int DefaultParameters::GetRenderWidth() {
  return DefParams->ScreenWidth;
}


///@brief Returns the window's height. 
int DefaultParameters::GetRenderHeight() {
  return DefParams->ScreenHeight;
}

///@brief Returns the game's multiplier.
float DefaultParameters::GetMultiplier ( ) {
  return DefParams->Multiplier;
}