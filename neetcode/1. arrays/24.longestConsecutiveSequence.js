// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function (nums) {
  let set = new Set(nums);
  let best = 0;
  for (let num of set) {
    if (!set.has(num - 1)) {
      let y = num + 1;
      while (set.has(y)) {
        y++;
      }
      best = Math.max(best, y - num);
    }
  }
  return best;
};
