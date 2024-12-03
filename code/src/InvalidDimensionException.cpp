#include "../headers/InvalidDimensionException.hpp"

const char* NullNegativeDimensionsException::what() const noexcept {
    return "Negative/null render dimensions... Returning to render dimensions configuration prompt.\n";
}


