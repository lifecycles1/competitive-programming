// A step(x) operation works like this: it changes a number x into x - s(x), where s(x) is the sum 
// of x's digits. You like applying functions to numbers, so given the number n, you decide to build 
// a decreasing sequence of numbers: n, step(n), step(step(n)), etc., with 0 as the last element.

// Building a single sequence isn't enough for you, so you replace all elements of the sequence with 
// the sums of their digits (s(x)). Now you're curious as to which number appears in the new sequence 
// most often. If there are several answers, return the maximal one.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

class Solution {
public:
  int mostFrequentDigitSum(int n) {
    std::map<int, int> m;
    while (n) {
      int s = 0;
      for (int c = n; c; c /= 10) {
        s += c % 10;
      }
      m[s]++;
      n -= s;
    }
    return std::max_element(m.begin(), m.end(), [](const auto& l, const auto& r) {
      return l.second != r.second ? l.second < r.second : l.first < r.first;
    })->first;
  }
};

class Solution {
public:
  int mostFrequentDigitSum(int n) {
    std::vector<int> a = {n};
    int c = n;
    auto s = [](int x) -> int {
      int sum = 0;
      std::string str_x = std::to_string(x);
      for (char c : str_x) {
        sum += c - '0';
      }
      return sum;
    };
    while (c > 0) {
      c -= s(c);
      a.push_back(c);
    }
    std::vector<int> a_sorted(a.size());
    std::transform(a.begin(), a.end(), a_sorted.begin(), s);
    std::sort(a_sorted.begin(), a_sorted.end(), std::greater<int>());
    return *std::max_element(a_sorted.begin(), a_sorted.end(), [&a_sorted](int a, int b) {
      return std::count(a_sorted.begin(), a_sorted.end(), a) < std::count(a_sorted.begin(), a_sorted.end(), b);
    });
  }
};