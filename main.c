// File for Initializing maze, then updating maze and moving bot to explore the maze and finally doing the sprint run
/*     y ^
         |
         |
         |
       (0,0)-------> x
*/

/*
struct cord{         //Coordinate of a Cell
  int x,y;
  };

struct bot_parameters{
  
  struct cord bot_cord;

  
  };

struct bot_parameters bot;
bot.bot_cord.x=0;
bot.bot_cord.y=0;
bot.bot_moving_dir=0;    //Initially moving North

struct grid{            //One unit of Maze

  int value;            //Value of Cell by Floodfill
  int count;            //No. of times cell has already been visited
  bool wallpresent[4];   //0,1,2,3 indices for Wall present at North, East, West, South. 1 if wall present, 0 otherwise.
  
  struct cord grid_cord;
  struct cord prev_grid_cord;         //this may not be needed... m not sure
  struct cord neighbour_cord[4];     //Neighbour in North,East,West,South
  }

struct grid maze[16][16];
*/
#include<stdio.h>
int bot_moving_dir=0;  //0,1,2,3 for Bot moving in North,East,West,South
int bot_x_cord=0;
int bot_y_cord=0;

int grid_value[16][16];         //Value of Cell by Floodfill
int grid_count[16][16];         //No. of times cell has already been visited
bool wallpresent[16][16][4];    //0,1,2,3 indices for Wall present at North, East, West, South. 1 if wall present, 0 otherwise.

void maze_setup()                      //Initializing grid variables and values with potential value algo
{
     int i,j;
     for(i=0;i<16;i++)               //Setting potential values for all grids
     for(j=0;j<16;j++)
     {
               if((i<8)&&(j<8))       grid_value[i][j]=14-j-i;
               if((i>=8)&&(j<8))      grid_value[i][j]=grid_value[15-i][j];  
               if((i<8)&&(j>=8))      grid_value[i][j]=grid_value[i][15-j];
               if((i>=8)&&(j>=8))     grid_value[i][j]=grid_value[15-i][15-j];     
               grid_count[i][j]=0;
     }
     
     for(i=0;i<16;i++){                           //Setting boundary walls
        wallpresent[0][i][1]=1;
        wallpresent[15][i][2]=1;
        wallpresent[i][0][3]=1;
        wallpresent[i][15][0]=1;
     }
       
}

void dead_end_check(struct grid a){                               //checks dead end of grids adjacent to grid a
  int i,x;
  if(a.grid_cord.x==0&&a.grid_cord.y==1)                          //If grid to check is the (0,1) grid whose south is Start Grid then abort
    return;
  else{
    for(i=0;i<4&&i!=bot.bot_moving_dir;i++){
      x=a.neighbour_cord[i].wallpresent[0]+a.neighbour_cord[i].wallpresent[1]+a.neighbour_cord[i].wallpresent[2]+a.neighbour_cord[i].wallpresent[3];
      if(x==3)                               //if adjacent grid has 3 walls then put fourth wall also
        a.neighbour_cord[i].wallpresent={1,1,1,1};
    }
  }  
}
  
