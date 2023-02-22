// write a functin `canConstruct(target, wordBank)` that accepts a target string and an array
// of strings. the function should return a boolean indicating whether or not the `target` can
// be constructed by concatenating elements of the `wordBank` array. you may reuse elements of
// `wordBank` as many times as needed.

// iterative tabulation solution
function canConstruct(target, wordBank) {
  const table = Array(target.length + 1).fill(false);
  table[0] = true;
  for (let i = 0; i <= target.length; i++) {
    if (table[i] === true) {
      for (let word of wordBank) {
        if (target.slice(i, i + word.length) === word) {
          table[i + word.length] = true;
        }
      }
    }
  }
  return table[target.length];
}

// recursive solution
function canConstruct(target, wordBank) {
  if (target === "") return true;
  for (let word of wordBank) {
    if (target.indexOf(word) === 0) {
      const suffix = target.slice(word.length);
      if (canConstruct(suffix, wordBank) === true) {
        return true;
      }
    }
  }
  return false;
}

// memoized solution - dynamic programming
function canConstruct(target, wordBank, memo = {}) {
  if (target in memo) return memo[target];
  if (target === "") return true;
  for (let word of wordBank) {
    if (target.indexOf(word) === 0) {
      const suffix = target.slice(word.length);
      if (canConstruct(suffix, wordBank, memo) === true) {
        memo[target] = true;
        return true;
      }
    }
  }
  memo[target] = false;
  return false;
}

console.log(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])); // true
console.log(canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"])); // false
