// Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
// You may return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 20% runtime
class Solution {
public:
  unordered_map<char, int> Create(string p) {
    unordered_map<char, int> Mapp;
    for (char& i : p) {
      if (Mapp.find(i) == Mapp.end()) {
        Mapp.insert(make_pair(i, 1));
      } else {
        Mapp[i]++;
      }
    }
    return Mapp;
  }
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> Mapp = {};
    unordered_map<char, int> Maps;
    vector<int> nums = {};
    int Fp = 0;
    int Sp = p.length();
    int lens = s.length();
    int lenp = p.length();
    Mapp = Create(p);
    Maps = Create(s.substr(0, p.length()));
    for (Fp = 0; Fp < lens - lenp + 1; Fp++) {
      if (Maps == Mapp) {
        nums.push_back(Fp);
      }
      if (Maps.find(s[Sp]) != Maps.end()) {
        Maps[s[Sp]]++;
      } else {
        Maps.insert(make_pair(s[Sp], 1));
      }
      Sp++;
      Maps[s[Fp]]--;
      if (Maps[s[Fp]] == 0) {
        Maps.erase(s[Fp]);
      }
    }
    return nums;
  }
};

// 75% runtime. vector and sliding window technique.
// Time Complexity = O(n * 26) = O(n), n is the length of string s.
// Space Complexity = O(26) = O(1)
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int s_len = s.length();
    int p_len = p.length();
    if (s.size() < p.size()) {
      return {};
    }
    vector<int> freq_p(26, 0);
    vector<int> window(26, 0);

    // first window
    for (int i = 0; i < p_len; i++) {
      freq_p[p[i] - 'a']++;
      window[s[i] - 'a']++;
    }

    vector<int> ans;
    if (freq_p == window) {
      ans.push_back(0);
    }

    for (int i = p_len; i < s_len; i++) {
      window[s[i-p_len] - 'a']--;
      window[s[i] - 'a']++;

      if (freq_p == window) {
        ans.push_back(i-p_len+1);
      }
    }
    return ans;
  }
};