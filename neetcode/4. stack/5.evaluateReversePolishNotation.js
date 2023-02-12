// You are given an array of strings tokens that represents an arithmetic expression in a Reverse
// Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function (tokens) {
  const stack = [];

  for (const token of tokens) {
    if (!isNaN(token)) {
      stack.push(parseInt(token));
    } else {
      const secondOperand = stack.pop();
      const firstOperand = stack.pop();
      let result;
      switch (token) {
        case "+":
          result = firstOperand + secondOperand;
          break;
        case "-":
          result = firstOperand - secondOperand;
          break;
        case "*":
          result = firstOperand * secondOperand;
          break;
        case "/":
          result = Math.trunc(firstOperand / secondOperand);
          break;
      }
      stack.push(result);
    }
  }
  return stack.pop();
};

///////////////////////////////////////
// JavaScript solution 2
///////////////////////////////////////

/**
 * https://leetcode.com/problems/evaluate-reverse-polish-notation
 * Time O(N^2) | Space(1)
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function (tokens, index = 0) {
  while (1 < tokens.length) {
    /* Time O(N) */
    const isOperation = () => tokens[index] in OPERATORS;
    while (!isOperation()) index++; /* Time O(N) */

    const value = performOperation(tokens, index);

    tokens[index] = value;
    tokens.splice(index - 2, 2); /* Time O(N) */
    index--;
  }

  return tokens[0];
};

var OPERATORS = {
  "+": (a, b) => a + b,
  "-": (a, b) => a - b,
  "*": (a, b) => a * b,
  "/": (a, b) => Math.trunc(a / b),
};

var performOperation = (tokens, index) => {
  const [rightNum, leftNum] = [Number(tokens[index - 1]), Number(tokens[index - 2])];
  const operation = OPERATORS[tokens[index]];

  return operation(leftNum, rightNum);
};

///////////////////////////////////////
// JavaScript solution 3
///////////////////////////////////////

/**
 * https://leetcode.com/problems/evaluate-reverse-polish-notation
 * Time O(N) | Space(N)
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function (tokens, stack = []) {
  for (const char of tokens) {
    /* Time O(N) */
    const isOperation = char in OPERATORS;
    if (isOperation) {
      const value = performOperation(char, stack);

      stack.push(value); /* Space O(N) */

      continue;
    }

    stack.push(Number(char)); /* Space O(N) */
  }

  return stack.pop();
};

var OPERATORS = {
  "+": (a, b) => a + b,
  "-": (a, b) => a - b,
  "*": (a, b) => a * b,
  "/": (a, b) => Math.trunc(a / b),
};

var performOperation = (char, stack) => {
  const [rightNum, leftNum] = [stack.pop(), stack.pop()];
  const operation = OPERATORS[char];

  return operation(leftNum, rightNum);
};
