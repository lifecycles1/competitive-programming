# find the shortest path between two nodes in a graph

# copilot solution
# dictionary to represent the graph and a hash map to keep track of the shortest distances
# computes the shortest distances and the shortest path from given start to given end node
def dijkstra(graph, start, end):
    shortest_distance = {}
    predecessor = {}
    unseenNodes = graph
    infinity = 999999
    path = []
    for node in unseenNodes:
        shortest_distance[node] = infinity
    shortest_distance[start] = 0

    while unseenNodes:
        minNode = None
        for node in unseenNodes:
            if minNode is None:
                minNode = node
            elif shortest_distance[node] < shortest_distance[minNode]:
                minNode = node

        for childNode, weight in graph[minNode].items():
            if weight + shortest_distance[minNode] < shortest_distance[childNode]:
                shortest_distance[childNode] = weight + shortest_distance[minNode]
                predecessor[childNode] = minNode
        unseenNodes.pop(minNode)

    currentNode = end
    while currentNode != start:
        try:
            path.insert(0, currentNode)
            currentNode = predecessor[currentNode]
        except KeyError:
            print('Path not reachable')
            break
    path.insert(0, start)
    if shortest_distance[end] != infinity:
        print('Shortest distance is ' + str(shortest_distance[end]))
        print('And the path is ' + str(path))

graph = {
  'A': {'B': 4, 'C': 2}, 
  'B': {'D': 2, 'E': 3, 'C': 3}, 
  'C': {'B': 1, 'D': 4, 'E': 5}, 
  'D': {}, 
  'E': {'D': 1}
}
dijkstra(graph, 'A', 'E')

# jackie solution
# uses a nested dictionary to represent the graph and a priority queue to keep track of the shortest distances
# computes the shortest distances
import heapq

def dijkstra(graph, start_node):
  visited_nodes = set()
  distances = { start_node: 0 } # hashmap
  priority_queue = [(0, start_node)] # pq as a list of tuples

  while priority_queue:
    (weight, node) = heapq.heappop(priority_queue)
    if node not in visited_nodes:
      visited_nodes.add(node)
      for neighbor, distance in graph[node].items():
        if neighbor not in distances or distances[node] + distance < distances[neighbor]: 
          distances[neighbor] = distances[node] + distance # compute distance
          heapq.heappush(priority_queue, (distances[neighbor], neighbor))
  return distances


graph = {
  'A': {'B': 4, 'C': 2},
  'B': {'D': 2, 'E': 3, 'C': 3},
  'C': {'B': 1, 'D': 4, 'E': 5},
  'D': {},
  'E': {'D': 1}
}

print(dijkstra(graph, 'A'))