// quick summary - basically the problem is to find the minimum number of days to conquer all the cities in a graph
// while advancing 1 day per all cities that have only 1 neighbour.

// This code is solving the problem of conquering cities, where the cities are represented as nodes in a graph
// and roads are the edges that connect them. It uses a combination of data structures such as Set, Array,
// and Map to store and manipulate the data. The techniques used in this code are:

// Graph traversal: The code is traversing through the graph by iterating over the roads and adding the neighboring
// cities to a Map, where the key is the city, and the value is a Set of its neighbors.

// Depth-first search: This code is using a for-loop to iterate over the cities, where each iteration represents a
// day and the code is trying to conquer the cities that have less than 2 neighbors in that day.

// Dynamic programming: The code is storing the result of the day when the city was conquered in an Array.

// This problem will be practical to use when trying to model the process of conquering cities in a game or a
// simulation. It can also be used in real-world scenarios where one needs to conquer a territory and wants to
// know the most efficient way of doing so.

function solution(n, roads) {
  //A set to store conquered cities
  let conquered = new Set(),
    //Initially we set all nodes conquered in day 1(some nodes don't have any neighbor)
    result = new Array(n).fill(1),
    //data store key is the node, values is a Set of it's neighbors
    data = new Map();

  //Set information for data
  roads.forEach((v) => {
    const [vertex1, vertex2] = v;
    data.has(vertex1) ? data.get(vertex1).add(vertex2) : data.set(vertex1, new Set([vertex2]));

    data.has(vertex2) ? data.get(vertex2).add(vertex1) : data.set(vertex2, new Set([vertex1]));
  });
  //A node that we can conquer having the number of it's neighbors <= 1
  for (let day = 1; ; day++) {
    //We want to check whether we can conquer any cities today
    //If not it means that we either conquered every city or
    //the remaining cities, they all have more than 1 neighbor
    //We can not conquer the ones, THEY'RE TOO STRONG
    let victory = false;
    //For every node in data, get rid of conquered cities
    conquered.forEach((node) => data.forEach((o) => o.delete(node)));
    data.forEach((v, i) => {
      //Now, how many neighbor this city has?
      if (v.size < 2) {
        victory = true;
        result[i] = day;
        //Conquered successfully
        conquered.add(i);
        //Get rid of this city on the map
        data.delete(i);
      }
    });
    if (!victory) break;
  }
  //Set remaining cities to -1
  data.forEach((v, i) => (result[i] = -1));
  return result;
}

// Python solution

// def solution(n, roads):
//     prev = []
//     res = [-1]*n
//     neighbors = {i: set() for i in range(n)}
//     for a, b in roads:
//         neighbors[a].add(b)
//         neighbors[b].add(a)
//     day = 1
//     while prev != res:
//         prev = res[:]
//         for i in range(n):
//             if res[i] == -1 and len({c for c in neighbors[i] if res[c] in (-1, day)}) <= 1:
//                 res[i] = day
//         day += 1
//     return res
