# As a director of a large company, you try to do your best to make the working environment as efficient 
# as possible. However, it's difficult to do so when even the hardware used in the office is not efficient:
# there are too many wires connecting your employees' computers.

# Naturally, you decided to minimize their number by getting rid of some wires. There's only one 
# constraint: if it is possible to deliver information from one computer to another one using the wires, 
# it should still be possible to do so after the renovation. You would also like to minimize the total 
# wires length, because the longer the wires, the more it possible for you to trip over them at some point.

# Given the plan of your n office computers and the wires connecting them, find the minimum resulting 
# length of the wires after removing some of them according to the constraints above.

# It is guaranteed that there is no more than one wire between each pair of computers.


# [input] integer n: The number of computers in your office.

# [input] array.array.integer wires:
# Information about the wires connecting computers. For each valid i, wires[i] contains three numbers: 
# wires[i][0] and wires[i][1] stand for the ids of computers ith wire connects, and wires[i][2] stands 
# for the length of this wire.




def find_set(x, link):
    """
    Find the representative of the set to which a node belongs
    """
    if x != link[x]:
        link[x] = find_set(link[x], link) # path compression
    return link[x]

def solution(n, wires):
    """
    Find the minimum spanning tree of a graph using Kruskal's algorithm
    """
    link = {x: x for x in range(n)}  # initialize each node as its own set
    res = 0 # Initialize the result to 0
    for x, y, d in sorted(wires, key=lambda x: x[-1]):
        rep_x, rep_y = find_set(x, link), find_set(y, link)
        if rep_x != rep_y:  # check if adding edge (x, y) would create a cycle
            link[rep_x] = rep_y  # union the sets
            res += d  # add the edge weight to the total cost
    return res # Return the total cost

# The above solution is using the technique of Union-Find (also known as Disjoint-Set) which is a data structure that 
# keeps track of a partitioning of a set of elements into a number of disjoint (non-overlapping) subsets.

# The function `find_set` is a helper function which is used to find the representative element of a set that an 
# element is in, by using a technique called path compression. It traverses the tree of the set that the element 
# is in, and attaches every encountered node directly to the representative element.

# The function `solution` is the main function that solves the problem, it uses the Union-Find data structure to keep 
# track of the disjoint sets of vertices. it starts by initializing the link dictionary, then it iterates over 
# the edges of the graph in order of increasing weight, and for each edge it finds the representative element 
# of each set that the vertices of the edge are in. If the representative elements are different, it means that 
# the vertices are not in the same set, so it connects them by making the representative of one set the parent 
# of the other and increments the result variable by the weight of the edge.

# The key idea of this solution is that it uses the Union-Find data structure to keep track of the disjoint sets 
# of vertices and to ensure that adding an edge will not create a cycle. The solution sorts the edges by weight, 
# and for each edge it considers, it checks whether the two vertices are in the same set or not, if not it 
# connects them and adds the weight of the edge to the result variable. By doing this, the algorithm guarantees 
# that it will only add edges that are part of the minimum spanning tree.

# This is the implementation of Kruskal's algorithm, which is a well-known algorithm for finding the minimum 
# spanning tree of a graph.


# [output] integer: The minimum resulting length of the wires after removing some of them.


