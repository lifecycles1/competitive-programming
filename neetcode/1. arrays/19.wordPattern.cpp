// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in 
// pattern and a non-empty word in s.


# include <string>
# include <vector>
# include <unordered_map>
# include <sstream>
using namespace std;

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    vector<int> pat_map(26, 0);
    unordered_map<string, int> str_map;
    int i = 0;
    int n = pattern.size();
    istringstream ss(s);
    string token;
    
    for (string token; ss >> token; i++) {
      if (i == n || pat_map[pattern[i]-'a'] != str_map[token]) {
        return false;
      }
      // 1-based indexing since map assings 0 as a default value for keys not found.
      pat_map[pattern[i]-'a'] = str_map[token] = i+1;
    }
    return i == n;
  }
};