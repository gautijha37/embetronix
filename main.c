// File for Initializing maze, then updating maze and moving bot to explore the maze and finally doing the sprint run

#include<stdio.h>

struct cord{         //Coordinate of a Cell
  int x,y;
  };
  
struct grid{            //One unit of Maze

  int value;            //Value of Cell by Floodfill
  int count;            //No. of times cell has already been visited
  bool wallPresent[4];   //0,1,2,3 for Wall present at North, East, West, South
  int bot_moving_dir;  //4 bit no. 0b1000 for moving North
                        //          0b0100 for East
                        //          0b0010 for West
                        //          0b0001 for South
  
  struct cord grid_cord;
  struct cord prev_grid_cord;
  struct cord neighbour_cord[4];     //Neighbour in North,East,West,South
  
  }
  
struct grid maze[16][16];

void neighbours_assign()
{
     int i,j;
     for(i=0;i<16;i++)
     for(j=0;j<16;j++)
     {
                      
                      maze[i][j].Neighbour_cord[0].x=i;maze[i][j].neighbour_cord[0].y=j-1;
                      maze[i][j].Neighbour_cord[3].x=i;maze[i][j].neighbour_cord[3].y=j+1;
                      maze[i][j].Neighbour_cord[2].x=i+1;maze[i][j].neighbour_cord[2].y=j;
                      maze[i][j].Neighbour_cord[1].x=i-1;maze[i][j].neighbour_cord[1].y=j;
     }
}  

void maze_setup()
{
     int i,j;
     for(i=0;i<16;i++)
     for(j=0;j<16;j++)
     {
               if((i<8)&&(j<8))       maze[i][j].value=14-j-i;
               if((i>=8)&&(j<8))      maze[i][j].value=maze[15-i][j].value;  
               if((i<8)&&(j>=8))      maze[i][j].value=maze[i][15-j].value;
               if((i>=8)&&(j>=8))     maze[i][j].value=maze[15-i][15-j].value;               
     
     }
}

void dead_end_check(struct grid a){                               //checks dead end of grids adjacent to grid a
  int i,x;
  if(a.grid_cord.x==0&&a.grid_cord.y==1)                          //If grid to check is not the (0,1) grid whose south is Start Grid
    return;
  else{
    for(i=0;i<4;i++){
      x=a.neighbour_cord[i].wallpresent[0]+a.neighbour_cord[i].wallpresent[1]+a.neighbour_cord[i].wallpresent[2]+a.neighbour_cord[i].wallpresent[3];
      if(x==3)
        a.neighbour_cord[i].wallpresent={1,1,1,1};
    }
  }  
}
  
