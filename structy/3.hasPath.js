// write a function that takes in an object representing an adjacency list of a directed acyclic
// graph and two nodes. the function should return a boolean indicating whether or not there exists
// a directed path between the first node and the second node.

const graph = {
  f: ["g", "i"],
  g: ["h"],
  h: [],
  i: ["g", "k"],
  j: ["i"],
  k: [],
};

const src = "f";
const dst = "k";

const hasPath = (graph, src, dst) => {
  const queue = [src];

  while (queue.length > 0) {
    const node = queue.shift();
    if (node === dst) {
      return true;
    }
    for (const neighbor of graph[node]) {
      queue.push(neighbor);
    }
  }
  return false;
};

console.log(hasPath(graph, src, dst));
