/*
 * The Problem:
 * Given 'n' cities and a register of roads connecting the cities
 * (by two way roads) 'roads', return true if you can travel to
 * any city from any other city by traversing at most 2 roads
 *
 * Input: An integer and a matrix
 * Output: boolean
 *
 * Strategy:
 * 1) add cities 'n' to roadRegister object
 * 2) parse through roads matrix and add connections to roadRegister
 * 3) Now, let's work through the object for each city and if a city is not
 *    connected to another city directly, let's see if any of it's "key's" are connected
 *    to the city in question.  If so, move on, if not return false
 * 4) return true at end
 */

function solution(n, roads) {
  let roadRegister = {},
    buildThese = [];
  //add exception for bizarre edge case
  if (n === 1) return true;
  //add keys to object with empty arrays as properties
  for (let i = 0; i < n; i++) {
    roadRegister[i] = [];
  }
  //parse through roads array and add appropriate cities to each key's property array
  for (let j = 0; j < roads.length; j++) {
    let from = roads[j][0],
      to = roads[j][1];
    roadRegister[from].push(to);
    roadRegister[to].push(from);
  }
  //let's parse through roadRegister and see if any road can get to any other road
  //by at most 2 moves
  for (let city in roadRegister) {
    let connects = roadRegister[city];
    //let's check each city up to n
    for (let k = 0; k < n; k++) {
      if (connects.includes(k)) {
        continue;
      } else {
        for (var l = 0; l < connects.length; l++) {
          if (roadRegister[k].includes(connects[l])) break;
        }
        if (l === connects.length) return false;
      }
    }
  }
  return true;
}

// Python solution

// from collections import defaultdict

// def solution(n, roads):
//   vertices = defaultdict(set)
//   for road in roads:
//     x, y = road
//     vertices[x].add(y)
//     vertices[y].add(x)

//   for i in range(n):
//     for j in range(i + 1, n):
//       if i in vertices[j] or j in vertices[i] or len(vertices[i] & vertices[j]) >= 1:
//         continue
//       else:
//         return False

//   return True
