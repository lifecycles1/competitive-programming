// Given an array of points on a 2D plane, find the maximum number of points that are visible
// from point (0, 0) with a viewing angle that is equal to 45 degrees.

// The array of points. For each valid i, points[i] contains exactly 2 elements and represents
// the ith point, where points[i][0] is the x-coordinate and points[i][1] is the y-coordinate.
// It is guaranteed that there are no points located at (0, 0) and there are no two points located
// at the same place

class Solution {
  visiblePoints(points) {
    let count = 0;
    let angles = [];
    for (let point of points) {
      if (point[0] === 0 && point[1] === 0) {
        count++;
      } else {
        angles.push(Math.atan2(point[1], point[0]));
      }
    }
    angles.sort((a, b) => a - b);
    let len = angles.length;
    for (let i = 0; i < len; i++) {
      angles.push(angles[i] + Math.PI * 2);
    }
    let max = 0;
    let start = 0;
    for (let i = 0; i < angles.length; i++) {
      while (angles[i] - angles[start] > Math.PI / 4) {
        start++;
      }
      max = Math.max(max, i - start + 1);
    }
    return max + count;
  }
}
