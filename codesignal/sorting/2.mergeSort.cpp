
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> mergeSort(std::vector<int> a) {
    if (a.size() == 1) return a;
    int mid = a.size() / 2;
    std::vector<int> left(a.begin(), a.begin() + mid);
    std::vector<int> right(a.begin() + mid, a.end());
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
  }
  std::vector<int> merge(std::vector<int> left, std::vector<int> right) {
    std::vector<int> result;
    while (left.size() > 0 || right.size() > 0) {
      if (left.size() > 0 && right.size() > 0) {
        if (left.front() <= right.front()) {
          result.push_back(left.front());
          left.erase(left.begin());
        } else {
          result.push_back(right.front());
          right.erase(right.begin());
        }
      } else if (left.size() > 0) {
        result.push_back(left.front());
        left.erase(left.begin());
      } else if (right.size() > 0) {
        result.push_back(right.front());
        right.erase(right.begin());
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  std::vector<int> a = {1, 3, 5, 7, 2, 4, 6, 8};
  std::vector<int> b = s.mergeSort(a);
  for (int i = 0; i < b.size(); i++) {
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}