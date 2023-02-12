// Design a data structure that supports adding new words and finding if a string matches any 
// previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or 
// false otherwise. word may contain dots '.' where dots can be matched with any letter.

//  Design add & search words data structure
//  Implement trie, handle wildcards: traverse all children & search substrings
//  Time: O(m x 26^n) -> m = # of words, n = length of words
//  Space: O(n)

#include <limits.h>
#include <string>
using namespace std;

class TrieNode {
public:
  TrieNode* children[26];
  bool isWord;

  TrieNode() {
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
    isWord = false;
  }
};

class WordDictionary {
public:
  WordDictionary() {
    root = new TrieNode();
  }
  void addWord(string word) {
    TrieNode* node = root;
    int curr = 0;

    for (int i = 0; i < word.size(); i++) {
      curr = word[i] - 'a';
      if (node->children[curr] == NULL) {
        node->children[curr] = new TrieNode();
      }
      node = node->children[curr];
    }
    node->isWord = true;
  }

  bool search(string word) {
    TrieNode* node = root;
    return searchInNode(word, 0, node);
  }

private:
  TrieNode* root;

  bool searchInNode(string& word, int i, TrieNode* node) {
    if (node == NULL) {
      return false;
    }
    if (i == word.size()) {
      return node->isWord;
    }
    if (word[i] != '.') {
      return searchInNode(word, i + 1, node->children[word[i] - 'a']);
    }
    for (int j = 0; j < 26; j++) {
      if (searchInNode(word, i+1, node->children[j])) {
        return true;
      }
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */