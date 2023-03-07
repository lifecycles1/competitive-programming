//  You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

//  Example

//  For a = [[1, 2, 3],
          // [4, 5, 6],
          // [7, 8, 9]]

//  the output should be

//  solution(a) = [[7, 4, 1],
                // [8, 5, 2],
                // [9, 6, 3]]

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> rotateImage(vector<vector<int>> a) {
    sort(a.end(), a.begin());
    for (int i = 0; i < a.size(); i++) {
      for (int j = 0; j < i; j++) {
        swap(a[i][j], a[j][i]);
      }
    }
    return a;
  }
};