int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int perimeter = 0;
    int i, j;

    if(gridRowSize < 2) { // single row
        for(j = 0; j < gridColSize; ++j)
            perimeter += grid[0][j];
        return perimeter * 2 + 2;
    }

    if(gridColSize < 2) { // gingle col
        for(i = 0; i < gridRowSize; ++i)
            perimeter += grid[i][0];
        return perimeter * 2 + 2;
    }

    // for main area
    for(i = 1; i < gridRowSize-1; ++i) {
        for(j = 1; j < gridColSize-1; ++j) {
            if(grid[i][j]) perimeter += (4 - grid[i][j-1] - grid[i][j+1] - grid[i-1][j] - grid[i+1][j]);
        }
    }
    // for 4 corners
    if(grid[0][0]) perimeter += (4 - grid[0][1] - grid[1][0]); // topleft
    if(grid[0][gridColSize-1]) perimeter += (4 - grid[0][gridColSize-2] - grid[1][gridColSize-1]); // topright
    if(grid[gridRowSize-1][0]) perimeter += (4 - grid[gridRowSize-1][1] - grid[gridRowSize-2][0]); // bottomleft
    if(grid[gridRowSize-1][gridColSize-1]) perimeter += (4 - grid[gridRowSize-2][gridColSize-1] - grid[gridRowSize-1][gridColSize-2]); // bottomright

    // for 4 edges
    for(j = 1; j < gridColSize-1; ++j) {
        if(grid[0][j]) perimeter += (4 - grid[0][j-1] - grid[0][j+1] - grid[1][j]); // for top edge
        if(grid[gridRowSize-1][j]) perimeter += (4 - grid[gridRowSize-1][j-1] - grid[gridRowSize-1][j+1] - grid[gridRowSize-2][j]); // for bottom edge
    }
    for(i = 1; i < gridRowSize-1; ++i) {
        if(grid[i][0]) perimeter += (4 - grid[i-1][0] - grid[i+1][0] - grid[i][1]); // for left edge
        if(grid[i][gridColSize-1]) perimeter += (4 - grid[i-1][gridColSize-1] - grid[i+1][gridColSize-1] - grid[i][gridColSize-2]); // for right edge
    }
    return perimeter;
}
