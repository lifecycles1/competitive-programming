// write a function `allConstruct(target, wordBank)` that accepts a target string and an array
// of strings. the function should return a 2d array containing all of the ways that the `target`
// can be constructed by concatenating elements of the `wordBank` array. each element of the 2d
// array should represent one combination that constructs the `target`. you may reuse elements
// of `wordBank` as many times as needed.

// iterative tabulation solution
function allConstruct(target, wordBank) {
  const table = Array(target.length + 1)
    .fill()
    .map(() => []);
  table[0] = [[]];
  for (let i = 0; i <= target.length; i++) {
    for (let word of wordBank) {
      if (target.slice(i, i + word.length) === word) {
        const newCombinations = table[i].map((subArray) => [...subArray, word]);
        table[i + word.length].push(...newCombinations);
      }
    }
  }
  return table[target.length];
}

// recursive solution
function allConstruct(target, wordBank) {
  if (target === "") return [[]];
  const result = [];
  for (let word of wordBank) {
    if (target.indexOf(word) === 0) {
      const suffix = target.slice(word.length);
      const suffixWays = allConstruct(suffix, wordBank);
      const targetWays = suffixWays.map((way) => [word, ...way]);
      result.push(...targetWays);
    }
  }
  return result;
}

// memoized solution - dynamic programming
function allConstruct(target, wordBank, memo = {}) {
  if (target in memo) return memo[target];
  if (target === "") return [[]];
  const result = [];
  for (let word of wordBank) {
    if (target.indexOf(word) === 0) {
      const suffix = target.slice(word.length);
      const suffixWays = allConstruct(suffix, wordBank, memo);
      const targetWays = suffixWays.map((way) => [word, ...way]);
      result.push(...targetWays);
    }
  }
  memo[target] = result;
  return result;
}
