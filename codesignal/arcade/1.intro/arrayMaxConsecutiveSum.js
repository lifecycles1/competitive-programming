// Given array of integers, find the maximal possible sum of some of its k consecutive elements.

// Example

// For inputArray = [2, 3, 5, 1, 6] and k = 2, the output should be
// solution(inputArray, k) = 8.

function solution(inputArray, k) {
  let maxSum = 0;
  for (let i = 0; i <= inputArray.length - k; i++) {
    let currSums = 0;
    for (let j = i; j < i + k; j++) {
      currSums += inputArray[j];
    }
    maxSum = Math.max(currSums, maxSum);
  }
  return maxSum;
}
