/*
 * The Problem:
 * Given a number of cities, and an edge list, return the roads that need to be built to
 * finish connecting the cities completely together such that one can go from any city
 * directly to any other city (these are two way roads)
 *
 * Input: cities integer (number of cities) and roads array (edge list of existing roads)
 * Output: new roads to be built, lexicographically
 *
 * Strategy:
 * 1) Let's create an object that stores the cities as keys and then the cities they
 *    are connected to as an array stored at the property
 * 2) Iterate through the keys in the object and for each city (key), determine which cities
 *    it still needs to be connected to.  push these as an edge pair into a 'buildThese' array.
 *    a) update the roadRegister object each time for the roads we just 'built'
 * 3) Return the 'buildThese' array
 */

function solution(cities, roads) {
  let roadRegister = {},
    buildThese = [];
  //add keys to object with empty arrays as properties
  for (let i = 0; i < cities; i++) {
    roadRegister[i] = [];
  }
  //parse through roads array and add appropriate cities to each key's property array
  for (let j = 0; j < roads.length; j++) {
    let from = roads[j][0],
      to = roads[j][1];
    roadRegister[from].push(to);
    roadRegister[to].push(from);
  }
  //parse through city keys to find missing cities, and push roads to be built
  //to buildThese array.  update roadregister each time
  for (const city in roadRegister) {
    const connects = new Set(roadRegister[city]);
    let buildThis = [];
    for (let k = 0; k < cities; k++) {
      if (!connects.has(k) && k !== +city) {
        buildThis = [+city, k];
        buildThese.push(buildThis);
        //update our road register
        roadRegister[city].push(k);
        roadRegister[k].push(+city);
      }
    }
  }
  //return our array of roads to build
  return buildThese;
}

// Python solution

// def solution(cities, roads):
//     roads = set([tuple(road) for road in roads])
//     toBuild = []
//     for i in range(0,cities-1):
//         for j in range(i+1,cities):
//           if (i,j) not in roads and (j,i) not in roads:
//               toBuild.append([i,j])
//     return toBuild
