#pragma once

#include <iostream>

class InvalidMultiplierException : public std::exception {
public:
  const char * what ( )const noexcept override;
};