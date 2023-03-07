// Given an array a that contains only numbers in the range from 1 to a.length,
// find the first duplicate number for which the second occurrence has the minimal index.
// In other words, if there are more than 1 duplicated numbers, return the number for which
// the second occurrence has a smaller index than the second occurrence of the other number does.
// If there are no such elements, return -1.

class Solution {
  firstDuplicate(a) {
    let minIndex = a.length;
    let minNumber = -1;
    for (let i = 0; i < a.length; i++) {
      for (let j = i + 1; j < a.length; j++) {
        if (a[i] === a[j]) {
          if (j < minIndex) {
            minIndex = j;
            minNumber = a[i];
          }
        }
      }
    }
    return minNumber;
  }
}

class Solution {
  firstDuplicate(a) {
    r = new Set();
    for (let i = 0; i < a.length; i++) {
      if (r.has(a[i])) return a[i];
      r.add(a[i]);
    }
    return -1;
  }
}

class Solution {
  firstDuplicate(a) {
    duplicates = {};
    for (let i = 0; i < a.length; i++) {
      if (duplicates[a[i]]) return a[i];
      else duplicates[a[i]] = 1;
    }
    return -1;
  }
}
