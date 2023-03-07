//  You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

//  Example

//  For a = [[1, 2, 3],
//           [4, 5, 6],
//           [7, 8, 9]]

//  the output should be

//  solution(a) = [[7, 4, 1],
//                 [8, 5, 2],
//                 [9, 6, 3]]

class Solution {
  rotateImage(a) {
    return a.map((_, rowIndex) => a.map((col) => col[rowIndex]).reverse());
  }
}
