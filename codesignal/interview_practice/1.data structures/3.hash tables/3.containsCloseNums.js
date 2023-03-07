// Given an array of integers nums and an integer k, determine whether there are two distinct
// indices i and j in the array where nums[i] = nums[j] and the absolute difference between i and j
// is less than or equal to k.

class Solution {
  containsCloseNums(nums, k) {
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
      if (map.has(nums[i]) && i - map.get(nums[i]) <= k) {
        return true;
      }
      map.set(nums[i], i);
    }
    return false;
  }
}

class Solution {
  containsCloseNums(nums, k) {
    var indexes = {};
    for (i = 0; i < nums.length; i++) {
      if (i - indexes[nums[i]] <= k) return true;
      indexes[nums[i]] = i;
    }
    return false;
  }
}
