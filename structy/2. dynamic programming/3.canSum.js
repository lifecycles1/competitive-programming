// write a function `canSum(targetSum, numbers)` that takes in a targetSum and an array of numbers
// as arguments. the function should return a boolean indicating whether or not it is possible to
// generate the targetSum using numbers from the array. you may use an element of the array as many
// times as needed. you may assume that all input numbers are nonnegative.

// iterative tabulation solution
function canSum(targetSum, numbers) {
  const table = Array(targetSum + 1).fill(false);
  table[0] = true;
  for (let i = 0; i <= targetSum; i++) {
    if (table[i] === true) {
      for (let num of numbers) {
        table[i + num] = true;
      }
    }
  }
  return table[targetSum];
}

// recursive solution
function canSum(targetSum, numbers) {
  if (targetSum === 0) return true;
  if (targetSum < 0) return false;
  for (let num of numbers) {
    const remainder = targetSum - num;
    if (canSum(remainder, numbers) === true) {
      return true;
    }
  }
  return false;
}

// memoized solution - dynamic programming
function canSum(targetSum, numbers, memo = {}) {
  if (targetSum in memo) return memo[targetSum];
  if (targetSum === 0) return true;
  if (targetSum < 0) return false;
  for (let num of numbers) {
    const remainder = targetSum - num;
    if (canSum(remainder, numbers, memo) === true) {
      memo[targetSum] = true;
      return true;
    }
  }
  memo[targetSum] = false;
  return false;
}
