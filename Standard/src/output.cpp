#include <fstream>
#include <iostream>
#include <sstream>
#include "classes.h"
#include "output.h"

void out_colours(Cube cube, int number_ot){
  
  if(number_ot<42000){
    std::ofstream file;
    std::ostringstream file_name;
    for(int side=0;side<cube.sides.size();side++){
      file_name.str("");
      file_name.clear();
      file_name<<"data/colour_side"<<side<<"_step"<<number_ot<<".txt";
      file.open(file_name.str());
      for(int i=0;i<cube.sides[side].colours.size();i++){
        file<<cube.sides[side].colours[i]<<" ";
        if((i+1)%3==0) file<<"\n";
      }
      file.close();
    }
  }

}
