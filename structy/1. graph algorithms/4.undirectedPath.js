// write a function that takes in an array of edges for an undirected graph and two nodes.
// The function should return a boolean indicating whether or not there exists a path between
// the two nodes.

const edges = [
  ["i", "j"],
  ["k", "i"],
  ["m", "k"],
  ["k", "l"],
  ["o", "n"],
];

const nodeA = "j";
const nodeB = "m";

const undirectedPath = (edges, nodeA, nodeB) => {
  const graph = buildGraph(edges);
  console.log(graph);
  return hasPath(graph, nodeA, nodeB, new Set());
};

const hasPath = (graph, src, dst, visited) => {
  if (src == dst) return true;
  if (visited.has(src)) return false; // cycle
  visited.add(src); // mark as visited

  for (let neighbor of graph[src]) {
    if (hasPath(graph, neighbor, dst, visited) == true) {
      return true;
    }
  }
  return false;
};

const buildGraph = (edges) => {
  const graph = {};

  for (let edge of edges) {
    const [a, b] = edge;
    if (!(a in graph)) graph[a] = [];
    if (!(b in graph)) graph[b] = [];
    graph[a].push(b);
    graph[b].push(a);
  }
  return graph;
};

console.log(undirectedPath(edges, nodeA, nodeB));
