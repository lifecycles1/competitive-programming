// You are given two strings s and t of the same length, consisting of uppercase English letters. 
// Your task is to find the minimum number of "replacement operations" needed to get some anagram 
// of the string t from the string s. A replacement operation is performed by picking exactly one 
// character from the string s and replacing it by some other character.

#include <string>
#include <vector>

class Solution {
public:
  int createAnagram(std::string s, std::string t) {
    std::vector<int> buckets(26, 0);
    for(auto c : s) {
      buckets[c-'A']++;
    }
    for(auto c : t) {
      buckets[c-'A']--;
    }
    int count = 0;
    for(auto i : buckets) {
      count += abs(i);
    }
    return count/2;
  }
};