// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an 
// integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance #
// (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order 
// that it is in).


// Solution 1
// Quickselect, partition until pivot = k, left side all < k
// Time: O(k log n)
// Space: O(n)

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

    priority_queue<pair<double, vector<int>>> pq;
    for (int i = 0; i < points.size(); i++) {
      double distance = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
      pq.push({distance, points[i]});
      if (pq.size() > k) {
        pq.pop();
      }
    }

    vector<vector<int>> result;
    while(!pq.empty()) {
      result.push_back(pq.top().second);
      pq.pop();
    }

    return result;
  }
};

class Solution1 {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    int low = 0;
    int high = points.size() - 1;
    int pivotIndex = points.size();

    while (pivotIndex != k) {
      pivotIndex = partition(points, low, high);
      if (pivotIndex < k) {
        low = pivotIndex;
      } else {
        high = pivotIndex - 1;
      }
    }
    return vector<vector<int>>(points.begin(), points.begin() + k);
  }
private:
  int partition(vector<vector<int>>& points, int low, int high) {
    vector<int> pivot = points[low + (high - low) / 2];
    int pivotDistance = getDistance(pivot);

    while (low < high) {
      if (getDistance(points[low]) >= pivotDistance) {
        swap(points[low], points[high]);
        high--;
      } else {
        low++;
      }
    }

    if (getDistance(points[low]) < pivotDistance) {
      low++;
    }
    return low;
  }
  int getDistance(vector<int>& point) {
    return pow(point[0], 2) + pow(point[1], 2);
  }
};

// O(n logn) solution using sorting
class Solution2 {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> res(k);
    sort(points.begin(), points.end(), [](vector<int>& p1, vector<int>& p2) {
      int dist_p1 = pow(p1[0],2) + pow(p1[1],2);
      int dist_p2 = pow(p2[0],2) + pow(p2[1],2);
      return dist_p1 < dist_p2;
    });
    copy(points.begin(), points.begin() + k, res.begin());
    return res;
  }
};

// O(k logn) solution
class Solution3 {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> triples;
    for (auto& p : points) {
      triples.push_back({p[0] * p[0] + p[1] * p[1], p[0], p[1]});
    }
    // Min heap of vectors (triples). This constructor takes O(n) time (n = len(v))
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(triples.begin(), triples.end());
    vector<vector<int>> res;
    while (k--) {
      vector<int> el = pq.top();
      pq.pop();
      res.push_back({el[1], el[2]});
    }
    return res;
  }
};