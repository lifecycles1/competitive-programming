// Some people run along a straight line in the same direction. They start simultaneously at pairwise 
// distinct positions and run with constant speed (which may differ from person to person).

// If two or more people are at the same point at some moment we call that a meeting. The number of 
// people gathered at the same point is called meeting cardinality.

// For the given starting positions and speeds of runners find the maximum meeting cardinality assuming 
// that people run infinitely long. If there will be no meetings, return -1 instead.

// Example

// For startPosition = [1, 4, 2] and speed = [27, 18, 24], the output should be
// solution(startPosition, speed) = 3.

// In 20 seconds after the runners start running, they end up at the same point. Check out the gif below 
// for better understanding:

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int solution(std::vector<int> startPosition, std::vector<int> speed) {
      int d = startPosition.size();
      int l = speed.size();
      int x = 1;
      for (int i = 0; i < d; i++)
          for (int j = i + 1; j < l; j++) {
              int P = startPosition[j] - startPosition[i];
              int S = speed[i] - speed[j];
              int c = 0;
              int k = 0;
              while (S && k < d)
                  c += (startPosition[k] - startPosition[i]) * S == (speed[i] - speed[k]) * P, k++;
                x = std::max(x, c); }
      return x > 1 ? x : -1; 
    }
};