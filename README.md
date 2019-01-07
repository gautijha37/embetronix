# embetronix
We need one file for testing our algo, i.e. it takes a maze as input (in the form of a 16x16 array of data structure to be defined in the main.c file) and gives a path as output.And one main.c file.
2 people can first design the utility file which checks the software.
rest two can design the exploration and path finding algo as of now.
Please suggest changes and keep updating files.

Purpose:
1. Initialize maze    
2. Move bot then detect walls then following steps would be done at each grid:
    a) Detect nearby walls, update wallposition value in 2 grids (1 wall would have 2 grids on each side) also update value by floodfill,          increase count. 
    b) Check adjacent 3 grids for dead end, if found make virtual wall on all 4 sides for that cell.
    c) Continue moving
3. On encountering more than 1 options for movement to next grid, preference to be given:
    a) count value, if same then
    b) potential value, if same then
    c) straight path (if available) is chosen, otherwise move left, otherwise right
4. After reaching centre, Come back towards start following same algo as above (Same movement preferences) to arrive at start following a 
   different path.
5. Calculate time for these two paths, sprint run on better path.
   (Time=(No. of turns)xTurning time + No. of gridsx(Traversal time for each grid))
