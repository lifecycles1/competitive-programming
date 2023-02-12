# // The Traveling Salesman Problem (TSP) is an NP-hard problem in which the goal is to find the shortest 
# path that visits every node in a graph exactly once and returns to the starting node. There are several 
# methods to solve TSP, such as exact algorithms (e.g. branch and bound, dynamic programming) and heuristic
#  algorithms (e.g. genetic algorithms, simulated annealing, ant colony optimization). However, as the 
# number of nodes in the graph increases, the time complexity of these methods becomes impractical for all
#  but small instances of the problem.

# // Approximation algorithm like Christofides algorithm can provide solution that gives the optimal 
# solution for TSP problem in a polynomial time.


# function ChristofidesTSP(n, graph) {
#   // Minimum Spanning Tree
#   var mst = KruskalMST(n, graph);
#   // Find all the odd degree vertices
#   var oddVertices = [];
#   for (var i = 0; i < n; i++) {
#     if (mst[i].length % 2 != 0) {
#       oddVertices.push(i);
#     }
#   }
#   // Create a subgraph with only odd degree vertices
#   var subgraph = new Array(oddVertices.length);
#   for (var i = 0; i < oddVertices.length; i++) {
#     subgraph[i] = new Array(oddVertices.length);
#   }
#   for (var i = 0; i < oddVertices.length; i++) {
#     for (var j = 0; j < oddVertices.length; j++) {
#       subgraph[i][j] = graph[oddVertices[i]][oddVertices[j]];
#     }
#   }
#   // Find a minimum weight perfect matching
#   var matching = KMPMatch(subgraph);
#   // Combine the minimum spanning tree with the matching
#   var eulerTour = new Array(n);
#   var index = 0;
#   for (var i = 0; i < n; i++) {
#     for (var j = 0; j < mst[i].length; j++) {
#       eulerTour[index++] = mst[i][j];
#     }
#   }
#   for (var i = 0; i < oddVertices.length; i++) {
#     eulerTour[index++] = oddVertices[matching[i]];
#   }
#   // Create a Hamiltonian cycle from the Euler tour
#   var cycle = new Array(n);
#   var visited = new Array(n);
#   for (var i = 0; i < n; i++) {
#     visited[i] = false;
#   }
#   index = 0;
#   for (var i = 0; i < eulerTour.length; i++) {
#     if (!visited[eulerTour[i]]) {
#       visited[eulerTour[i]] = true;
#       cycle[index++] = eulerTour[i];
#     }
#   }
#   cycle[index] = cycle[0];
#   // Calculate the total weight of the Hamiltonian cycle
#   var totalWeight = 0;
#   for (var i = 0; i < n; i++) {
#     totalWeight += graph[cycle[i]][cycle[i + 1]];
#   }
#   return { cycle: cycle, totalWeight: totalWeight };
# }

# function KruskalMST(n, graph) {
#   var mst = new Array(n);
#   for (var i = 0; i < n; i++) {
#     mst[i] = new Array();
#   }
#   var p = new Array(n);
#   for (var i = 0; i < n; i++) {
#     p[i] = i;
#   }
#   function find(i) {
#     if (p[i] != i) {
#       p[i] = find(p[i]);
#     }
#     return p[i];
#   }
#   var edges = new Array();
#   for (var i = 0; i < n; i++) {
#     for (var j = 0; j < n; j++) {
#       if (graph[i][j] > 0) {
#         edges.push([i, j, graph[i][j]]);
#       }
#     }
#   }
#   edges.sort(function (a, b) {
#     return a[2] - b[2];
#   });
#   var index = 0;
#   var count = 0;
#   while (count < n - 1) {
#     var nextEdge = edges[index++];
#     var i = find(nextEdge[0]);
#     var j = find(nextEdge[1]);
#     if (i != j) {
#       p[i] = j;
#       mst[nextEdge[0]].push(nextEdge[1]);
#       mst[nextEdge[1]].push(nextEdge[0]);
#       count++;
#     }
#   }
#   return mst;
# }

# function KMPMatch(graph) {
#   var n = graph.length;
#   var match = new Array(n);
#   for (var i = 0; i < n; i++) {
#     match[i] = -1;
#   }
#   var visited = new Array(n);
#   function dfs(i) {
#     for (var j = 0; j < n; j++) {
#       if (graph[i][j] > 0 && !visited[j]) {
#         visited[j] = true;
#         if (match[j] == -1 || dfs(match[j])) {
#           match[j] = i;
#           return true;
#         }
#       }
#     }
#     return false;
#   }
#   for (var i = 0; i < n; i++) {
#     for (var j = 0; j < n; j++) {
#       visited[j] = false
