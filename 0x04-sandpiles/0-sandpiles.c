#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * sandpiles_sum - Write a function that computes the sum of two sandpiles
 * @grid1: sandpile 1
 * @grid2: sandpile 2
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum_sandpile(grid1, grid2);

	while (!valid_sandpaile(grid1))
	{
		print_sandpile(grid1);
		funt_sandpaile(grid1);
	}
}
/**
 * sum_sandpile - sum two sandpiles
 * @grid1: sandpile 1
 * @grid2: sandpile 2
 */
void sum_sandpile(int grid1[3][3], int grid2[3][3])
{
	int j = 0, i = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}

/**
 * valid_sandpaile -funtion sandpaile
 * @grid1: array
 * Return: 0 or 1
 */
int valid_sandpaile(int grid1[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * print_sandpile - Print 3x3 grid
 * @grid: sum all sandpile 1
 */
void print_sandpile(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * funt_sandpaile - change in array
 * @grid1: input array
 */

void funt_sandpaile(int grid1[3][3])
{
	int j = 0, i = 0, n = 0;
	int new_array[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}};


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			n = grid1[i][j];
			if (n >= 4)
			{
				grid1[i][j] = n - 4;
				if ((i + 1) >= 0 && (i + 1) < 3)
					new_array[i + 1][j]++;
				if ((i - 1) >= 0 && (i - 1) < 3)
					new_array[i - 1][j]++;
				if ((j + 1) >= 0 && (j + 1) < 3)
					new_array[i][j + 1]++;
				if ((j - 1) >= 0 && (j - 1) < 3)
					new_array[i][j - 1]++;
			}
		}
	}
	sum_sandpile(grid1, new_array);
}
