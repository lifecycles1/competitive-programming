// Note for me: I see a lot of implementations as
/* function solution(t, s) {
    if (!t) return s === 0;
    s -= t.value;
    return solution(t.left, s) ||
           solution(t.right, s);
}
*/
// That is a WRONG solution because t == null does NOT make sure that its father is a leaf.
// Example input: s = 7
//              4
//           /     \
//          1        3          From the above solution, path 4-3-nil is a valid path!
//        /   \     /  \
//      -2    nil nil   2
//     /   \          /   \
//   nil    3       -4    -3

solution = (t, s) => {
  if (!t) return s === 0;
  return traverse(t, s);
};

traverse = (t, s) => {
  if (!t.left && !t.right && t.value === s) {
    return true;
  }
  s = s - t.value;
  return (!!t.left && traverse(t.left, s)) || (!!t.right && traverse(t.right, s));
};

//Analyzing: 0 ≤ tree size ≤ 5 · 10^4
// => the height h of the given tree is h ~ (log2 of 5.10^4) - 1 = 15 (1)
// => the max number possible paths is total_number_paths = 2^15 ~ 32000 (2)
// From (1) we can also interpolate that the maximal sum of a path is 4000*15 = 60000 which is still in "safe zone integer" (the minimum sum is the same)
// => it's feasible to brute-force to traverse all paths of the tree

// JavaScript solution 2

function solution(t, s) {
  if (!t) {
    return false;
  }
  if (!t.left && !t.right) {
    return s == t.value;
  }
  return solution(t.left, s - t.value) || solution(t.right, s - t.value);
}
