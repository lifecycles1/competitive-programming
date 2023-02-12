/**
 * Time O(N) | Space O(N)
 * https://leetcode.com/problems/valid-parentheses/
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s, stack = []) {
  for (const bracket of s.split("")) {
    const isParenthesis = bracket === "(";
    if (isParenthesis) stack.push(")");
    const isCurlyBrace = bracket === "{";
    if (isCurlyBrace) stack.push("}");
    const isSquareBracket = bracket === "[";
    if (isSquareBracket) stack.push("]");

    const isOpenPair = isParenthesis || isCurlyBrace || isSquareBracket;
    if (isOpenPair) continue;

    const isEmpty = !stack.length;
    const isWrongPair = stack.pop() !== bracket;
    const isInvalid = isEmpty || isWrongPair;
    if (isInvalid) return false;
  }

  return stack.length === 0;
};

// JavaScript solution 2

/**
 * Time O(N) | Space O(N)
 * https://leetcode.com/problems/valid-parentheses/
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s, stack = []) {
  const map = {
    "}": "{",
    "]": "[",
    ")": "(",
  };

  for (const char of s) {
    const isBracket = char in map;
    if (!isBracket) {
      stack.push(char);
      continue;
    }
    const isEqual = stack[stack.length - 1] === map[char];
    if (isEqual) {
      stack.pop();
      continue;
    }
    return false;
  }
  return stack.length === 0;
};
