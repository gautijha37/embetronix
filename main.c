// File for Initializing maze, then updating maze and moving bot to explore the maze and finally doing the sprint run

#include<stdio.h>

struct cord{         //Coordinate of a Cell
  int x,y;
  };
  
struct grid{            //One unit of Maze

  int value;            //Value of Cell by Floodfill
  int count;            //No. of times cell has already been visited
  int wallPresent[4];   //0,1,2,3 for Wall present at North, East, West, South
  int bot_moving_dir;  //4 bit no. 0x1000 for moving North
                        //          0x0100 for East
                        //          0x0010 for West
                        //          0x0001 for South
  
  struct cord grid_cord;
  struct cord prev_grid_cord;
  struct cord Neighbour_cord[4];     //Neighbour in North,East,West,South
  
  }
  
