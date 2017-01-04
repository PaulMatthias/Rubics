#include "classes.h"
#include "init.h"

void init(Cube& cube){
  //side 1
  cube.sides[0].colours[0]=BLUE;
  cube.sides[0].colours[1]=RED;
  cube.sides[0].colours[2]=RED;
  cube.sides[0].colours[3]=YELLOW;
  cube.sides[0].colours[4]=YELLOW;
  cube.sides[0].colours[5]=ORANGE;
  cube.sides[0].colours[6]=ORANGE;
  cube.sides[0].colours[7]=BLUE;
  cube.sides[0].colours[8]=YELLOW;

  //side 2
  cube.sides[1].colours[0]=YELLOW;
  cube.sides[1].colours[1]=ORANGE;
  cube.sides[1].colours[2]=RED;
  cube.sides[1].colours[3]=GREEN;
  cube.sides[1].colours[4]=RED;
  cube.sides[1].colours[5]=WHITE;
  cube.sides[1].colours[6]=WHITE;
  cube.sides[1].colours[7]=RED;
  cube.sides[1].colours[8]=ORANGE;

  //side 3
  cube.sides[2].colours[0]=RED;
  cube.sides[2].colours[1]=BLUE;
  cube.sides[2].colours[2]=GREEN;
  cube.sides[2].colours[3]=GREEN;
  cube.sides[2].colours[4]=WHITE;
  cube.sides[2].colours[5]=BLUE;
  cube.sides[2].colours[6]=BLUE;
  cube.sides[2].colours[7]=WHITE;
  cube.sides[2].colours[8]=ORANGE;

  //side 4
  cube.sides[3].colours[0]=YELLOW;
  cube.sides[3].colours[1]=RED;
  cube.sides[3].colours[2]=YELLOW;
  cube.sides[3].colours[3]=WHITE;
  cube.sides[3].colours[4]=ORANGE;
  cube.sides[3].colours[5]=GREEN;
  cube.sides[3].colours[6]=ORANGE;
  cube.sides[3].colours[7]=YELLOW;
  cube.sides[3].colours[8]=WHITE;

  //side 5
  cube.sides[4].colours[0]=RED;
  cube.sides[4].colours[1]=BLUE;
  cube.sides[4].colours[2]=WHITE;
  cube.sides[4].colours[3]=YELLOW;
  cube.sides[4].colours[4]=BLUE;
  cube.sides[4].colours[5]=ORANGE;
  cube.sides[4].colours[6]=GREEN;
  cube.sides[4].colours[7]=ORANGE;
  cube.sides[4].colours[8]=BLUE;
 
  //side 6
  cube.sides[5].colours[0]=BLUE;
  cube.sides[5].colours[1]=RED;
  cube.sides[5].colours[2]=GREEN;
  cube.sides[5].colours[3]=WHITE;
  cube.sides[5].colours[4]=GREEN;
  cube.sides[5].colours[5]=YELLOW;
  cube.sides[5].colours[6]=GREEN;
  cube.sides[5].colours[7]=GREEN;
  cube.sides[5].colours[8]=WHITE;
}
