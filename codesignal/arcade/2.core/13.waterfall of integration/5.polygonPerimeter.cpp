// You have a rectangular white board with some black cells. The black cells create a connected black 
// figure, i.e. it is possible to get from any black cell to any other one through connected adjacent 
// (sharing a common side) black cells.

// Find the perimeter of the black figure assuming that a single cell has unit length.

// It's guaranteed that there is at least one black cell on the table.

// Example

// For

// matrix = [[false, true,  true ],
//           [true,  true,  false],
//           [true,  false, false]]
// the output should be
// solution(matrix) = 12.

#include <iostream>
#include <vector>

class Solution {
public:
    int solution(std::vector<std::vector<bool>> matrix) {
        int perimeter = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j]) {
                    perimeter += 4;
                    if (i > 0 && matrix[i - 1][j]) perimeter -= 2;
                    if (j > 0 && matrix[i][j - 1]) perimeter -= 2;
                }
            }
        }
        return perimeter;
    }
};