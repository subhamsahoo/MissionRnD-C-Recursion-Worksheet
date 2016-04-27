/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int *wrapper(int **input_array, int *result, int rows, int columns, int a, int b, int c, int d, int i);
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows<1 || columns<1)
		return NULL;
	int *result = (int *)malloc(sizeof(int)*(rows*columns));
	result = wrapper(input_array, result, rows, columns, 0, rows - 1, 0, columns - 1, 0);
	return result;
}
int *wrapper(int **input_array, int *result, int rows, int columns, int a, int b, int c, int d, int i)
{
	int k;
	if (i > rows*columns - 1)
		return result;
	else
	{
		for (k = c; k <= d; k = k + 1)
			result[i++] = input_array[a][k];
		a++;
		for (k = a; k <= b; k = k + 1)
			result[i++] = input_array[k][d];
		d--;
		if (a < b)
		{
			for (k = d; k >= c; k -= 1)
				result[i++] = input_array[b][k];
			b--;
		}
		if (c < d)
		{
			for (k = b; k >= a; k -= 1)
				result[i++] = input_array[k][c];
			c++;
		}
		if (i == rows*columns - 1)
		{
			if (a == c && b == d)
				result[i] = input_array[a][d];
			return result;
		}
	}
	return wrapper(input_array, result, rows, columns, a, b, c, d, i);
}
