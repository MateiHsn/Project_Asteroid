#include <iostream>

class NonLandscapeDimensions : public std::exception {
public:
  const char * what ( )const noexcept override;
};