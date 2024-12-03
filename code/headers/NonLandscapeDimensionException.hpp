#pragma once

#include <iostream>

class NonLandscapeDimensionsException : public std::exception {
public:
  const char * what ( )const noexcept override;
};