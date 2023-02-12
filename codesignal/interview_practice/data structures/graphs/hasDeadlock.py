# In a multithreaded environment, it's possible that different processes will need to use the same
# resource. A wait-for graph represents the different processes as nodes in a directed graph, where an 
# edge from node i to node j means that the node j is using a resource that node i needs to use 
# (and cannot use until node j releases it).

# We are interested in whether or not this digraph has any cycles in it. If it does, it is possible for 
# the system to get into a state where no process can complete.

# We will represent the processes by integers 0, ...., n - 1. We represent the edges using a 
# two-dimensional list connections. If j is in the list connections[i], then there is a directed edge 
# from process i to process j.

# Write a function that returns True if connections describes a graph with a directed cycle, or False 
# otherwise.






# The function uses depth-first search (dfs) to traverse the graph and keep track of visited nodes in the 
# visited list and nodes that are currently in the recursion stack in the rec_stack list. If a node is 
# encountered that has already been visited and is currently in the recursion stack, then a cycle is
# present and the function returns True. If all nodes have been visited and no cycles are present, the
#  function returns False.

def solution(connections):
    # Helper function to check for cycles in a directed graph using depth-first search
    def dfs(i, visited, rec_stack):
      # Mark the current node as visited
      visited[i] = True
      # Add the current node to the recursion stack
      rec_stack[i] = True
      # Visit all the neighbors of the current node
      for j in connections[i]:
        # If neighbor has not been visited, visit it
        if not visited[j]:
          if dfs(j, visited, rec_stack):
            return True
        # If neighbor is already in the recursion stack, there is a cycle
        elif rec_stack[j]:
          return True
      # Remove the current node from the recursion stack
      rec_stack[i] = False
      return False
    # Get the number of nodes in the graph
    n = len(connections)
    # Initialize lists to keep track of visited nodes and the recursion stack
    visited = [False] * n
    rec_stack = [False] * n
    # Visit all the nodes
    for i in range(n):
      if not visited[i]:
        if dfs(i, visited, rec_stack):
          return True
    return False
