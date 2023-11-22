#!/usr/bin/python3
"""
Module that contains the island_perimeter function
"""


def island_perimeter(grid):
    """
    Function that returns the perimeter of an island described in grid
    """
    perimeter = 0

    nrows = len(grid)

    if grid:
        ncolumns = len(grid[0])

    for row in range(nrows):
        for col in range(ncolumns):
            if grid[row][col] == 1:
                perimeter += (row == 0 or grid[row - 1][col] == 0)
                perimeter += (row == nrows - 1 or grid[row + 1][col] == 0)
                perimeter += (col == 0 or grid[row][col - 1] == 0)
                perimeter += (col == ncolumns - 1 or grid[row][col + 1] == 0)

    return perimeter
