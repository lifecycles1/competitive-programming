// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. 
// You may assume that the majority element always exists in the array.

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
using namespace std;

// hash table
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int& i : nums) {
      if (++mp[i] > n/2) {
        return i;
      }
    }
    return -1;
  }
};

// sorting
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
  }
};

// randomization
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int n = nums.size(); 
    int candidate; 
    int counter;

    srand(unsigned(time(NULL)));
    while (true) {
      candidate = nums[rand() % n];
      counter = 0;
      for (int num : nums) {
        if (num == candidate) {
          counter++;
        }
      }
      if (counter > n/2) {
        break;
      }
    }
    return candidate;
  }
};

// divide and conquer
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    return majority(nums, 0, nums.size() - 1);
  }
private:
  int majority(vector<int>& nums, int l, int r) {
    if (l == r) {
      return nums[l];
    }
    int m = l + (r - l) / 2;
    int lm = majority(nums, l, m);
    int rm = majority(nums, m+1, r);
    if (lm == rm) {
      return lm;
    }
    return count(nums.begin() + l, nums.begin() + r + 1, lm) > count(nums.begin() + l, nums.begin() + r + 1, rm) ? lm : rm; 
  }
};

// Boyer-Moore Voting Algorithm
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int counter = 0;
    int majority = 0;
    for (int num : nums) {
      if (!counter) {
        majority = num;
      }
      counter += num == majority ? 1 : -1;
    }
    return majority;
  }
};

// Bit Manipulation
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int majority = 0;
    for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
      int bits = 0;
      for (int num : nums) {
        if (num & mask) {
          bits++;
        }
      }
      if (bits > nums.size() / 2) {
        majority |= mask;
      }
    }
    return majority;
  }
};