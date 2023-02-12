// You are keeping the scores for a baseball game with strange rules. At the beginning of the game, 
// you start with an empty record.

// You are given a list of strings operations, where operations[i] is the ith operation you must apply 
// to the record and is one of the following:

// An integer x.
// Record a new score of x.
// '+'.
// Record a new score that is the sum of the previous two scores.
// 'D'.
// Record a new score that is the double of the previous score.
// 'C'.
// Invalidate the previous score, removing it from the record.
// Return the sum of all the scores on the record after applying all the operations.

// The test cases are generated such that the answer and all intermediate calculations fit in a 
// 32-bit integer and that all operations are valid.

# include <vector>
# include <string>
# include <stack>
using namespace std;

class Solution {
public:
  int calPoints(vector<string>& ops) {
    stack<int> stack;
    int sum = 0;

    for (int i = 0; i < ops.size(); i++) {
      if (ops[i] == "+") {
        int first = stack.top();
        stack.pop();

        int second = stack.top();
        stack.push(first);
        stack.push(first + second);
        sum += first + second;
      } else if (ops[i] == "D") {
        sum += 2 * stack.top();
        stack.push(2 * stack.top());
      } else if (ops[i] == "C") {
        sum -= stack.top();
        stack.pop();
      } else {
        sum += stoi(ops[i]);
        stack.push(stoi(ops[i]));
      }
    }
    return sum;
  }
};