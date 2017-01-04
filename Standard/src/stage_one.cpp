#include "classes.h"


//Aim : cross of specific colour cl at the front side, while the touching sides have to be according to the centers
void cross(Cube& cube, int cl, int& num_ot){
  //first get the wanted colour center piece
  for(int i=0;i<4;i++){
    if(cube.sides[0].colours[4]!=cl) break;
    turn_middle_to_right(cube, num_ot);
  }
  for(int i=0;i<4;i++){
    if(cube.sides[0].colours[4]!=cl) break;
    turn_middle_to_top(cube, num_ot);
  }

  //second get the side pieces

}
