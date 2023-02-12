// Given an integer array nums and an integer k, return the k most frequent elements.

// 1. Create a hash map (JavaScript's Map object) to store the count of each element in the array.
// Iterate over the array, and for each element, increment its count in the hash map.

// 2. Create an array of arrays to store the elements with their counts.
// Iterate over the hash map and for each element add it and its count to the array of arrays

// 3. Sort the array of arrays based on the count of each element in descending order.

// 4. Return the first k elements of the sorted array of arrays.

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function (nums, k) {
  // Step 1
  let counts = new Map();
  for (let i = 0; i < nums.length; i++) {
    if (!counts.has(nums[i])) {
      counts.set(nums[i], 1);
    } else {
      counts.set(nums[i], counts.get(nums[i]) + 1);
    }
  }
  // Step 2
  let countsArr = [];
  for (const [key, value] of counts) {
    countsArr.push([key, value]);
  }
  // Step 3
  countsArr.sort((a, b) => b[1] - a[1]);
  // Step 4
  let result = [];
  for (let i = 0; i < k; i++) {
    result.push(countsArr[i][0]);
  }

  return result;
};
