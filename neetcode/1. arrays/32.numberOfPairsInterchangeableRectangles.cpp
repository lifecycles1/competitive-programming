// You are given n rectangles represented by a 0-indexed 2D integer array rectangles, where 
// rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.

// Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height 
// ratio. More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj 
// (using decimal division, not integer division).

// Return the number of pairs of interchangeable rectangles in rectangles.

// Approach: 
// Keep the track of the ratios in a hash map
// Time complexity : O(n)
// Space complexity: O(n)
// n is number of rectangles

#include <vector>
#include <map>
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution {
public:
  long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    map<long double, int> hash;
    long double ratio;
    long long answer = 0;
    for (int i = 0; i < rectangles.size(); i++) {
      ratio = (long double)(rectangles[i][0]) / (long double)(rectangles[i][1]);
      if (hash.find(ratio) != hash.end()) {
        hash[ratio]++;
      } else {
        hash[ratio] = 1;
      }
    }
    for (auto it : hash) {
      answer += (long long)(it.second) * (long long)(it.second-1) / 2;
    }
    return answer;
  }
};

class Solution {
public:
  long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    long long result = 0;
    map<pair<int, int>, int> mp;
    for (auto& rect : rectangles) {
      int gcDivisor = gcd(rect[0], rect[1]);
      pair<int, int> key = {rect[0]/gcDivisor, rect[1]/gcDivisor};
      if (mp.find(key) != mp.end()) {
        result += mp[key];
      }
      mp[key]++;
    }
    return result;
  }
};

// one of the fastest solution
class Solution {
public:
  long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    long long ans = 0;
    unordered_map<double, int> freq;
    for (auto& rec : rectangles) {
      double ratio = (double) rec[0]/rec[1];
      ans += freq[ratio];
      freq[ratio]++;
    }
    return ans;
  }
};

class Solution {
public:
  long long interchangeableRectangles(vector<vector<int>>& rectangles) {
    long long result = 0;
    map<double, int> mp;

    // calculate the div
    for (auto& rectangle : rectangles) {
      double div = (double)rectangle[1] / (double)rectangle[0];
      mp[div] = mp[div] + 1;
    }
    // sigma the total count for each div
    for (auto count : mp) {
      for (int i = 1; i < count.second; i++) {
        result += i;
      }
    }
    return result;
  }
};

// fastest solutions
class Solution {
public:
  long long func(int n) {
    int a = n, b = n-1;
    if(a%2 == 0) {
       a /= 2;
    }
    else {
      b /= 2;
    }
    return (long long)a * b;
  }
  long long interchangeableRectangles(vector<vector<int>>& a) {
    int n = a.size();
    long long count = 0;
    unordered_map<double,int> mp;
    for(int i=0; i<n; i++) {
        double rect = (double)a[i][0]/a[i][1];
        mp[rect]++;
    }
    for(auto i: mp) {
        long long res = func(i.second);
        count += res;
    }
    return count;
  }
};