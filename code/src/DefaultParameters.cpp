#include "../headers/DefaultParameters.hpp"

DefaultParameters * DefaultParameters::def_parameters = new DefaultParameters();


DefaultParameters*& DefaultParameters::get_instance() {
  if ( !def_parameters ) def_parameters = new DefaultParameters;
  return def_parameters;
}



void DefaultParameters::set_window_dimensions ( int new_width = 1600 , int new_height = 1000 ) {
  def_parameters->screen_width = new_width;
  def_parameters->screen_height = new_height;
  std::cout
    << "New window dimensions: "
    << def_parameters->screen_width << "x"
    << def_parameters->screen_height << '\n';
}

void DefaultParameters::set_mul ( float new_multiplier = 2.0 ) {

  def_parameters->multiplier = new_multiplier;
  std::cout << "New multiplier: "
    << def_parameters->multiplier;
}

int DefaultParameters::get_width ( ) {
  return def_parameters->screen_width;
}

int DefaultParameters::get_height ( ) {
  return def_parameters->screen_height;
}

float DefaultParameters::get_mul ( ) {
  return def_parameters->multiplier;
}