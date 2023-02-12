// In an alien language, surprisingly, they also use English lowercase letters, 
// but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

// Given a sequence of words written in the alien language, and the order of the alphabet, 
// return true if and only if the given words are sorted lexicographically in this alien language.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool compare(string& a, string& b, string& order) {
    int i = 0;
    while (i < a.size() && a[i] == b[i]) {
      i++;
    }
    if (a.size() == i) {
      return true;
    } else if (b.size() == i) {
      return false;
    }
    return (order.find(a[i]) < order.find(b[i]));
  }
  
  bool isAlienSorted(vector<string>& words, string order) {
    for (int i = 0; i < words.size() - 1; i++) {
      if (!compare(words[i], words[i+1], order)) {
        return false;
      }
    }
    return true;
  }
};

class Solution {
public:
  bool isAlienSorted(vector<string>& words, string order) {
    for (int i = 0; i < words.size() - 1; i++) {
      string word1 = words[i];
      string word2 = words[i+1];
      int i1 = 0;
      int i2 = 0;
      while (word1[i1] == word2[i2]) {
        i1++;
        i2++;
      }
      int r = order.find(word1[i1]);
      int s = order.find(word2[i2]);
      if (r > s) {
        return false;
      }
    }
    return true;
  }
};