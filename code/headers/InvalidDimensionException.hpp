#pragma once

#include <iostream>

class InvalidDimensionsException : public std::exception {
public:
  const char * what ( )const noexcept override;
};
