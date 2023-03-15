// You are implementing a command-line version of the Paint app. Since the command line doesn't 
// support colors, you are using different characters to represent pixels. Your current goal is to 
// support rectangle x1 y1 x2 y2 operation, which draws a rectangle that has an upper left corner at 
// (x1, y1) and a lower right corner at (x2, y2). Here the x-axis points from left to right, and the 
// y-axis points from top to bottom.

// Given the initial canvas state and the array that represents the coordinates of the two corners, 
// return the canvas state after the operation is applied. For the details about how rectangles are 
// painted, see the example.

// Example

// For

// canvas = [['a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'],
//           ['a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'],
//           ['a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'],
//           ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'],
//           ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b']]
// and rectangle = [1, 1, 4, 3], the output should be

// solution(canvas, rectangle) = [['a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'],
//                                ['a', '*', '-', '-', '*', 'a', 'a', 'a'],
//                                ['a', '|', 'a', 'a', '|', 'a', 'a', 'a'],
//                                ['b', '*', '-', '-', '*', 'b', 'b', 'b'],
//                                ['b', 'b', 'b', 'b', 'b', 'b', 'b', 'b']]

// Note that rectangle sides are depicted as -s and |s, asterisks (*) stand for its corners and all 
// of the other "pixels" remain the same.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<char>> drawRectangle(vector<vector<char>> canvas, vector<int> rectangle) {
    int x1 = rectangle[0];
    int y1 = rectangle[1];
    int x2 = rectangle[2];
    int y2 = rectangle[3];

    for (int i = y1; i <= y2; i++) {
      for (int j = x1; j <= x2; j++) {
        if (i == y1 || i == y2) {
          if (j == x1 || j == x2) {
            canvas[i][j] = '*';
          }
          else {
            canvas[i][j] = '-';
          }
        }
        else {
          if (j == x1 || j == x2) {
            canvas[i][j] = '|';
          }
        }
      }
    }
    return canvas;
  }
};