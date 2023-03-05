// Given an array strings, determine whether it follows the sequence given in the patterns array.
// In other words, there should be no i and j for which strings[i] = strings[j]
// and patterns[i] ≠ patterns[j] or for which strings[i] ≠ strings[j] and patterns[i] = patterns[j].

// Example

// For strings = ["cat", "dog", "dog"] and patterns = ["a", "b", "b"], the output should be
// solution(strings, patterns) = true;

class Solution {
  areFollowingPatterns(strings, patterns) {
    let a = {};
    let b = {};
    for (let i = 0; i < strings.length; i++) {
      if (a[strings[i]] !== b[patterns[i]]) {
        return false;
      }
      a[strings[i]] = i;
      b[patterns[i]] = i;
    }
    return true;
  }
}

class Solution {
  areFollowingPatterns(strings, patterns) {
    for (var i = 0; i < strings.length; i++) {
      if (strings.indexOf(strings[i]) != patterns.indexOf(patterns[i])) return false;
    }
    return true;
  }
}
