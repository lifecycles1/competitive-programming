//A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and 
//retrieve keys in a dataset of strings. There are various applications of this data structure, such as 
//autocomplete and spellchecker.

//Implement the Trie class:

//Trie() Initializes the trie object.
//void insert(String word) Inserts the string word into the trie.
//boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before),
//and false otherwise.
//boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has 
//the prefix prefix, and false otherwise.

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

class Trie {
public:
  Trie() {
    root = new TrieNode();
  }

  void insert(string word) {
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
    int curr = 0;

    for (int i = 0; i < word.size(); i++) {
      curr = word[i] - 'a';
      if (node->children[curr] == NULL) {
        return false;
      }
      node = node->children[curr];
    }
    return node->isWord;
  }

  bool startsWith(string prefix) {
    TrieNode* node = root;
    int curr = 0;

    for (int i = 0; i < prefix.size(); i++) {
      curr = prefix[i] - 'a';
      if (node->children[curr] == NULL) {
        return false;
      }
      node = node->children[curr];
    }
    return true;
  }

private:
  TrieNode* root;

};