// The median is the middle value in an ordered integer list. If the size of the list is even, there is no 
// middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer 
// will be accepted.

// Implement data structure that gets the median from a data stream
// Max heap of lower values & min heap of higher values, access to mids
// Time: O(log n) + O(1)
// Space: O(n)

#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
public:
  MedianFinder() {}

  void addNum(int num) {
    if (lower.empty()) {
      lower.push(num);
      return;
    }
    if (lower.size() > higher.size()) {
      if (lower.top() > num) {
        higher.push(lower.top());
        lower.pop();
        lower.push(num);
      } else {
        higher.push(num);
      }
    } else {
      if (num > higher.top()) {
        lower.push(higher.top());
        higher.pop();
        higher.push(num);
      } else {
        lower.push(num);
      }
    }
  }

  double findMedian() {
    double result = 0.0;

    if (lower.size() == higher.size()) {
      result = lower.top() + (higher.top() - lower.top()) / 2.0;
    } else {
      if (lower.size() > higher.size()) {
        result = lower.top();
      } else {
        result = higher.top();
      }
    }
    return result;
  }

private:
  priority_queue<int> lower;
  priority_queue<int, vector<int>, greater<int>> higher;
};



/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */