// There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some 
// number of bricks each of the same height (i.e., one unit) but they can be of different widths. 
// The total width of each row is the same.

// Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes 
// through the edge of a brick, then the brick is not considered as crossed. You cannot draw a line 
// just along one of the two vertical edges of the wall, in which case the line will obviously cross 
// no bricks.

// Given the 2D array wall that contains the information about the wall, return the minimum number of 
// crossed bricks after drawing such a vertical line.

// Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
// Output: 2

// Approach: 
// Store the count of the end of the brick for each row in a hash and keep the track
// of max number of brick that ends at same position, return rows - max.
// Time complexity : O(n x m)
// Space complexity: O(n x m)
// n is number of rows, m is max brick in a row.

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  int leastBricks(vector<vector<int>>& wall) {
    map<int, int> end_count;
    int end_of_brick;
    int max_end_count = 0;
    int rows = wall.size();
    int cols;

    for (int i = 0; i < rows; i++) {
      end_of_brick = 0;
      // '-1' because the edge of the wall is not considered
      cols = wall[i].size() - 1;
      for (int j = 0; j < cols; j++) {
        end_of_brick += wall[i][j];

        if (end_count.find(end_of_brick) != end_count.end()) {
          end_count[end_of_brick]++;
        } else {
          end_count[end_of_brick] = 1;
        }
        max_end_count = max(max_end_count, end_count[end_of_brick]);
      }
    }
    return rows - max_end_count;
  }
};