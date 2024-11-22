#include "../headers/DefaultParameters.h"

DefaultParameters * DefaultParameters::DefPars = nullptr;

static DefaultParameters & DefaultParameters::get_instance ( )const {
  return DefPars;
}

static void DefaultParameters::set_window_dimensions ( int new_width,
                                                       int new_height ) :
  screen_width ( new_width ),
  screen_height ( new_height ) {
  std::cout
    << "New window dimensions: "
    << screen_width << "x"
    << screen_height << '\n';
}
