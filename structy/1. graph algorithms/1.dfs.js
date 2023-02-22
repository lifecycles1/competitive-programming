const depthFirstSearch = (graph, targetVal) => {
  const stack = [root];
  while (stack.length > 0) {
    const node = stack.pop();
    if (node.val === targetVal) return node;
    for (const neighbor of graph[node]) {
      stack.push(neighbor);
    }
  }
};
