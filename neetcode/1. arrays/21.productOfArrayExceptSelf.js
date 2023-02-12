// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the
// elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function (nums) {
  let result = Array.from({ length: nums.length }, () => 1);
  pre = 1;
  post = 1;
  for (let i = 0; i < nums.length; i++) {
    result[i] = result[i] * pre;
    pre = pre * nums[i];

    result[nums.length - i - 1] = result[nums.length - i - 1] * post;
    post = post * nums[nums.length - i - 1];
  }
  return result;
};
