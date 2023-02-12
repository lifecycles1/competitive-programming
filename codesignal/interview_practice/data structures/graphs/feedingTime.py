
### COLORING GRAPH PROBLEM ### with 2 python and 1 JavaScript solutions


# You are the head zookeeper at a large zoo. You've been contacted by schools in the area that want to 
# bring in classes so that students can feed the animals. The animals can only be fed once a day, so no 
# two classes can come on the same day if they want to feed the same animals.

# You have a list classes, such that classes[i] is a list of animals that the ith class wants to feed. 
# Classes i and j cannot come on the same day if an animal in classes[i] also appears in classes[j] 
# (for i ≠ j). Your job is to determine the minimum number of days you would need to have all the classes 
# come to feed the animals if they can all come within 5 days. If it isn't possible for all the classes 
# to come within 5 days, return -1 instead.

# Example

# For classes = [["Tiger", "Lima", "Frog"], ["Tiger", "Zebra","Lion"], ["Tiger", "Rabbit"], 
# ["Emu", "Zebra", "Rabbit"]], the output should be

# solution(classes) = 3.

# Classes 0, 1, and 2 all want to feed the Tiger, so they have to come on different days. Class 3 cannot 
# come on the same day as class 1 (because of the Zebra) or class 2 (because of the Rabbit), but they can 
# come on the same day as class 0. Therefore it only takes 3 days for all the classes to visit the zoo.




# Vies this as coloring graph problem. Use brute-force backtracking algorithm.
# We have 5 colors available for each vertex. We try coloring current vertex
# in the 1st available color. Then we try to color every of its uncolored neighbor.
# If we cannot color some neighbor, it means, we have to try different color
# for current vertex. If we have colored all of its neighbors, we return True,
# meaning that graph has been colored succesfully. Else if we tried all colors
# and didn't manage to color the graph, we return False, meaning that graph
# cannot be colored using 5 colors.
# Also when we run coloring dfs function, we need to run it for every uncolored
# vertex, since graph can be disconnected, i.e. after running dfs we only color
# one connected component that has current vertex and not the whole graph.


def has_common_animals(classes, i, j):
    """ Returns True if class i and j have common animals, False otherwise.
    """
    for animal in classes[i]:
        if animal in classes[j]:
            return True
    return False


def build_graph(classes):
    """ Builds graph from classes. Graph is represented as adjacency list.
    There's an edge between node i and j if class[i] and class[j] have some
    animals in common.
    """
    graph = [[] for _ in range(len(classes))]
    classes = list(map(set, classes))
    for i in range(len(classes) - 1):
        for j in range(i + 1, len(classes)):
            if has_common_animals(classes, i, j):
                graph[i].append(j)
                graph[j].append(i)
    return graph


def find_colors(graph, curr, color):
    """ Returns array of size 5, where array[i] is True if vertex curr can be
    colored with color i, i.e. no other neighbor has this color.
    """
    available = [True] * 5
    for next_vert in graph[curr]:
        if color[next_vert] != -1:  # vertex has some color
            available[color[next_vert]] = False
    return available


def color_graph(graph, curr, color):  # main logic of algorithm is in this function
    """ Modified DFS, returns True if graph can be colored using 5 colors,
    False otherwise. Backtracking algorithm.
    """
    available = find_colors(graph, curr, color)  # list of available colors
    for i in range(5):
        if available[i]:  # we can use color i for coloring current vertex
            color[curr] = i
            for next_vert in graph[curr]:  # try to color neighbors
                if color[next_vert] == -1:  # neighboring vertex hasn't been colored
                    if not color_graph(graph, next_vert, color):
                        color[curr] = -1  # backtrack
                        break  # try different color for current vertex
            else:  # all neighbors have been colored succesfully
                return True
    return False


def solution(classes):
    graph = build_graph(classes)
    color = [-1] * len(graph)  # color[i] is color from 0 to 4 of vertex i
    for i in range(len(graph)):
        if color[i] == -1:  # vertex hasn't been colored yet
            if not color_graph(graph, i, color):  # color connected component with vertex i
                return -1
    return max(color) + 1




# Python solution 2

# def solution(classes):
#     g = [[] for _ in range(len(classes))]
#     for u, c1 in enumerate(classes):
#         for v, c2 in enumerate(classes):
#             if u != v and set(c1) & set(c2): g[u].append(v)
#     return days(g, 0, [0 for _ in range(len(g))])

# def days(g, u, colors):
#     if u == len(g): return max(colors)
#     used = set(colors[v] for v in g[u])
#     for color in [c for c in range(1, 6) if c not in used]:
#         colors[u] = color
#         num = days(g, u + 1, colors.copy())
#         if 0 <= num < 6: return num
#     return -1




# function solution(classes) {    
#     const graph = classes.map(a => new Set(a))
#         .map((s, i, ctx) => {
#             const edges = [];
#             for (const animal of s) {
#                 ctx.forEach((c, j) => {
#                     if (i !== j && c.has(animal)) edges.push(j); 
#                 });
#             }
#             return edges;
#         });
#     const marks = new Array(classes.length).fill(1);
#     const visited = new Array(classes.length).fill(false);
    
#     graph.forEach((edges, i) => {
#         const mark = marks[i];
#         visited[i] = true;
#         edges.forEach(node => {
#             if (!visited[node] && marks[node] === mark) {
#                 marks[node] = mark + 1;
#             }
#         });
#     });
    
#     const days = Math.max(...marks);
#     return days > 5 ? -1 : days;
# }
