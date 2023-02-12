import random

def fill_random_sudoku():
    grid = [[0 for _ in range(9)] for _ in range(9)]
    fill_grid(grid, 0, 0)
    return grid

def fill_grid(grid, row, col):
    if col == 9:
        col = 0
        row += 1
    if row == 9:
        return True

    for num in random.sample(range(1, 10), 9):
        if is_valid(grid, row, col, num):
            grid[row][col] = num
            if fill_grid(grid, row, col + 1):
                return True
            grid[row][col] = 0

    return False

def is_valid(grid, row, col, num):
    for i in range(9):
        if grid[i][col] == num or grid[row][i] == num:
            return False

    startRow = row - row % 3
    startCol = col - col % 3
    for i in range(3):
        for j in range(3):
            if grid[i + startRow][j + startCol] == num:
                return False

    return True



def print_grid(grid):
    for row in grid:
        print(row)


grid = fill_random_sudoku()
print_grid(grid)
