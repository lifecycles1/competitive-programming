// Suppose an array of length n sorted in ascending order is rotated between 1 and n times.
// For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array
// [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.

/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function (nums) {
  let [left, right] = [0, nums.length - 1];
  while (left < right) {
    const mid = (left + right) >> 1;
    const guess = nums[mid];
    const [leftNum, rightNum] = [nums[left], nums[right]];
    const isTarget = leftNum < rightNum;
    if (isTarget) return leftNum;
    const isTargetGreater = leftNum <= guess;
    if (isTargetGreater) left = mid + 1;
    const isTargetLess = guess < leftNum;
    if (isTargetLess) right = mid;
  }
  return nums[left];
};
