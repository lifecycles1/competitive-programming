// There are n cars going to the same destination along a one-lane road. The destination is target
// miles away.

// You are given two integer array position and speed, both of length n, where position[i] is the
// position of the ith car and speed[i] is the speed of the ith car (in miles per hour).

// A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper
// at the same speed. The faster car will slow down to match the slower car's speed. The distance between
// these two cars is ignored (i.e., they are assumed to have the same position).

// A car fleet is some non-empty set of cars driving at the same position and same speed. Note that
// a single car is also a car fleet.

// If a car catches up to a car fleet right at the destination point, it will still be considered as
// one car fleet.

// Return the number of car fleets that will arrive at the destination.

/**
 * @param {number} target
 * @param {number[]} position
 * @param {number[]} speed
 * @return {number}
 */
var carFleet = function (target, position, speed) {
  const n = position.length;
  const cars = Array(n);
  for (let i = 0; i < n; i++) {
    cars[i] = [position[i], (target - position[i]) / speed[i]];
  }
  cars.sort((a, b) => b[0] - a[0]);
  let res = 0;
  let curr = 0;
  for (let i = 0; i < n; i++) {
    if (cars[i][1] > curr) {
      res++;
      curr = cars[i][1];
    }
  }
  return res;
};

///////////////////////////////////////
// JavaScript solution 2
///////////////////////////////////////

/**
 * https://leetcode.com/problems/car-fleet
 * Time O(N * log(N)) | Space O(N)
 * @param {number} target
 * @param {number[]} position
 * @param {number[]} speed
 * @return {number}
 */
var carFleet = function (target, position, speed) {
  const coordinates = getCoordinates(target, position, speed); /* Time O(N * log(N)) | Space O(N) */

  return searchAscending(coordinates); /* Time O(N)          | Space O(N) */
};

var getCoordinates = (target, position, speed) =>
  position
    .map((_position, index) => [_position, speed[index]]) /* Time O(N)          | Space O(N) */
    .sort(([aPosition], [bPosition]) => aPosition - bPosition) /* Time O(N * log(N)) | HeapSort Space 0(1) | QuickSort Space O(log(N)) */
    .map(([_position, _speed]) => (target - _position) / _speed); /* Time O(N)          | Space O(N) */

var searchAscending = (coordinates, stack = []) => {
  for (const coordinate of coordinates) {
    /* Time O(N + N) */
    shrink(coordinate, stack); /* Time O(N + N) */
    stack.push(coordinate); /* Space O(N) */
  }

  return stack.length;
};

const shrink = (coordinate, stack) => {
  const isPreviousLess = () => stack[stack.length - 1] <= coordinate;
  while (stack.length && isPreviousLess()) stack.pop(); /* Time O(N + N) */
};

///////////////////////////////////////
// JavaScript solution 3
///////////////////////////////////////

/**
 * https://leetcode.com/problems/car-fleet
 * Time O(N * log(N)) | Space O(N)
 * @param {number} target
 * @param {number[]} position
 * @param {number[]} speed
 * @return {number}
 */
var carFleet = function (target, position, speed) {
  const coordinates = getCoordinates(target, position, speed); /* Time O(N * log(N)) | Space O(N) */

  return searchDescending(coordinates); /* Time O(N) */
};

var getCoordinates = (target, position, speed) =>
  position
    .map((_position, index) => [_position, speed[index]]) /* Time O(N)          | Space O(N) */
    .sort(([aPosition], [bPosition]) => bPosition - aPosition) /* Time O(N * log(N)) | HeapSort Space 0(1) | QuickSort Space O(log(N)) */
    .map(([_position, _speed]) => (target - _position) / _speed); /* Time O(N)          | Space O(N) */

var searchDescending = (coordinates, previous = 0, fleets = 0) => {
  for (const coordinate of coordinates) {
    /* Time O(N) */
    const isPreviousLess = previous < coordinate;
    if (!isPreviousLess) continue;

    previous = coordinate;
    fleets++;
  }

  return fleets;
};
