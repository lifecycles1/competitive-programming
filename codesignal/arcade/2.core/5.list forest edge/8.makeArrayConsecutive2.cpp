// Ratiorg got statues of different sizes as a present from CodeMaster for his birthday, 
// each statue having an non-negative integer size. Since he likes to make things perfect, 
// he wants to arrange them from smallest to largest so that each statue will be bigger than 
// the previous one exactly by 1. He may need some additional statues to be able to accomplish that. 
// Help him figure out the minimum number of additional statues needed

#include <vector>
#include <algorithm>

class Solution {
public:
  int makeArrayConsecutive2(std::vector<int> statues) {
    int min = *std::min_element(statues.begin(), statues.end());
    int max = *std::max_element(statues.begin(), statues.end());
    return max - min - statues.size() + 1;
  }
};