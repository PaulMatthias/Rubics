#include <iostream>

#include "classes.h"

#include "output.h"
#include "moves.h"

void turn_cube_right(Cube& cube, int& num_ot){
  int no_out=42000;
  turn_upper_to_right(cube, no_out);
  turn_middle_to_right(cube, no_out);
  turn_lower_to_right(cube, num_ot);
}

void turn_cube_left(Cube& cube, int& num_ot){
  int no_out=42000;
  turn_upper_to_left(cube, no_out);
  turn_middle_to_left(cube, no_out);
  turn_lower_to_left(cube, num_ot);
}

void turn_cube_up(Cube& cube, int& num_ot){
  int no_out=42000;
  turn_left_to_top(cube, num_ot);
  turn_middle_to_top(cube, num_ot);
  turn_right_to_top(cube, num_ot);
}

void turn_cube_down(Cube& cube, int& num_ot){
  int no_out=42000;
  turn_left_to_bottom(cube, no_out);
  turn_middle_to_bottom(cube, no_out);
  turn_right_to_bottom(cube, num_ot);
}

void turn_front_left(Cube& cube, int& num_ot){
  turn_cube_right(cube, num_ot);
  turn_right_to_bottom(cube, num_ot);
  turn_cube_left(cube, num_ot);
}

void turn_front_right(Cube& cube, int& num_ot){
  turn_cube_right(cube, num_ot);
  turn_right_to_top(cube, num_ot);
  turn_cube_left(cube, num_ot);
}

void turn_side(std::string direction, Side& side){
  Side side_tmp=side;
  if(direction=="right"){
    side.colours[0]=side_tmp.colours[6]; 
    side.colours[1]=side_tmp.colours[3];
    side.colours[2]=side_tmp.colours[0];
    side.colours[3]=side_tmp.colours[7];
    side.colours[5]=side_tmp.colours[1];
    side.colours[6]=side_tmp.colours[8];
    side.colours[7]=side_tmp.colours[5];
    side.colours[8]=side_tmp.colours[2];
  } else if (direction=="left"){
    side.colours[0]=side_tmp.colours[2]; 
    side.colours[1]=side_tmp.colours[5];
    side.colours[2]=side_tmp.colours[8];
    side.colours[3]=side_tmp.colours[1];
    side.colours[5]=side_tmp.colours[7];
    side.colours[6]=side_tmp.colours[0];
    side.colours[7]=side_tmp.colours[3];
    side.colours[8]=side_tmp.colours[6];
  }else{
    std::cout<<"Turning side failed"<<std::endl;
  }
}

void turn_upper_to_left(Cube& cube, int& number_ot){
//save old cube as tmp
  Cube cube_tmp=cube;
  for(int i=0;i<3;i++){
    //front up to left up
    cube.sides[4].colours[i]=cube_tmp.sides[0].colours[i];
    //right up to front up
    cube.sides[0].colours[i]=cube_tmp.sides[5].colours[i];
    //left up to back up
    cube.sides[2].colours[8-i]=cube_tmp.sides[4].colours[i];
    //back up to right up
    cube.sides[5].colours[i]=cube_tmp.sides[2].colours[8-i];
  }
  //turn the upper right side in itself
  turn_side("right", cube.sides[3]);

  number_ot++;
//output of cube colours
  out_colours(cube, number_ot);
}

void turn_lower_to_left(Cube& cube, int& number_ot){
//save old cube as tmp
  Cube cube_tmp=cube;
  for(int i=6;i<9;i++){
    //front low to left low
    cube.sides[4].colours[i]=cube_tmp.sides[0].colours[i];
    //right low to front low
    cube.sides[0].colours[i]=cube_tmp.sides[5].colours[i];
    //left low to back low
    cube.sides[2].colours[8-i]=cube_tmp.sides[4].colours[i];
    //back low to right low
    cube.sides[5].colours[i]=cube_tmp.sides[2].colours[8-i];
  }
  //turn the lower side left in itself
  turn_side("left", cube.sides[1]);

  number_ot++;
//output of cube colours
  out_colours(cube, number_ot);
}

void turn_middle_to_left(Cube& cube, int& number_ot){
//save old cube as tmp
  Cube cube_tmp=cube;
  for(int i=3;i<6;i++){
    //front to left 
    cube.sides[4].colours[i]=cube_tmp.sides[0].colours[i];
    //right to front
    cube.sides[0].colours[i]=cube_tmp.sides[5].colours[i];
    //left to back 
    cube.sides[2].colours[8-i]=cube_tmp.sides[4].colours[i];
    //back to right
    cube.sides[5].colours[i]=cube_tmp.sides[2].colours[8-i];
  }
  //no side turning in itself with this movement

  number_ot++;
//output of cube colours
  out_colours(cube, number_ot);
}

void turn_left_to_top(Cube& cube, int& number_ot){
//save old cube as tmp
  Cube cube_tmp=cube;
  for(int i=0;i<3;i++){
    //front to top 
    cube.sides[3].colours[3*i]=cube_tmp.sides[0].colours[3*i];
    //top to back 
    cube.sides[2].colours[3*i]=cube_tmp.sides[3].colours[3*i];
    //back to bottom 
    cube.sides[1].colours[3*i]=cube_tmp.sides[2].colours[3*i];
    //bottom to front 
    cube.sides[0].colours[3*i]=cube_tmp.sides[1].colours[3*i];
  }
  //left side turning in itself with this movement
  turn_side("left",cube.sides[4]);

  number_ot++;
//output of cube colours
  out_colours(cube, number_ot);
}


void turn_right_to_top(Cube& cube, int& number_ot){
//save old cube as tmp
  Cube cube_tmp=cube;
  for(int i=0;i<3;i++){
    //front to top 
    cube.sides[3].colours[3*i+2]=cube_tmp.sides[0].colours[3*i+2];
    //top to back 
    cube.sides[2].colours[3*i+2]=cube_tmp.sides[3].colours[3*i+2];
    //back to bottom 
    cube.sides[1].colours[3*i+2]=cube_tmp.sides[2].colours[3*i+2];
    //bottom to front 
    cube.sides[0].colours[3*i+2]=cube_tmp.sides[1].colours[3*i+2];
  }
  //left side turning in itself with this movement
  turn_side("right",cube.sides[5]);

  number_ot++;
//output of cube colours
  out_colours(cube, number_ot);
}


void turn_middle_to_top(Cube& cube, int& number_ot){
//save old cube as tmp
  Cube cube_tmp=cube;
  for(int i=0;i<3;i++){
    //front to top 
    cube.sides[3].colours[3*i+1]=cube_tmp.sides[0].colours[3*i+1];
    //top to back 
    cube.sides[2].colours[3*i+1]=cube_tmp.sides[3].colours[3*i+1];
    //back to bottom 
    cube.sides[1].colours[3*i+1]=cube_tmp.sides[2].colours[3*i+1];
    //bottom to front 
    cube.sides[0].colours[3*i+1]=cube_tmp.sides[1].colours[3*i+1];
  }
  //no side turning in itself with this movement

  number_ot++;
//output of cube colours
  out_colours(cube, number_ot);
}

//these were all turn left and up motions, now follow all right and down motions

void turn_upper_to_right(Cube& cube, int& number_ot){
//save old cube as tmp
  Cube cube_tmp=cube;
  for(int i=0;i<3;i++){
    //left to front
    cube.sides[0].colours[i]=cube_tmp.sides[4].colours[i];
    //front to right
    cube.sides[5].colours[i]=cube_tmp.sides[0].colours[i];
    //back to left
    cube.sides[4].colours[i]=cube_tmp.sides[2].colours[8-i];
    //right to back
    cube.sides[2].colours[8-i]=cube_tmp.sides[5].colours[i];
  }
  //turn the upper right side in itself
  turn_side("left", cube.sides[3]);

  number_ot++;
//output of cube colours
  out_colours(cube, number_ot);
}

void turn_lower_to_right(Cube& cube, int& number_ot){
//save old cube as tmp
  Cube cube_tmp=cube;
  for(int i=6;i<9;i++){
    //left to front
    cube.sides[0].colours[i]=cube_tmp.sides[4].colours[i];
    //front to right
    cube.sides[5].colours[i]=cube_tmp.sides[0].colours[i];
    //back to left
    cube.sides[4].colours[i]=cube_tmp.sides[2].colours[8-i];
    //right to back
    cube.sides[2].colours[8-i]=cube_tmp.sides[5].colours[i];
  }
  //turn the lower side left in itself
  turn_side("right", cube.sides[1]);

  number_ot++;
//output of cube colours
  out_colours(cube, number_ot);
}

void turn_middle_to_right(Cube& cube, int& number_ot){
//save old cube as tmp
  Cube cube_tmp=cube;
  for(int i=3;i<6;i++){
    //left to front 
    cube.sides[0].colours[i]=cube_tmp.sides[4].colours[i];
    //right to front
    cube.sides[5].colours[i]=cube_tmp.sides[0].colours[i];
    //back to left 
    cube.sides[4].colours[i]=cube_tmp.sides[2].colours[8-i];
    //right to back
    cube.sides[2].colours[8-i]=cube_tmp.sides[5].colours[i];
  }
  //no side turning in itself with this movement

  number_ot++;
//output of cube colours
  out_colours(cube, number_ot);
}

void turn_left_to_bottom(Cube& cube, int& number_ot){
//save old cube as tmp
  Cube cube_tmp=cube;
  for(int i=0;i<3;i++){
    //front to bottom 
    cube.sides[0].colours[3*i]=cube_tmp.sides[3].colours[3*i];
    //top to back 
    cube.sides[3].colours[3*i]=cube_tmp.sides[2].colours[3*i];
    //back to bottom 
    cube.sides[2].colours[3*i]=cube_tmp.sides[1].colours[3*i];
    //bottom to front 
    cube.sides[1].colours[3*i]=cube_tmp.sides[0].colours[3*i];
  }
  //left side turning in itself with this movement
  turn_side("right",cube.sides[4]);

  number_ot++;
//output of cube colours
  out_colours(cube, number_ot);
}


void turn_right_to_bottom(Cube& cube, int& number_ot){
//save old cube as tmp
  Cube cube_tmp=cube;
  for(int i=0;i<3;i++){
    //front to top 
    cube.sides[0].colours[3*i+2]=cube_tmp.sides[3].colours[3*i+2];
    //top to back 
    cube.sides[3].colours[3*i+2]=cube_tmp.sides[2].colours[3*i+2];
    //back to bottom 
    cube.sides[2].colours[3*i+2]=cube_tmp.sides[1].colours[3*i+2];
    //bottom to front 
    cube.sides[1].colours[3*i+2]=cube_tmp.sides[0].colours[3*i+2];
  }
  //left side turning in itself with this movement
  turn_side("left",cube.sides[5]);

  number_ot++;
//output of cube colours
  out_colours(cube, number_ot);
}


void turn_middle_to_bottom(Cube& cube, int& number_ot){
//save old cube as tmp
  Cube cube_tmp=cube;
  for(int i=0;i<3;i++){
    //front to top 
    cube.sides[0].colours[3*i+1]=cube_tmp.sides[3].colours[3*i+1];
    //top to back 
    cube.sides[3].colours[3*i+1]=cube_tmp.sides[2].colours[3*i+1];
    //back to bottom 
    cube.sides[2].colours[3*i+1]=cube_tmp.sides[1].colours[3*i+1];
    //bottom to front 
    cube.sides[1].colours[3*i+1]=cube_tmp.sides[0].colours[3*i+1];
  }
  //no side turning in itself with this movement

  number_ot++;
//output of cube colours
  out_colours(cube, number_ot);
}




