// Given an array of points on a 2D plane, find the maximum number of points that are visible 
// from point (0, 0) with a viewing angle that is equal to 45 degrees.

// The array of points. For each valid i, points[i] contains exactly 2 elements and represents 
// the ith point, where points[i][0] is the x-coordinate and points[i][1] is the y-coordinate. 
// It is guaranteed that there are no points located at (0, 0) and there are no two points located 
// at the same place

#include <vector>
#include <cmath>
#include <algorithm>
#define M_PI 3.14159265358979323846
using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>> points) {
        int n = points.size();
        int count = 0;
        vector<double> angles;
        for (int i = 0; i < n; i++) {
            if (points[i][0] == 0 && points[i][1] == 0) {
                count++;
                continue;
            }
            angles.push_back(atan2(points[i][1], points[i][0]));
        }
        sort(angles.begin(), angles.end());
        int m = angles.size();
        for (int i = 0; i < m; i++) {
            angles.push_back(angles[i] + 2 * M_PI);
        }
        int res = 0;
        int j = 0;
        for (int i = 0; i < angles.size(); i++) {
            while (angles[i] - angles[j] > M_PI / 4) {
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res + count;
    }
};