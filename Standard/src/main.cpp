#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include "classes.h"
#include "check_pos.h"
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
//
//STAGE 1: solving the cross:
  int cross_colour=cube.sides[3].colours[4];
  std::cout<<"Solving cross for the colour: "<<cross_colour<<std::endl;

  // try the right and left side for any middle piece
  for(int i=0; i<cube.sides.size();i++){
    for(int j=0;j<cube.sides[i].colours.size();j++){
      if(cube.sides[i].colours[j]==cross_colour && i<=2){
        if(j==3 ){
          if(i==0){
            turn_left_to_top(cube, number_of_turns);
          } else if(i==1){
            turn_left_to_top(cube, number_of_turns);
            turn_left_to_top(cube, number_of_turns);
          } else if(i==2){
            turn_left_to_bottom(cube, number_of_turns);
          }
        break;
        }else if(j==6){
          if(i==0){
            turn_right_to_top(cube, number_of_turns);
          } else if(i==1){
            turn_right_to_top(cube, number_of_turns);
            turn_right_to_top(cube, number_of_turns);
          } else if(i==2){
            turn_right_to_bottom(cube, number_of_turns);
          }
         break;
        }
      } 
    }
  }
  //now that thereis one correct piece shift the middle so that the sides are correctly alligned
  for(int i=0;i<cube.sides[3].colours.size();i++){
    if((i+1)%2==0){
      if(cube.sides[3].colours[i]==cross_colour){
        if(i==1 && cube.sides[2].colours[7]!=cube.sides[2].colours[4]){
          while(cube.sides[2].colours[7]!=cube.sides[2].colours[4]){
            turn_middle_to_right(cube,number_of_turns);
          }
        }else if(i==3 && cube.sides[4].colours[1]!=cube.sides[4].colours[4]){
          while(cube.sides[4].colours[1]!=cube.sides[4].colours[4]){
            turn_middle_to_right(cube,number_of_turns);
          }
        }else if(i==5 && cube.sides[5].colours[1]!=cube.sides[5].colours[4]){
          while(cube.sides[5].colours[1]!=cube.sides[5].colours[4]){
            turn_middle_to_right(cube,number_of_turns);
          }
        }else if(i==7 && cube.sides[0].colours[1]!=cube.sides[0].colours[4]){
          while(cube.sides[0].colours[1]!=cube.sides[0].colours[4]){
            turn_middle_to_right(cube,number_of_turns);
          }
        }
      }
    }
  }

  //check for the missing cross parts and put them into place
  //put the block which has to be replaced to the front
  while(cube.sides[3].colours[7]==cross_colour && cube.sides[0].colours[1]==cube.sides[0].colours[4]){
    turn_cube_right(cube, number_of_turns);
  }
 
  //now look for the corresponding block and move it to the front position
  //therfore exist a lot (21) of possibilitys, first check where the block is located
  int colour_to_move=cube.sides[0].colours[4];
  int side_of_cross_colour;
  int pos_of_cross_colour;
  int side_of_colour_to_move;
  int pos_of_colour_to_move;

  check_for_position(cube, cross_colour, side_of_cross_colour, pos_of_cross_colour, colour_to_move, side_of_colour_to_move, pos_of_colour_to_move);




//STAGE 1: solving the cross:
//  turn_front_right(cube, number_of_turns);
//  turn_right_to_bottom(cube, number_of_turns);
//  turn_lower_to_left(cube, number_of_turns);
////third piece
//  turn_front_right(cube, number_of_turns);
//  turn_front_right(cube, number_of_turns);
//  turn_right_to_bottom(cube, number_of_turns);
//  
//  turn_cube_up(cube, number_of_turns);
//  turn_right_to_bottom(cube, number_of_turns);
//  turn_upper_to_left(cube, number_of_turns);
//  turn_front_left(cube, number_of_turns);
//  turn_upper_to_right(cube, number_of_turns);
//  turn_cube_down(cube, number_of_turns);
//
//  //last piece
//  turn_left_to_bottom(cube, number_of_turns);
//  turn_front_right(cube, number_of_turns);
//  turn_upper_to_right(cube, number_of_turns);
//  turn_front_right(cube, number_of_turns);

  //cross finished and at the front 

//STAGE 2: solving cross corners
  //turn_cube_left(cube, number_of_turns); ??
  



  std::cout<<__LINE__<<" "<< number_of_turns<<std::endl;
  out_colours(cube, number_of_turns);

  //Stage 1:first solve for the white cross (WHITE=4)
  //cross(cube);


  return 0;
}
