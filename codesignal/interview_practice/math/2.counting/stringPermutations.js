// Given a string s, find all its potential permutations. The output should be sorted in lexicographical order.

function solution(s) {
  // base case: if the string is empty, return an empty array
  if (s.length === 0) return [];
  // base case: if the string has only one character, return an array with that character
  if (s.length === 1) return [s];
  // set to store the permutations
  // (otherwise duplicates occur if the inner for loop below adds items to a normal array data structure)
  const permutations = new Set();
  // iterate through each character in the string
  for (let i = 0; i < s.length; i++) {
    // get the current character
    const char = s[i];
    // get the remaining characters in the string
    const remainingChars = s.slice(0, i) + s.slice(i + 1);
    // recursively get the permutations of the remaining characters
    const subPermutations = solution(remainingChars);
    // prepend the current character to each subpermutation and add it to the permutations set
    for (let j = 0; j < subPermutations.length; j++) {
      permutations.add(char + subPermutations[j]);
    }
  }
  // convert the set to an array and sort it in lexicographical order
  return Array.from(permutations).sort();
}
