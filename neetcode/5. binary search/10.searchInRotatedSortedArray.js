// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k
// (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0],
// nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3
// and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target
// if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
  let [left, right] = [0, nums.length - 1];

  while (left <= right) {
    const mid = (left + right) >> 1;
    const guess = nums[mid];
    const [leftNum, rightNum] = [nums[left], nums[right]];
    const isTarget = guess === target;
    if (isTarget) return mid;

    const isAscending = leftNum <= guess;
    if (isAscending) {
      const isInRange = leftNum <= target;
      const isLess = target < guess;
      const isTargetGreater = !(isInRange && isLess);
      if (isTargetGreater) left = mid + 1;
      const isTargetLess = isInRange && isLess;
      if (isTargetLess) right = mid - 1;
    }
    const isDescending = guess < leftNum;
    if (isDescending) {
      const isGreater = guess < target;
      const isInRange = target <= rightNum;
      const isTargetGreater = isGreater && isInRange;
      if (isTargetGreater) left = mid + 1;
      const isTargetLess = !(isGreater && isInRange);
      if (isTargetLess) right = mid - 1;
    }
  }
  return -1;
};
