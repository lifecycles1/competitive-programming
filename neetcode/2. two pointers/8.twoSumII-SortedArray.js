/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
// array is already sorted, if not, need to be sorted first and then use two pointers approach
var twoSum = function (numbers, target) {
  let left = 0;
  let right = numbers.length - 1;

  while (left < right) {
    let currentSum = numbers[left] + numbers[right];
    if (currentSum === target) {
      return [left + 1, right + 1]; // + 1 on indices because the task requires the result to be 1-indexed
    } else if (currentSum < target) {
      left++;
    } else {
      right--;
    }
  }
};
