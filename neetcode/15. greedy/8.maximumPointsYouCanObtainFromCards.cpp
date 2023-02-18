// There are several cards arranged in a row, and each card has an associated number of points. 
// The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. 
// You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.

// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

#include <vector>
using namespace std;

class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    int sum = 0;
    int n = cardPoints.size();
    
    vector<int> cummulativeSumFromFront(n+1, 0);
    vector<int> cummulativeSumFromBehind(n+1, 0);
    
    sum = 0;
    for (int i=0; i<n; i++) {
      sum += cardPoints[i];
      cummulativeSumFromFront[i+1] = sum;
    }
    sum = 0;
    for (int i=n-1; i>=0; i--) {
      sum += cardPoints[i];
      cummulativeSumFromBehind[i] = sum;
    }
    
    // Reversing is optional. I reversed it so that it would be easy
    // to access sum of last (k-i) elements by just indexing at [k-i]
    // Otherwise, I would have had to index it at [n-k+i] which would
    // have made it difficult to read.
    reverse(cummulativeSumFromBehind.begin(), cummulativeSumFromBehind.end());
    
    int answer = 0;
    for(int i=0; i<=k; i++) {      
      answer = max(answer, 
                    cummulativeSumFromFront[i] // Sum of first 'i' cards.
                  + cummulativeSumFromBehind[k-i]); // Sum of last 'k-i' cards.
    }
    return answer;
  }
};

// 97% faster sliding window solution
class Solution {
public:
  int maxScore(vector<int>& C, int K) {
    int total = 0;
    for (int i = 0; i < K; i++) total += C[i];
    int best = total;
    for (int i = K - 1, j = C.size() - 1; ~i; i--, j--)
      total += C[j] - C[i], best = max(best, total);
    return best;
  }
};