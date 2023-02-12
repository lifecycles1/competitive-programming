




# JS solution with Trie data structure, DFS, and backtracking

# function solution(board, words) {
#   // Set up a trie data structure to store the words
#   const trie = new Trie();
#   for (const word of words) {
#     trie.insert(word);
#   }

#   // Set up a set to store the found words
#   const foundWords = new Set();

#   // Set up a 2D array to store the visited cells
#   const visited = Array(board.length).fill(null).map(() => Array(board[0].length).fill(false));

#   // Iterate through all cells of the board
#   for (let i = 0; i < board.length; i++) {
#     for (let j = 0; j < board[0].length; j++) {
#       // Start a depth-first search from each cell
#       dfs(i, j, trie.root, visited, foundWords, board);
#     }
#   }

#   // Return the array of found words
#   return [...foundWords].sort();
# }

# function dfs(i, j, trieNode, visited, foundWords, board) {
#   // Check if the character at the current cell is a child of the current trie node
#   if (!trieNode.children.has(board[i][j])) {
#     return;
#   }

#   // Mark the current cell as visited
#   visited[i][j] = true;

#   // Check if the current cell is a word in the trie
#   const nextTrieNode = trieNode.children.get(board[i][j]);
#   if (nextTrieNode.isWord) {
#     foundWords.add(nextTrieNode.word);
#   }

#   // Explore the 8 neighbors of the current cell
#   for (const [di, dj] of [[0, 1], [0, -1], [1, 0], [-1, 0], [-1, -1], [1, 1], [1, -1], [-1, 1]]) {
#     const ni = i + di;
#     const nj = j + dj;
#     if (ni >= 0 && ni < board.length && nj >= 0 && nj < board[0].length && !visited[ni][nj]) {
#       // If the neighbor is in the board and not visited, search for the word starting from the neighbor
#       dfs(ni, nj, nextTrieNode, visited, foundWords, board);
#     }
#   }

#   // Mark the current cell as not visited
#   visited[i][j] = false;
# }

# class TrieNode {
#   constructor() {
#     this.children = new Map();
#     this.isWord = false;
#     this.word = null;
#   }
# }

# class Trie {
#   constructor() {
#     this.root = new TrieNode();
#   }

#   insert(word) {
#     let node = this.root;
#     for (const c of word) {
#       if (!node.children.has(c)) {
#         node.children.set(c, new TrieNode());
#       }
#       node = node.children.get(c);
#     }
#     node.isWord = true;
#     node.word = word;
#   }
# }



# Python solution with DFS and backtracking
def solution(board, words):
  r = []
  for word in words:
    if canBoggle(board,word):
      r.append(word)
  return sorted(r)

def canBoggle(board, word, used = []):
  if len(word) == 0:
    return True
  for i in range(len(board)):
    for j in range(len(board[0])):
      if (i,j) not in used and board[i][j] == word[0]:
        if len(used)==0 or (abs(used[-1][0] - i)<=1 and abs(used[-1][1] - j)<= 1):
          if canBoggle(board,word[1:],used + [(i,j)]):
            return True
  return False        