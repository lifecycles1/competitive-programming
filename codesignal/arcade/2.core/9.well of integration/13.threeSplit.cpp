// You have a long strip of paper with integers written on it in a single line from left to right. 
// You wish to cut the paper into exactly three pieces such that each piece contains at least one 
// integer and the sum of the integers in each piece is the same. You cannot cut through a number, 
// i.e. each initial number will unambiguously belong to one of the pieces after cutting. 
// How many ways can you do it?

// It is guaranteed that the sum of all elements in the array is divisible by 3.

#include <vector>
using namespace std;

class Solution {
public:
  int threeSplit(vector<int> a) {
    long sum = 0;
    for (auto x : a) {
      sum += x;
    }
    long find = sum / 3;
    
    int cut1 = 0;
    int total = 0;
    sum = 0;
    for (int i = 0; i < a.size()-1; i++) {
      int x = a[i];
      sum += x;
      total += (sum == 2*find ? cut1 : 0);
      cut1 += (sum == find);
    }
    return total;
  }
};