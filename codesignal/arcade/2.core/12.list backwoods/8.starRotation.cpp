// Consider a (2k+1) × (2k+1) square subarray of an integer integers matrix. Let's call the union of 
// the square's two longest diagonals, middle column and middle row a star. Given the coordinates of 
// the star's center in the matrix and its width, rotate it 45 · t degrees clockwise preserving 
// position of all matrix elements that do not belong to the star.

# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> starRotation(vector<vector<int>> matrix, int width, vector<int> center, int t) {
    const int pos_x[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    const int pos_y[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    vector<vector<int>> result = matrix;
    
    for(int i = ((width - 1) / 2); i > 0; i--){
      for(int j = 0; j < 8; j++){
        int move = (j + t) % 8;
        result[pos_y[move] * i + center[0]][pos_x[move] * i + center[1]] = matrix[pos_y[j] * i + center[0]][pos_x[j] * i + center[1]];
      }
    }
    return result;
    }
};