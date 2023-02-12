/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function (nums) {
  let hashset = new Map();

  for (const n of nums) {
    if (hashset.has(n)) {
      return true;
    }
    hashset.set(n);
  }
  return false;
};

// Python solution

// class Solution:
//     def containsDuplicate(self, nums: List[int]) -> bool:
//         hashset = set()

//         for n in nums:
//             if n in hashset:
//                 return True
//             hashset.add(n)
//         return False
