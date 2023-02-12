// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

/**
 * https://leetcode.com/problems/permutation-in-string/
 * Time O(N + (M - N)) | Space O(1)
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function (s1, s2) {
  const isInvalid = s2.length < s1.length;
  if (isInvalid) return false;

  let [left, right] = [0, 0];
  const [s1FrequencyMap, s2FrequencyMap] = getFrequencyMaps(s1);

  while (right < s2.length) {
    addRightFrequency(s2, right, s2FrequencyMap);

    const window = right - left + 1;
    const isPermutation = window === s1.length && isSame(s1FrequencyMap, s2FrequencyMap);
    if (isPermutation) return true;

    const canSlide = s1.length <= window;
    if (canSlide) {
      subtractLeftFrequency(s2, left, s2FrequencyMap);
      left++;
    }

    right++;
  }

  return false;
};

const getFrequencyMaps = (s1) => {
  const [s1FrequencyMap, s2FrequencyMap] = new Array(2).fill().map(() => new Array(26).fill(0));
  for (const char of s1) s1FrequencyMap[getCode(char)]++;
  return [s1FrequencyMap, s2FrequencyMap];
};

const getCode = (char) => char.charCodeAt(0) - "a".charCodeAt(0);

const addRightFrequency = (s, right, frequencyMap) => {
  const char = s[right];
  const index = getCode(char);
  frequencyMap[index]++;
  return frequencyMap[index];
};

const subtractLeftFrequency = (s, left, frequencyMap) => {
  const char = s[left];
  const index = getCode(char);
  frequencyMap[index]--;
  return frequencyMap[index];
};

const isSame = (a, b) => {
  for (let i = 0; i < 26; i++) {
    const isMatch = a[i] === b[i];
    if (!isMatch) return false;
  }
  return true;
};

// JavaScript solution 2
//////////////////////////////////////////////////////////////////////////////
// Static Sliding Window
// Time: Theta(l1 + l2) O(l1 + l2)  Space: Theta(1) O(1)
// Highest performing solution. Simply builds a map of the character counts
// for `s1` and `s1.length` of `s2` whose characters are within `s1`, updates
// the `s2` character map as it slides from the beginning of `s2` to the end
// of `s2`, and returns upon verifying a match between the `s1` and `s2`
// character maps.
//////////////////////////////////////////////////////////////////////////////

/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function (s1, s2) {
  if (s1.length > s2.length) {
    return false;
  }

  const s1Chars = Object.create(null);
  const s2Chars = Object.create(null);

  for (const ch of s1) {
    if (!(ch in s1Chars)) {
      s1Chars[ch] = 0;
      s2Chars[ch] = 0;
    }
    s1Chars[ch]++;
  }

  for (let i = 0; i < s1.length; i++) {
    const ch = s2[i];
    if (ch in s1Chars) {
      s2Chars[ch]++;
    }
  }

  let matches = 0;
  let matched = 0;

  for (const ch in s1Chars) {
    if (s1Chars[ch] === s2Chars[ch]) {
      matches++;
    }
    matched++;
  }

  const last = s2.length - s1.length;

  for (let i = 0; i < last; i++) {
    if (matches === matched) {
      return true;
    }

    const ch1 = s2[i];
    const ch2 = s2[i + s1.length];

    if (ch1 in s1Chars) {
      if (s1Chars[ch1] === s2Chars[ch1]--) {
        matches--;
      } else if (s1Chars[ch1] === s2Chars[ch1]) {
        matches++;
      }
    }

    if (ch2 in s1Chars) {
      if (s1Chars[ch2] === s2Chars[ch2]++) {
        matches--;
      } else if (s1Chars[ch2] === s2Chars[ch2]) {
        matches++;
      }
    }
  }
  return matches === matched;
};
