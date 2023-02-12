function solution(level, pos) {
  if (level == 1) {
    return "Engineer";
  }

  var p = solution(level - 1, Math.floor((pos + 1) / 2));

  if (p == "Engineer") {
    return pos % 2 == 1 ? "Engineer" : "Doctor";
  } else if (p == "Doctor") {
    return pos % 2 == 1 ? "Doctor" : "Engineer";
  }
}

// JavaScript solution 2

// basically we don't even need the level, since we can calculate from left to right and we know that the leftmost
// node is always an engineer, so we can just calculate the number of 1s in the binary representation of the position

function solution(level, pos) {
  if (pos === 1) return "Engineer";
  return (pos - 1).toString(2).match(/1/g).length % 2 === 0 ? "Engineer" : "Doctor";
}
