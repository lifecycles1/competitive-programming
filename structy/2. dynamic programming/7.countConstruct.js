// write a function `countConstruct(target, wordBank)` that accepts a target string and an array
// of strings. the function should return the number of ways that the `target` can be constructed
// by concatenating elements of the `wordBank` array. you may reuse elements of `wordBank` as many
// times as needed.

// iterative tabulation solution
function countConstruct(target, wordBank) {
  const table = Array(target.length + 1).fill(0);
  table[0] = 1;
  for (let i = 0; i <= target.length; i++) {
    for (let word of wordBank) {
      if (target.slice(i, i + word.length) === word) {
        table[i + word.length] += table[i];
      }
    }
  }
  return table[target.length];
}

// recursive solution
function countConstruct(target, wordBank) {
  if (target === "") return 1;
  let totalCount = 0;
  for (let word of wordBank) {
    if (target.indexOf(word) === 0) {
      const suffix = target.slice(word.length);
      const numWaysForSuffix = countConstruct(suffix, wordBank);
      totalCount += numWaysForSuffix;
    }
  }
  return totalCount;
}

// memoized solution - dynamic programming
function countConstruct(target, wordBank, memo = {}) {
  if (target in memo) return memo[target];
  if (target === "") return 1;
  let totalCount = 0;
  for (let word of wordBank) {
    if (target.indexOf(word) === 0) {
      const suffix = target.slice(word.length);
      const numWaysForSuffix = countConstruct(suffix, wordBank, memo);
      totalCount += numWaysForSuffix;
    }
  }
  memo[target] = totalCount;
  return totalCount;
}
