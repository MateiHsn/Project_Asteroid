#include "../headers/InvalidMultiplierException.hpp"

const char* InvalidMultiplierException::what() const noexcept {
  return "Invalid game multiplier value... Returning to game multiplier configuration prompt\n";
}
