// Given a string s consisting of small English letters, find and return the first instance of a
// non-repeating character in it. If there is no such character, return '_'.

// For s = "abacabad", the output should be solution(s) = 'c'.
// There are 2 non-repeating characters in the string: 'c' and 'd'.
// Return c since it appears in the string first.

// For s = "abacabaabacaba", the output should be solution(s) = '_'.
// There are no characters in this string that do not repeat.

class Solution {
  firstNonRepeatingCharacter(s) {
    const charMap = {};
    for (let i = 0; i < s.length; i++) {
      if (charMap[s[i]]) {
        charMap[s[i]]++;
      } else {
        charMap[s[i]] = 1;
      }
    }
    for (let i = 0; i < s.length; i++) {
      if (charMap[s[i]] === 1) {
        return s[i];
      }
    }
    return "_";
  }
}

class Solution {
  firstNonRepeatingCharacter(s) {
    for (var i = 0; i < s.length; i++) {
      if (s.indexOf(s[i]) == s.lastIndexOf(s[i])) {
        return s[i];
      }
    }
    return "_";
  }
}
