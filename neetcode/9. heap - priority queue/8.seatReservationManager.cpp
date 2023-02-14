// Design a system that manages the reservation state of n seats that are numbered from 1 to n.

// Implement the SeatManager class:

// SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. 
// All seats are initially available.
// int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.
// void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.

# include < queue >

class SeatManager {
public:
  SeatManager(int n) {
    for (int i = 1; i <= n; i++) {
      minHeap.push(i);
    }
  }
  
  int reserve() {
    int seat = minHeap.top();
    minHeap.pop();
    return seat;
  }
  
  void unreserve(int seatNumber) {
    minHeap.push(seatNumber);
  }
private:
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
};