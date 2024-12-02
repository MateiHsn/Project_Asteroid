#include "../headers/InvalidDimensionException.hpp"

const char* InvalidDimensionsException::what() const noexcept {
    return "Negative/null render dimensions... Returning to render dimensions configuration prompt.\n";
}


