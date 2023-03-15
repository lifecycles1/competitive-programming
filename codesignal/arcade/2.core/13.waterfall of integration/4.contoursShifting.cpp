// Mark got a rectangular array matrix for his birthday, and now he's thinking about all the fun things 
// he can do with it. He likes shifting a lot, so he decides to shift all of its i-contours in a clockwise 
// direction if i is even, and counterclockwise if i is odd.

// Here is how Mark defines i-contours:

// the 0-contour of a rectangular array as the union of left and right columns as well as top and 
// bottom rows;
// consider the initial matrix without the 0-contour: its 0-contour is the 1-contour of the initial matrix;
// define 2-contour, 3-contour, etc. in the same manner by removing 0-contours from the obtained arrays.
// Implement a function that does exactly what Mark wants to do to his matrix.

// Example

// For

// matrix = [[ 1,  2,  3,  4],
//            [ 5,  6,  7,  8],
//            [ 9, 10, 11, 12],
//            [13, 14, 15, 16],
//            [17, 18, 19, 20]]
// the output should be

// solution(matrix) = [[ 5,  1,  2,  3],
//                      [ 9,  7, 11,  4],
//                      [13,  6, 15,  8],
//                      [17, 10, 14, 12],
//                      [18, 19, 20, 16]]

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<vector<int>> solution(vector<vector<int>> matrix) {
    const int w = size(matrix[0]), h = size(matrix);
    
    for (int c = 0; c < (w+1)/2 && c < (h+1)/2; ++c) {
      const int cw = w - 2*c;
      const int ch = h - 2*c;
      const int l = cw>1 && ch>1 ? 2*cw +  2*ch - 4 : max(cw, ch);
      const int delta = c % 2 ? 1 : l-1;
              
      int temp = matrix[c][c], px = 0, py = 0;
      for (int a = delta; a; a = (a + delta) % l) {
        int x = a, y = 0;
        if (x > cw-1) y += x-(cw-1), x = cw-1;
        if (y > ch-1) x -= y-(ch-1), y = ch-1;
        if (x < 0) y += x, x = 0;
        matrix[py+c][px+c] = matrix[y+c][x+c];
        py = y;
        px = x;
      }
      matrix[py+c][px+c] = temp;
    }    
    return matrix;
  }
};
