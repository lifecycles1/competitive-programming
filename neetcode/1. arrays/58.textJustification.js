// 68. Text Justification

// Given an array of strings words and a width maxWidth, format the text such that each line has
// exactly maxWidth characters and is fully (left and right) justified.
// You should pack your words in a greedy approach; that is, pack as many words as you can in each
// line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
// Extra spaces between words should be distributed as evenly as possible. If the number of spaces
// on a line does not divide evenly between words, the empty slots on the left will be assigned
// more spaces than the slots on the right.
// For the last line of text, it should be left-justified, and no extra space is inserted between words.

// Note:
// A word is defined as a character sequence consisting of non-space characters only.
// Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// The input array words contains at least one word.

// Example 1:
// Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]

// Example 2:
// Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
// Note that the second line is also left-justified because it contains only one word.

/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
// code modulo based
// Time complexity: O(n)
// Space complexity: O(n+m)
var fullJustify = function (words, maxWidth) {
  let res = [];
  let cur = [];
  let num_of_letters = 0;
  for (let word of words) {
    if (word.length + cur.length + num_of_letters > maxWidth) {
      for (let i = 0; i < maxWidth - num_of_letters; i++) {
        cur[i % (cur.length - 1 || 1)] += " ";
      }
      res.push(cur.join(""));
      cur = [];
      num_of_letters = 0;
    }
    cur.push(word);
    num_of_letters += word.length;
  }
  let lastLine = cur.join(" ");
  while (lastLine.length < maxWidth) {
    lastLine += " ";
  }
  res.push(lastLine);
  return res;
};

// code gap based
// Time complexity: O(n)
// Space complexity: O(n+m)
/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function (words, maxWidth) {
  let res = [],
    curWords = [],
    curLen = 0;
  for (let word of words) {
    if (curLen + word.length + curWords.length > maxWidth) {
      let totalSpaces = maxWidth - curLen;
      let gaps = curWords.length - 1;
      if (gaps === 0) {
        res.push(curWords[0] + " ".repeat(totalSpaces));
      } else {
        let spacePerGap = Math.floor(totalSpaces / gaps);
        let extraSpaces = totalSpaces % gaps;
        let line = "";
        for (let i = 0; i < curWords.length; i++) {
          line += curWords[i];
          if (i < gaps) {
            line += " ".repeat(spacePerGap);
            if (i < extraSpaces) {
              line += " ";
            }
          }
        }
        res.push(line);
      }
      curWords = [];
      curLen = 0;
    }
    curWords.push(word);
    curLen += word.length;
  }
  let lastLine = curWords.join(" ");
  while (lastLine.length < maxWidth) {
    lastLine += " ";
  }
  res.push(lastLine);
  return res;
};
