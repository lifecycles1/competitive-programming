// You are given n rectangular boxes, the ith box has the length lengthi, the width widthi and 
// the height heighti. Your task is to check if it is possible to pack all boxes into one so that 
// inside each box there is no more than one another box (which, in turn, can contain at most one 
// another box, and so on). More formally, your task is to check whether there is such sequence of n 
// different numbers pi (1 ≤ pi ≤ n) that for each 1 ≤ i < n the box number pi can be put into the box 
// number pi+1.
// A box can be put into another box if all sides of the first one are less than the respective ones 
// of the second one. You can rotate each box as you wish, i.e. you can swap its length, width and 
// height if necessary.

// Example

// For length = [1, 3, 2], width = [1, 3, 2], and height = [1, 3, 2], the output should be
// solution(length, width, height) = true;
// For length = [1, 1], width = [1, 1], and height = [1, 1], the output should be
// solution(length, width, height) = false;
// For length = [3, 1, 2], width = [3, 1, 2], and height = [3, 2, 1], the output should be
// solution(length, width, height) = false

#include <vector>
#include <array>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool solution(std::vector<int> length, std::vector<int> width, std::vector<int> height) {
    vector<array<int,3>> boxes;
    for (int i = 0; i < size(length); ++i) {
      int dims[] = {length[i], width[i], height[i]};
      sort(begin(dims), end(dims));
      boxes.push_back({dims[0], dims[1], dims[2]});
    }
    sort(begin(boxes), end(boxes));
    auto err = adjacent_find(begin(boxes), end(boxes), [](const auto& a, const auto& b) {
      return a[0] >= b[0] || a[1] >= b[1] || a[2] >= b[2]; 
    });
    return err == end(boxes);
  }
};