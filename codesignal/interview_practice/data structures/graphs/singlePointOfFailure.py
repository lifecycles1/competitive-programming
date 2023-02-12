# Sue is a network administrator who consults for companies that have massive Local Area Networks (LANs). 
# The computers are connected together with network cables, and Sue has been brought in to evaluate the 
# company’s network. The networks are huge, and she wants to ensure that no single network cable failure 
# can disconnect the network. Any cable that fails that leaves the network in two or more disconnected 
# pieces is called a single point of failure.

# She labels the different network devices from 0 to n - 1. She keeps an n × n matrix connections, where 
# connections[i][j] = 1 if there is a network cable directly connecting devices i and j, and 0 otherwise. 
# Write a function that takes the matrix of connections, and returns the number of cables that are a 
# single point of failure.




# In this function, we are iterating over all the devices in the network and removing the cable between 
# devices i and j, then we are checking whether the network is still connected or not, by using dfs to 
# check the connectivity of the network.
# If the network is not connected anymore after the removal of the cable this means that the cable is a 
# single point of failure.

def solution(connections):
    n = len(connections)
    # Initialize a variable to keep track of the number of cables that are a single point of failure
    single_point_of_failures = 0
    # iterate over all the devices
    for i in range(n):
        # iterate over all the devices
        for j in range(n):
            # check if there is a cable between devices i and j
            if connections[i][j] == 1:
                # remove the current cable between devices i and j
                connections[i][j] = 0
                # check whether the network is still connected or not
                if not is_connected(connections,n):
                    #increment the number of single point of failure cables
                    single_point_of_failures += 1
                # add the removed cable back 
                connections[i][j] = 1
    return single_point_of_failures

# check whether the network is still connected or not
def is_connected(connections,n):
    # Initialize the visited array to check the connectivity
    visited = [False] * n
    # start DFS from node 0
    dfs(connections, 0, visited)
    # check if all the devices are connected
    return all(visited)

# function to check the connectivity by DFS
def dfs(connections, v, visited):
    visited[v] = True
    for i in range(len(connections)):
        if connections[v][i] and not visited[i]:
            dfs(connections, i, visited)



# JavaScript fully working solution

# BridgesAdjacencyList class is defined which contains the logic for finding bridges in a graph. 
# The findBridges() method uses depth first search algorithm to find the bridges in the graph and dfs() 
# method is helper method used to traverse the graph.

# The solutions(connections) function takes in a matrix of connections and uses it to create an adjacency 
# list representation of the graph. It then creates an instance of the BridgesAdjacencyList class and 
# uses it to find the bridges in the graph. The number of bridges found is returned as the number of 
# single point of failures.


# class BridgesAdjacencyList {
#   constructor() {
#     //number of devices
#     this.n = 0;
#     // id to assign to vertex
#     this.id = 0;
#     //array to keep the low value of each vertex
#     this.low = [];
#     // array to keep the id of each vertex
#     this.ids = [];
#     // indicate if the graph is solved
#     this.solved = false;
#     // array to keep track of visited vertex
#     this.visited = [];
#     //adjancency list graph
#     this.graph = [];
#     // array to keep the bridges in the graph
#     this.bridges = [];
#   }
#   //find bridges in graph
#   findBridges() {
#     this.solved = true;
#     // traverse through all vertex in the graph
#     for (let i = 0; i < this.n; i++) {
#       // if vertex is not visited
#       if (!this.visited[i]) {
#         // dfs with initial parent as -1
#         this.dfs(i, -1);
#       }
#     }
#   }
#   dfs(at, parent) {
#     // mark current vertex as visited
#     this.visited[at] = true;
#     // assign id to vertex and set low as id
#     this.ids[at] = this.low[at] = ++this.id;
#     //iterate through all the adjacent vertex
#     for (let to of this.graph[at]) {
#       // if adjacent vertex is parent then skip
#       if (to === parent) continue;
#       if (!this.visited[to]) {
#         // recursively call dfs
#         this.dfs(to, at);
#         //update low value of the current vertex
#         this.low[at] = Math.min(this.low[at], this.low[to]);
#         // if id of current vertex is less than low value of adjacent vertex 
#         if (this.ids[at] < this.low[to]) {
#           // add this edge as bridge
#           this.bridges.push([at, to]);
#         }
#       } else {
#         //update low value of the current vertex
#         this.low[at] = Math.min(this.low[at], this.ids[to]);
#       }
#     }
#   }
# }

# function solution(connections) {
#   // number of devices
#   let n = connections.length;
#   // create adjacency list graph
#   let graph = new Array(n);
#   for (let i = 0; i < n; i++) {
#     graph[i] = [];
#     for (let j = 0; j < n; j++) {
#       // if there is a connection between i and j
#       if (connections[i][j] === 1) {
#         // add j to the adjacency list of i
#         graph[i].push(j);
#       }
#     }
#   }
#   //create instance of BridgesAdjacencyList class
#   let bridges = new BridgesAdjacencyList();
#   // assign graph to the instance
#   bridges.graph = graph;
#   // assign number of devices to the instance
#   bridges.n = n;
#   // call the findBridges method
#   bridges.findBridges();
#   //return number of bridges as single point failure
#   return bridges.bridges.length;
# }
