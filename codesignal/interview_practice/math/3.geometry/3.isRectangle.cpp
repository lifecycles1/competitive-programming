// You have four points in an array points = [[x1, y1], [x2, y2], [x3, y3], [x4, y4]]. 
// You make a (possibly self-intersecting) 4-sided polygon by joining the adjacent points in the 
// list and joining points[3] back to points[0]. Write a function that returns true if the shape 
// formed by points is a rectangle, and false otherwise.

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
  bool isRectangle(vector<vector<int>> points) {
    int s=0;
    for(int i = 0; i < 4; ++i){
        s = -s + points[i][0] + points[i][1];
    }
    int diag1 = sqrt(pow(points[0][0] - points[2][0],2) + pow(points[0][1] - points[2][1],2));
    int diag2 = sqrt(pow(points[1][0] - points[3][0],2) + pow(points[1][1] - points[3][1],2));
    return s == 0 && diag1==diag2;
  }
};