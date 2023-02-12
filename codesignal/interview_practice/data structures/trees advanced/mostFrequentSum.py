# The sum of a subtree is the sum of all the node values in that subtree, including its root.

# Given a binary tree of integers, find the most frequent sum (or sums) of its subtrees.

# If all the sum values in a tree occur only once, return all of them in ascending order.


#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None

# python solution 1

def solution(t):
    # If the tree is empty, return an empty list
    if not t:
        return []
    # Create a dictionary to store the frequency of each sum
    freq_map = {}
    def dfs(node):
        # If the current node is None, return 0
        if not node:
            return 0
        # Calculate the sum of the subtree rooted at the current node
        sum_subtree = node.value + dfs(node.left) + dfs(node.right)
        # If the sum already exists in the dictionary, increment its frequency
        if sum_subtree in freq_map:
            freq_map[sum_subtree] += 1
        # Otherwise, add the sum to the dictionary with a frequency of 1
        else:
            freq_map[sum_subtree] = 1
        # Return the sum of the subtree rooted at the current node
        return sum_subtree
    # Call the helper function to traverse the tree and populate the dictionary
    dfs(t)
    # Find the maximum frequency
    max_freq = max(freq_map.values())
    # Create a list of the sums with the maximum frequency
    result = [s for s, freq in freq_map.items() if freq == max_freq]
    # Sort the list in ascending order
    result.sort()
    # Return the list of most frequent sums
    return result

# python solution 2

sums = {}

def solution(t):
    get_freqs(t)
    mf = max(sums.values()) if sums else -1
    return sorted(v for v, f in sums.items() if f == mf) if sums else []
    
def get_freqs(t):
    if t is None: return 0
    s = get_freqs(t.left) + get_freqs(t.right) + t.value
    sums[s] = sums[s] + 1 if s in sums else 1
    return s

# javascript solution

# function solution(t) {
#   const sums = {};
#   const f = (t) => {
#     if (!t) return 0;
#     const leftSum = f(t.left);
#     const rightSum = f(t.right);
#     const sum = t.value + leftSum + rightSum;
#     sums[sum] = (sums[sum] || 0) + 1;
#     return sum;
#   };
#   f(t);
#   const maxCount = Math.max(...Object.values(sums));
#   const freqSums = Object.keys(sums)
#     .filter((k) => sums[k] === maxCount)
#     .map((v) => parseInt(v));
#   return freqSums.sort((a, b) => a - b);
# }
