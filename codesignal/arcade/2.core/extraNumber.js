// if 2 out of 3 numbers are equal return the non-duplicate number

// You're given three integers, a, b and c. It is guaranteed that two of these integers are equal to each other.
// What is the value of the third integer?

// Example

// For a = 2, b = 7, and c = 2, the output should be
// solution(a, b, c) = 7.

// The two equal numbers are a and c. The third number (b) equals 7, which is the answer.

// JavaScript solution 1

function solution(a, b, c) {
  return a ^ b ^ c;
}

// JavaScript solution 2

function solution(a, b, c) {
  return a == b ? c : a == c ? b : a;
}

// Generic solution. non-duplicate extraction for arrays
// this solution extracts the unique element from an array (not constrained to 3 items as above)

function solution(array) {
  // let array = [5, 5, 5, 11, 5];
  let count = {};
  for (let i = 0; i < array.length; i++) {
    if (!count[array[i]]) {
      count[array[i]] = 1;
    } else {
      count[array[i]]++;
    }
  }
  for (let key in count) {
    if (count[key] === 1) {
      return +key;
    }
  }
}
