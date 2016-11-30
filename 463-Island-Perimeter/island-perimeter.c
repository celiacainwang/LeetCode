/*
 * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
 *
 * [[0,1,0,0],
 * [1,1,1,0],
 * [0,1,0,0],
 * [1,1,0,0]]
 *
 * Answer: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 */


#include <stdio.h>

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
	int sum = 0;
	int i, j;

	for (i = 0; i < gridRowSize; i++) {
		for (j = 0; j < gridColSize; j++) {
			if (grid[i][j] == 1) {
				sum += 4;
				if (i > 0 && (grid[i - 1][j] == 1)) {
					sum -= 1;
				}
				if ((j < gridColSize - 1) && (grid[i][j + 1] == 1)) {
					sum -= 1;
				}
				if ((i < gridRowSize - 1) && (grid[i + 1][j] == 1)) {
					sum -= 1;
				}
				if (j > 0 && (grid[i][j - 1]) == 1) {
					sum -= 1;
				}
			}
		}
	}

	return sum;
}

int main(int argc, char * argv[]) {
	int grid[4][4] = {{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}};
	int *p[4];
	int i, j;

	p[0] = grid[0];
	p[1] = grid[1];
	p[2] = grid[2];
	p[3] = grid[3];

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}

	printf("perimeter = %d\n", islandPerimeter(p, 4, 4));

	return 0;
}
