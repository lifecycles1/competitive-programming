// Given an array of integers nums which is sorted in ascending order, and an integer target, write a
// function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function (nums, target) {
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === target) {
      return i;
    }
  }
  return -1;
};

//////////////////////////////////////////////////
// JavaScript solution 2
// Binary Search
//////////////////////////////////////////////////

/**
 * @param {number[]} nums
 * @param {number} target
 * Time O(log(N)) | Space O(1)
 * @return {number}
 */
var search = function (nums, target) {
  let [left, right] = [0, nums.length - 1];
  while (left <= right) {
    const mid = (left + right) >> 1;
    const guess = nums[mid];
    const isTarget = guess === target;
    if (isTarget) return mid;
    const isTargetGreater = guess < target;
    if (isTargetGreater) left = mid + 1;
    const isTargetLess = target < guess;
    if (isTargetLess) right = mid - 1;
  }
  return -1;
};
