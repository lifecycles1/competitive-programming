// JavaScript solution 1

const star = [
  [false, true, false, false, false],
  [true, false, false, false, false],
  [false, false, false, true, false],
  [false, false, true, false, false],
  [false, false, false, false, false],
];

function solution(adj) {
  return new Stars(adj).getStarCount();
}

class Stars {
  constructor(adj) {
    this.matrix = adj;
    this.adjMap = this.generateAdjMap();
  }

  generateAdjMap() {
    const { matrix } = this;

    const adjMap = new Map();

    matrix.forEach((field, index) => {
      const fieldMap = new Map();
      field.forEach((value, i) => {
        if (value && i !== index) {
          fieldMap.set(i, true);
        }
      });
      adjMap.set(index, fieldMap);
    });
    return adjMap;
  }

  getStarCount() {
    const { matrix, adjMap } = this;
    console.log(adjMap);
    const parentMap = new Map();

    return matrix.reduce((count, _, index) => {
      const fieldMap = adjMap.get(index);

      if (!parentMap.has(index) && fieldMap.size > 0 && !matrix[index][index]) {
        for (const key of fieldMap.keys()) {
          if (parentMap.has(key) || adjMap.get(key).size !== 1) return count;
        }
        parentMap.set(index, true);
        return count + 1;
      }
      return count;
    }, 0);
  }
}

console.log(solution(star));

// JavaScript solution 2

// function solution(adj) {
//   // Initialize a variable 'n' to store the number of nodes in the graph
//   // Initialize an array 'visited' to keep track of visited nodes
//   // Initialize a variable 'count' to store the number of stars
//   const n = adj.length;
//   let visited = [],
//     count = 0;

//   // Define a function 'leaf' which takes in a 'center' node and a 'node' as input
//   // It checks if the 'node' is a leaf node by checking if every other node is either the 'center' node or not connected to the 'node'
//   function leaf(center, node) {
//     return adj[node].every((v, i) => i == center || !v);
//   }

//   // Use the map function to iterate over the adjacency matrix
//   // For each node in the graph, check if it has been visited already
//   // If it has, skip it
//   // Otherwise, create an array 'connectNodes' to store the connected nodes
//   adj.map((v, i) => {
//     if (visited[i]) return;
//     let connectNodes = [];
//     v.map((o, j) => o && connectNodes.push(j));
//     // Check if all the connected nodes are leaf nodes
//     // If they are, increment the count and mark all the connected nodes as visited
//     if (connectNodes.length > 0 && connectNodes.every((v) => leaf(i, v))) {
//       // Edge case: A node connected to itself is still considered as normal
//       // But for a tree of size 2, a node connecting to itself is not counted
//       if (connectNodes.length === 1 && connectNodes[0] === i) return;
//       count++;
//       connectNodes.map((v) => (visited[v] = true));
//     }
//   });
//   // Return the count
//   return count;
// }
