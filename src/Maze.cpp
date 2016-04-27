/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
int exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2, int a, int b, int c, int d, int e, int f);
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows<1 || columns<1 || x1<0 || x1>rows - 1 || y1<0 || y1>columns - 1)return 0;
	if (*((maze + x1*columns) + y1) != 1 || *((maze + x2*columns) + y2) != 1)return 0;
	if (exists(maze, rows, columns, x1, y1, x2, y2, 0, 0, 0, 0, x1, y1) == 0)return 0;
	else return 1;
}



int exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2, int a, int b, int c, int d, int e, int f)
{
	int result = 0;
	if (x2 == x1 && y2 == y1)return 1;
	if (rows<1 || columns<1 || x1<0 || x1>rows - 1 || y1<0 || y1>columns - 1)return 0;
	if (*((maze + x1*columns) + y1) != 1)return 0;
	if ((y1 - 1 > -1 && b == 0) && (x1 != e || y1 - 1 != f))result = result + exists(maze, rows, columns, x1, y1 - 1, x2, y2, 1, 0, 0, 0, e, f);
	 if ((y1 + 1 < columns&&a == 0) && (x1 != e || y1 + 1 != f))result = result + exists(maze, rows, columns, x1, y1 + 1, x2, y2, 0, 1, 0, 0, e, f);
	 if ((x1 - 1 > -1 && d == 0) && (x1 - 1 != e || y1 != f))result = result + exists(maze, rows, columns, x1 - 1, y1, x2, y2, 0, 0, 1, 0, e, f);
	 if ((x1 + 1 < rows&&c == 0) && (x1 + 1 != e || y1 != f))result = result + exists(maze, rows, columns, x1 + 1, y1, x2, y2, 0, 0, 0, 1, e, f);
	return result;
}
