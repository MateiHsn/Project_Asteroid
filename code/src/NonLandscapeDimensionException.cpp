#include "../headers/NonLandscapeDimensionException.hpp"

/// @brief overloaded version of what() method from std::exception

const char* NonLandscapeDimensionsException::what() const noexcept {
  return "Non-landscape render dimensions... Returning to render dimensions configuration prompt.\n";
}
