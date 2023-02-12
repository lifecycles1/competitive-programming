// Given an integer length, count the number of different good strings that have a length of exactly length.
// A good string is a string for which the following conditions are true:

// A good string contains only lowercase English letters.
// Each character in a good string is unique.
// Exactly one character in a good string is alphabetically greater than the character that precedes it.

function solution(len) {
  //The graph of number:
  //<---  --> <---
  //prefix decreasing
  //then 2 letters increasing
  //suffix decreasing
  //--> Take a decreasing sequence of length len (A)
  //Take a decreasing subsequence of sequence A (B)
  // concat sequence(A \ B) + sequence(B) => Good string(DESC->ASC->DESC)
  //Subsequence of length 1 = ckn(len, 1) - 1
  //(we can not take the last letter and put to the end --> the sequence is still DESC)
  //Subsequence of length 2 = ckn(len, 2) - 1(exludes the case two last letters)
  //So on...
  //=> 2 ** len - 1 * len - c(len, 0)
  // = 2 ** len - len - 1
  const factory = (n) => (n ? n * factory(n - 1) : 1),
    ckn = (n, k) => factory(n) / (factory(n - k) * factory(k));
  return ckn(26, len) * (2 ** len - len - 1);
}
