// File for Initializing maze, then updating maze and moving bot to explore the maze and finally doing the sprint run
/*     y ^
         |
         |
         |
       (0,0)-------> x
*/
#include<stdio.h>

struct cord{         //Coordinate of a Cell
  int x,y;
  };

struct bot_parameters{
  
  struct cord bot_cord;
  int bot_moving_dir;  //0,1,2,3 for Bot moving in North,East,West,South
  
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

void maze_setup()                      //Initializing grid variables and values with potential value algo
{
     int i,j;
     for(i=0;i<16;i++)               //Setting potential values for all grids
     for(j=0;j<16;j++)
     {
               if((i<8)&&(j<8))       maze[i][j].value=14-j-i;
               if((i>=8)&&(j<8))      maze[i][j].value=maze[15-i][j].value;  
               if((i<8)&&(j>=8))      maze[i][j].value=maze[i][15-j].value;
               if((i>=8)&&(j>=8))     maze[i][j].value=maze[15-i][15-j].value;     
               maze[i][j].count=0;
               maze[i][j].grid_cord.x=i;
               maze[i][j].grid_cord.y=j;
     }
     
     for(i=0;i<16;i++){                           //Setting boundary walls
        maze[0][i].wallpresent[1]=1;
        maze[15][i].wallpresent[2]=1;
        maze[i][0].wallpresent[3]=1;
        maze[i][15].wallpresent[0]=1;
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
  
