# A tree height can be calculated as the length of the longest path in it (it is also called tree diameter)
# So, now you have a task you need to solve, so go ahead!

# [input] integer n is: The number of vertices in the structure
# [input] array: tree = [[2, 5], [5, 7], [5, 1], [1, 9], [1, 0], [7, 6], [6, 3], [3, 8], [8, 4]]


def solution(n, tree):
    # Create an adjacency list to store the edges of the tree
    graph = [[] for _ in range(n)]
    for u, v in tree:
        graph[u].append(v)
        graph[v].append(u)

    # Helper function to perform a breadth-first search (BFS)
    def bfs(root):
        # Initialize a queue with the starting node and distance
        queue = [(root, 0)]
        # Initialize a set to keep track of visited nodes
        seen = {root}
        # Iterate through the queue
        for node, d in queue:
            # Iterate through the neighbours of the current node
            for nei in graph[node]:
                if nei not in seen:
                    seen.add(nei)
                    queue.append((nei, d+1))
        # Return the last node and its distance from the starting node
        return node, d

    # Perform the BFS starting from node 0
    # Then, perform the BFS starting from the last node found in the first BFS
    # The distance returned by the second BFS is the diameter of the tree
    return bfs(bfs(0)[0])[1]

