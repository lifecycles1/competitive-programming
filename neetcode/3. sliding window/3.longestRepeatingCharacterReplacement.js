// You are given a string s and an integer k. You can choose any character of the string and change
// it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing
// the above operations.

/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var characterReplacement = function (s, k) {
  let [left, right, longest, max] = new Array(4).fill(0);
  const frequencyMap = new Array(26).fill(0);

  while (right < s.length) {
    const count = addRightFrequency(s, right, frequencyMap);

    longest = Math.max(longest, count);

    let window = right - left + 1;

    const canSlide = k < window - longest;

    if (canSlide) {
      subtractLeftFrequency(s, left, frequencyMap);
      left++;
    }

    window = right - left + 1;
    max = Math.max(max, window);

    right++;
  }

  return max;
};

const addRightFrequency = (s, right, map) => {
  const char = s[right];
  const index = getCode(char);
  map[index]++;
  return map[index];
};

const subtractLeftFrequency = (s, left, map) => {
  const char = s[left];
  const index = getCode(char);
  map[index]--;
  return map[index];
};

const getCode = (char) => char.charCodeAt(0) - "A".charCodeAt(0);
