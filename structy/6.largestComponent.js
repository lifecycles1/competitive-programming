// write a function that takes in the adjacency list of an undirected graph.
// the function should return the size of the largest connected component in that graph.

const largestComponent = (graph) => {
  const visited = new Set();
  let longest = 0;
  for (let node in graph) {
    const size = exploreSize(graph, node, visited);
    if (size > longest) longest = size;
  }
  return longest;
};

const exploreSize = (graph, node, visited) => {
  const stack = [node];
  let size = 0;

  while (stack.length > 0) {
    const current = stack.pop();
    if (visited.has(current)) continue;
    visited.add(current);
    size++;
    for (let neighbor of graph[current]) {
      stack.push(neighbor);
    }
  }
  return size;
};

const graph = {
  0: ["8", "1", "5"],
  1: ["0"],
  5: ["0", "8"],
  8: ["0", "5"],
  2: ["3", "4"],
  3: ["2", "4"],
  4: ["3", "2"],
};

console.log(largestComponent(graph));
