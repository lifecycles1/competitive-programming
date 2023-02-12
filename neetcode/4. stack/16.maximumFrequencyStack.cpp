// Design a stack-like data structure to push elements to the stack and pop the most frequent 
// element from the stack.

// Implement the FreqStack class:

// FreqStack() constructs an empty frequency stack.
// void push(int val) pushes an integer val onto the top of the stack.
// int pop() removes and returns the most frequent element in the stack.
// If there is a tie for the most frequent element, the element closest to the stack's top 
// is removed and returned.

#include <unordered_map>
#include <stack>
using namespace std;

class FreqStack {
public:
  FreqStack() : maxCnt(0) {}

  void push(int val) {
    int valCnt = 1 + cnt[val];
    cnt[val] = valCnt;
    if (valCnt > maxCnt) {
      maxCnt = valCnt;
      stacks[valCnt] = {};
    }
    stacks[valCnt].push(val);
  }

  int pop() {
    int res = stacks[maxCnt].top();
    stacks[maxCnt].pop();
    cnt[res]--;
    if (stacks[maxCnt].empty()) {
      stacks.erase(maxCnt);
      maxCnt--;
    }
    return res;
  }
private:
  unordered_map<int, int> cnt;
  int maxCnt;
  unordered_map<int, stack<int>> stacks;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */