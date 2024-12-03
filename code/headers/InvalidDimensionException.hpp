#pragma once

#include <iostream>

class NullNegativeDimensionsException : public std::exception {
public:
  const char * what ( )const noexcept override;
};
