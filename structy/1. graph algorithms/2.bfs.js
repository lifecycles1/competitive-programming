// returns an object that contains the length of the shortest path from the
// root node to each node in the graph
const breadthFirstSearch1 = (graph, root) => {
  let nodesLen = {};

  for (let i = 0; i < graph.length; i++) {
    nodesLen[i] = Infinity;
  }
  nodesLen[root] = 0;

  let queue = [root];
  let current;

  while (queue.length != 0) {
    current = queue.shift();

    let curConnected = graph[current];
    let neighborIdx = [];
    let idx = curConnected.indexOf(1);
    while (idx != -1) {
      neighborIdx.push(idx);
      idx = curConnected.indexOf(1, idx + 1);
    }

    for (let j = 0; j < neighborIdx.length; j++) {
      if (nodesLen[neighborIdx[j]] == Infinity) {
        nodesLen[neighborIdx[j]] = nodesLen[current] + 1;
        queue.push(neighborIdx[j]);
      }
    }
  }
  return nodesLen;
};

// traverses the graph, visits and logs each node.
const breadthFirstSearch2 = (graph, root) => {
  const queue = [root];

  while (queue.length > 0) {
    const node = queue.shift();
    console.log(node);
    for (const neighbor of graph[node]) {
      queue.push(neighbor);
    }
  }
};
