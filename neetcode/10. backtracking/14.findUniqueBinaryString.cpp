// Given an array of strings nums containing n unique binary strings each of length n, 
// return a binary string of length n that does not appear in nums. If there are multiple answers, 
// you may return any of them.

#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  string findDifferentBinaryString(vector<string>& nums) {
    string ans = "";
    for (int i = 0; i < nums.size(); i++) {
      ans += nums[i][i] == '0' ? '1' : '0';
    }
    return ans;
  }
};

// backtracking
class Solution {
public:
  string findDifferentBinaryString(vector<string> &nums) {
    int n = nums[0].size();
    string path = "";
    return dfs(nums , n , path);
  }

  string dfs(vector<string> &nums , int n , string &path) {
    if(path.size() == n) {
      if(find(nums.begin() , nums.end() , path) == nums.end())
        return path;
      else
        return ""; // means current path string formed already exists in nums , so it can't be the ans
    }
    
    string s;
    
    // include 1
    path.push_back('1');
    s = dfs(nums , n , path);// means required string is found so no need for further calls
    if(s != "") return s;
    path.pop_back(); // backtrack
      
    // include 0
    path.push_back('0');
    s = dfs(nums , n , path);
    if(s != "") return s; // means required string is found so no need for further calls
    path.pop_back(); // backtrack
    
    return "";
  }
};