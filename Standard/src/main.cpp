#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "classes.h"
#include "init.h"
#include "output.h"
#include "moves.h"

using namespace std;


int main(){

  int number_of_turns=0;
//initialize cube
  Cube cube;
  cube.number_of_sides=6;
  int size_of_square=9;
  for(int i=0; i<cube.number_of_sides; i++){
    cube.colours.push_back(i);
  }
  if(cube.colours.size()!=cube.number_of_sides) std::cout<<"Initialize failed!"<<std::endl;

//initialize sides
  for(int i=0; i<cube.number_of_sides; i++){
    Side side;
    side.shape="square";
    side.colours.resize(size_of_square);
    cube.sides.push_back(side);
  }

//generate start distribution
  init(cube);

//output of initial cube colours
  out_colours(cube, number_of_turns);

//MAIN LOOP-MOVING THE CUBE
  turn_front_right(cube, number_of_turns);
  std::cout<<__LINE__<<" "<< number_of_turns<<std::endl;
  out_colours(cube, number_of_turns);

  //Stage 1:first solve for the white cross (WHITE=4)
  //cross(cube);


  return 0;
}
