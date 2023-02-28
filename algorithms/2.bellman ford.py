# find the shortest path between two nodes in a graph
# can handle negative weights

# assumes that the graph is represented as a dictionary of lists, where each key represents 
# a vertex and the corresponding value is a list of tuples that represent the neighboring 
# vertices and their edge weights.
def bellmanFord(graph, source):
    distance = {node: float('inf') for node in graph}
    distance[source] = 0
    for _ in range(len(graph) - 1):
        for node in graph:
            for neighbour in graph[node]:
                if distance[node] + graph[node][neighbour] < distance[neighbour]:
                    distance[neighbour] = distance[node] + graph[node][neighbour]
    return distance

# assumes that the graph is represented as a dictionary of dictionaries, 
# where the outer dictionary maps each vertex to a dictionary that maps its 
# neighbors to their edge weights.
def bellmanFord(graph, source):
    # Step 1: Initialize distances from source to all vertices as infinite
    # and mark source as visited
    distance = {v: float('inf') for v in graph}
    distance[source] = 0

    # Step 2: Relax edges repeatedly
    for _ in range(len(graph) - 1):
        for u in graph:
            for v, weight in graph[u].items():
                if distance[u] != float('inf') and distance[u] + weight < distance[v]:
                    distance[v] = distance[u] + weight

    # Step 3: Check for negative-weight cycles
    for u in graph:
        for v, weight in graph[u].items():
            if distance[u] != float('inf') and distance[u] + weight < distance[v]:
                print("Graph contains negative-weight cycle")
                return

    # Step 4: Return the distance dictionary
    return distance


graph = {
  'A': {'B': 4, 'C': 2},
  'B': {'D': 2, 'E': 3, 'C': 3},
  'C': {'B': 1, 'D': 4, 'E': 5},
  'D': {},
  'E': {'D': 1}
}
print(bellmanFord(graph, 'A'))


