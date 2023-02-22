// write a function `bestSum(targetSum, numbers)` that takes in a targetSum and an array of numbers
// as arguments. the function should return an array containing the shortest combination of numbers
// that add up to exactly the targetSum. if there is a tie for the shortest combination,
// you may return any one of the shortest.

// iterative tabulation solution
function bestSum(targetSum, numbers) {
  const table = Array(targetSum + 1).fill(null);
  table[0] = [];
  for (let i = 0; i <= targetSum; i++) {
    if (table[i] !== null) {
      for (let num of numbers) {
        const combination = [...table[i], num];
        if (!table[i + num] || combination.length < table[i + num].length) {
          table[i + num] = combination;
        }
      }
    }
  }
  return table[targetSum];
}

// recursive solution
function bestSum(targetSum, numbers) {
  if (targetSum === 0) return [];
  if (targetSum < 0) return null;
  let shortestCombination = null;
  for (let num of numbers) {
    const remainder = targetSum - num;
    const remainderCombination = bestSum(remainder, numbers);
    if (remainderCombination !== null) {
      const combination = [...remainderCombination, num];
      if (shortestCombination === null || combination.length < shortestCombination.length) {
        shortestCombination = combination;
      }
    }
  }
  return shortestCombination;
}

// memoized solution - dynamic programming
function bestSum(targetSum, numbers, memo = {}) {
  if (targetSum in memo) return memo[targetSum];
  if (targetSum === 0) return [];
  if (targetSum < 0) return null;
  let shortestCombination = null;
  for (let num of numbers) {
    const remainder = targetSum - num;
    const remainderCombination = bestSum(remainder, numbers, memo);
    if (remainderCombination !== null) {
      const combination = [...remainderCombination, num];
      if (shortestCombination === null || combination.length < shortestCombination.length) {
        shortestCombination = combination;
      }
    }
  }
  memo[targetSum] = shortestCombination;
  return shortestCombination;
}
