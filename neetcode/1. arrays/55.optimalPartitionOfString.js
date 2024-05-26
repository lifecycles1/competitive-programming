// 2405. Optimal Partition of String

// Given a string s, partition the string into one or more substrings such that the characters
// in each substring are unique. That is, no letter appears in a single substring more than once.
// Return the minimum number of substrings in such a partition.
// Note that each character should belong to exactly one substring in a partition.

// Example 1:
// Input: s = "abacaba"
// Output: 4
// Explanation:
// Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
// It can be shown that 4 is the minimum number of substrings needed.

// Example 2:
// Input: s = "ssssss"
// Output: 6
// Explanation:
// The only valid partition is ("s","s","s","s","s","s").

/**
 * @param {string} s
 * @return {number}
 */
var partitionString = function (s) {
  let count = 1;
  let map = new Map();
  for (let i = 0; i < s.length; i++) {
    if (map.has(s[i])) {
      count++;
      map = new Map();
    }
    map.set(s[i], 1);
  }
  return count;
};

/**
 * Time complexity = O(n)
 * Space complexity = O(1)
 * @param {string} s
 * @return {number}
 */
const partitionString = (s) => {
  const freq = new Array(26).fill(0);
  let result = 1;
  for (let i = 0; i < s.length; i++) {
    const index = s.charAt(i).charCodeAt(0) - "a".charCodeAt(0);
    freq[index]++;
    if (freq[index] > 1) {
      result++;
      freq.fill(0);
      freq[index]++;
    }
  }
  return result;
};
