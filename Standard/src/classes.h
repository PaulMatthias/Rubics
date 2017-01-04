#pragma once

#include <vector>
#include <string>

enum Colours{
  RED=0,
  BLUE=1,
  YELLOW=2,
  ORANGE=3,
  WHITE=4,
  GREEN=5,
  MAX_COLOURS
};

struct Side{
  std::string shape;
  std::vector<int> colours;
};

struct Cube{
  std::vector<Side> sides;
  int number_of_sides;
  std::vector<int> colours;
};




