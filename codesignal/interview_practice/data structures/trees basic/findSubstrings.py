# You have two arrays of strings, words and parts. Return an array that contains the strings from words, modified 
# so that any occurrences of the substrings from parts are surrounded by square brackets [], following these 
# guidelines:

# If several parts substrings occur in one string in words, choose the longest one. If there is still more than 
# one such part, then choose the one that appears first in the string.

# Python solution 1

# The function uses a trie data structure to store the parts array. Then it iterates over each word and finds the 
# longest substring of the word that is present in the trie. Once it finds the longest substring, it surrounds it 
# with square brackets and returns the modified word. 
# Also, it will only surround the first occurrence of the substring in the word by brackets.

class TrieNode(object):
  def __init__(self, x):
    self.value = x
    self.terminal = False
    self.children = {}
        
def addWordToTrie(root, word):
  currNode = root
  
  for letter in word:
    if letter not in currNode.children:
      currNode.children[letter] = TrieNode(letter)
    currNode = currNode.children[letter]
  currNode.terminal = True
    
def findSubstringInWord(word, root):
  longestLen, longestPos = 0, 0
  
  for startPos in range(len(word)):
    currNode = root
    
    for pos in range(startPos, len(word)):
      letter = word[pos]
      if letter not in currNode.children:
        break
      
      currNode = currNode.children[letter]
      length = pos - startPos + 1
      if currNode.terminal and length > longestLen:
        longestLen, longestPos = length, startPos
  if longestLen == 0:
    return word
  end = longestLen + longestPos
  return word[:longestPos] + "[" + word[longestPos: end] + "]" + word[end:]

def solution(words, parts):
    root = TrieNode(None)
    
    for part in parts:
      addWordToTrie(root, part)
    return [findSubstringInWord(word, root) for word in words]
    


# Python solution 2

class Trie(object):
  def __init__(self):
    self.nxt = {}
    self.end = False

  def add(self, word):
    if not word:
      self.end = True
    else:
      self.nxt.setdefault(word[0], Trie()).add(word[1:])


def solution(words, parts):
  trie = Trie()
  for x in parts:
    trie.add(x)
  for i, w in enumerate(words):
    pos = len(w)
    L = -1
    for j in range(len(w)):
      t = trie
      k = j
      while k < len(w) and w[k] in t.nxt:
        t = t.nxt[w[k]]
        k += 1
        if t.end and k - j > L:
          L = k - j
          pos = j
    if L > 0:
      words[i] = "%s[%s]%s" % (w[:pos], w[pos:pos+L], w[pos+L:])
  return words
