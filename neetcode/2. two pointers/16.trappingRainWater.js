// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it can trap after raining.

/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function (height) {
  let left = 0;
  let right = height.length - 1;
  let leftMax = 0;
  let rightMax = 0;
  let water = 0;

  while (left < right) {
    // update
    if (height[left] > leftMax) leftMax = height[left];
    if (height[right] > rightMax) rightMax = height[right];
    // compute

    if (leftMax < rightMax) {
      water += leftMax - height[left];
      left++;
    } else {
      water += rightMax - height[right];
      right--;
    }
  }
  return water;
};

/////////////////////////////////////////////////
///////////// JavaScript solution 2 /////////////
/////////////////////////////////////////////////

/**
 * @param {number[]} height
 * @return {number}
 */
var trap = function (height) {
  let left = 0;
  let right = height.length - 1;
  let trappedWater = 0;
  let leftMaxHeight = 0;
  let rightMaxHeight = 0;

  while (left <= right) {
    if (height[left] < height[right]) {
      if (height[left] > leftMaxHeight) {
        leftMaxHeight = height[left];
      } else {
        trappedWater += leftMaxHeight - height[left];
      }
      left++;
    } else {
      if (height[right] > rightMaxHeight) {
        rightMaxHeight = height[right];
      } else {
        trappedWater += rightMaxHeight - height[right];
      }
      right--;
    }
  }
  return trappedWater;
};
