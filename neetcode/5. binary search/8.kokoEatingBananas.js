// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
// The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas
// and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead
// and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

/**
 * @param {number[]} piles
 * @param {number} h
 * Time O(N * log(M)) | Space O(1)
 * @return {number}
 */
var minEatingSpeed = function (piles, h) {
  let [left, right] = [1, Math.max(...piles)];
  while (left < right) {
    const mid = (left + right) >> 1;
    const hourSpent = getHourSpent(mid, piles);
    const isTargetGreater = h < hourSpent;
    if (isTargetGreater) left = mid + 1;
    const isTargetLess = hourSpent <= h;
    if (isTargetLess) right = mid;
  }
  return right;
};

const getHourSpent = (mid, piles, hourSpent = 0) => {
  for (const pile of piles) {
    hourSpent += Math.ceil(pile / mid);
  }

  return hourSpent;
};
