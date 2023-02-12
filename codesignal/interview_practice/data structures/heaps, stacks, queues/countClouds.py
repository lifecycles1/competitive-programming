import numpy

def solution(skyMap):
    # check if the skyMap is empty
    if not skyMap:
        return 0
    
    # get the number of rows, columns and initialize the count variable
    row, col, count = len(skyMap), len(skyMap[0]), 0
    # create an array with the same number of rows and columns as the skyMap filled with zeroes
    visited = numpy.zeros((row, col))
    # this function check if the passed coordinates are valid
    valid = lambda i, j: 0 <= i < row and 0 <= j < col
    
    # nested function that performs a DFS starting from a given cell
    def dfs(x, y):
        # stack to perform DFS
        stack = [(x, y)]
        # iterate until the stack is not empty
        while stack:
            # get the last added cell
            x, y = stack.pop()
            # check for all neighbors
            for i, j in (0, 1), (1, 0), (-1, 0), (0, -1):
                # check if the coordinates are valid, cell is not visited and contains cloud '1'
                if valid(x+i, y+j) and not visited[x+i][y+j] and skyMap[x+i][y+j] == "1":
                    # mark the cell as visited
                    visited[x+i][y+j] = 1
                    # push the cell to stack
                    stack.append((x+i, y+j))
    
    # iterate through all cells
    for i in range(row):
        for j in range(col):
            # if cell is not visited and contains cloud '1'
            if not visited[i][j] and skyMap[i][j] == "1":
                # increment the count
                count = count + 1
                # perform dfs on the cell
                dfs(i, j)
    # return the count
    return count
