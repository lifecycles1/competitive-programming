// 1822. Sign of the Product of an Array

// There is a function signFunc(x) that returns:
// 1 if x is positive.
// -1 if x is negative.
// 0 if x is equal to 0.
// You are given an integer array nums. Let product be the product of all values in the array nums.

// Return signFunc(product).

// Example 1:
// Input: nums = [-1,-2,-3,-4,3,2,1]
// Output: 1
// Explanation: The product of all values in the array is 144, and signFunc(144) = 1

// Example 2:
// Input: nums = [1,5,0,2,-3]
// Output: 0
// Explanation: The product of all values in the array is 0, and signFunc(0) = 0

var arraySign = function (nums) {
  // var ans = 1
  // for (i of nums) {
  //     if (i === 0) return 0;
  //     if (i < 0) ans = -ans;
  // }
  // return ans
  var product = 1;
  for (i of nums) {
    product = product * i;
  }
  return product < 0 ? -1 : product > 0 ? 1 : 0;
};
