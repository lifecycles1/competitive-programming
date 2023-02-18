// You are given a stream of points on the X-Y plane. Design an algorithm that:

// Adds new points from the stream into a data structure. Duplicate points are allowed and should be 
// treated as different points.
// Given a query point, counts the number of ways to choose three points from the data structure such 
// that the three points and the query point form an axis-aligned square with positive area.
// An axis-aligned square is a square whose edges are all the same length and are either parallel or 
// perpendicular to the x-axis and y-axis.

// Implement the DetectSquares class:

// DetectSquares() Initializes the object with an empty data structure.
// void add(int[] point) Adds a new point point = [x, y] to the data structure.
// int count(int[] point) Counts the number of ways to form axis-aligned squares with point 
// point = [x, y] as described above.

// Given stream of points, add new points, return count of squares
// Find diagonals, if exists then forms a square, loop thru all points
// Time: O(1) add O(n^2) count -> n = number of points
// Space: O(n)

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// slow solution
class DetectSquares {
public:
  DetectSquares() {}

  void add(vector<int> point) {
    points[point[0]][point[1]]++;
  }

  int count(vector<int> point) {
    int x1 = point[0];
    int y1 = point[1];

    int result = 0;

    for (auto x = points.begin(); x != points.end(); x++) {
      unordered_map<int, int> yPoints = x->second;
      for (auto y = yPoints.begin(); y != yPoints.end(); y++) {
        int x3 = x->first;
        int y3 = y->first;
        // skip points on same x-axis or y-axis
        if (abs(x3-x1) == 0 || abs(x3-x1) != abs(y3-y1)) {
          continue;
        }
        result += points[x3][y3] * points[x1][y3] * points[x3][y1];
      }
    }
    return result;
  }
private:
  // {x -> {y -> count}}
  unordered_map<int, unordered_map<int, int>> points;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

// 95+% runtime, 95% memory
class DetectSquares {
public:
  vector<unordered_map<int, int>> x_axis;
    
  DetectSquares() {
    x_axis = vector<unordered_map<int, int>>(1005);
  }
    
  void add(vector<int> point) {
    int x = point[0];
    int y = point[1];
    x_axis[x][y]++;
  }
    
  int count(vector<int> point) {
    int x = point[0], y = point[1];
    int res = 0;
    for (auto& it : x_axis[x]) {    // For all points lying on x_axis with value x_coordinate = x
      int y_coord = it.first;
      int countOcc = it.second;
        
      if (y == y_coord) {
        continue;
      }
      int sideLength = abs(y_coord - y);
        
      // counting for p3' and p4'
      if (x + sideLength <= 1000) {   // x_coordinate should be within range [0, 1000]
        int newX = x + sideLength;
        res += x_axis[x][y_coord] * x_axis[newX][y_coord] * x_axis[newX][y];
      }
  
      // counting for p3'' and p4''
      if (x - sideLength >= 0) {      // x_coordinate should be within range [0, 1000]
        int newX = x - sideLength;
        res += x_axis[x][y_coord] * x_axis[newX][y_coord] * x_axis[newX][y];
      }
    }
    return res;
  }
};