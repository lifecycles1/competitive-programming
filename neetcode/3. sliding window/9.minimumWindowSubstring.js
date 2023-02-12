// Given two strings s and t of lengths m and n respectively, return the minimum window
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is
// no such substring, return the empty string "".

/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function (s, t) {
  const isMissingArgs = !s.length || !t.length;
  if (isMissingArgs) return "";

  const frequencyMap = getFrequencyMap(t);
  const { start, end } = getWindowPointers(s, t, frequencyMap);

  return getSubString(s, start, end);
};

const getFrequencyMap = (str, frequencyMap = new Map()) => {
  for (const char of str) {
    frequencyMap.set(char, (frequencyMap.get(char) || 0) + 1);
  }
  return frequencyMap;
};

const getWindowPointers = (s, t, frequencyMap) => {
  let [left, right, matched, start, end] = [0, 0, 0, 0, s.length + 1];

  while (right < s.length) {
    matched = addRightFrequency(s, right, frequencyMap, matched);
    const canSlide = () => matched === t.length;
    while (canSlide()) {
      const window = right - left + 1;
      const isSmaller = window < end;
      if (isSmaller) {
        [start, end] = [left, window];
      }
      matched = subtractLeftFrequency(s, left, frequencyMap, matched);
      left++;
    }
    right++;
  }
  return { start, end };
};

const addRightFrequency = (s, right, frequencyMap, matched) => {
  const char = s[right];

  if (frequencyMap.has(char)) {
    frequencyMap.set(char, frequencyMap.get(char) - 1);
    const isInWindow = 0 <= frequencyMap.get(char);
    if (isInWindow) matched++;
  }
  return matched;
};

const subtractLeftFrequency = (s, left, frequencyMap, matched) => {
  const char = s[left];
  if (frequencyMap.has(char)) {
    const isOutOfWindow = frequencyMap.get(char) === 0;
    if (isOutOfWindow) matched--;
    frequencyMap.set(char, frequencyMap.get(char) + 1);
  }
  return matched;
};

const getSubString = (s, start, end) => (end <= s.length ? s.slice(start, start + end) : "");

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
///////////////////////// 2nd solution /////////////////////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function (s, t) {
  var map = new Array(128).fill(0);
  for (var i = 0; i < t.length; i++) {
    map[t.charCodeAt(i)]++;
  }
  var counter = t.length,
    begin = 0,
    end = 0,
    d = Number.MAX_VALUE,
    head = 0;
  while (end < s.length) {
    if (map[s.charCodeAt(end++)]-- > 0) counter--; //in t
    while (counter == 0) {
      //valid
      if (end - begin < d) d = end - (head = begin);
      if (map[s.charCodeAt(begin++)]++ == 0) counter++; //make it invalid
    }
  }
  return d == Number.MAX_VALUE ? "" : s.substring(head, head + d);
};
