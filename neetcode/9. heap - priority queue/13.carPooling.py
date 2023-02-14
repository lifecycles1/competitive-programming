# There is a car with capacity empty seats. The vehicle only drives east 
# (i.e., it cannot turn around and drive west).

# You are given the integer capacity and an array trips where 
# trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers 
# and the locations to pick them up and drop them off are fromi and toi respectively. 
# The locations are given as the number of kilometers due east from the car's initial location.

# Return true if it is possible to pick up and drop off all passengers for all the given trips, or 
# false otherwise.

from typing import List
import heapq

# normal regular solution
class Solution:
  def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
    trips.sort(key = lambda t: t[1])

    minHeap = [] # pair of [end, numPassengers]
    curPass = 0
    for t in trips:
      numPass, start, end = t
      while minHeap and minHeap[0][0] <= start:
        curPass -= minHeap[0][1]
        heapq.heappop(minHeap)
      
      curPass += numPass
      if curPass > capacity:
        return False
      heapq.heappush(minHeap, [end, numPass])
    return True

# because 0 <= from[i] < to[i] <= 1000 we can brute force this solution
class Solution:
  def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
    passChange = [0] * 1001

    for t in trips:
      numPass, start, end = t
      passChange[start] += numPass
      passChange[end] -= numPass
    
    curPass = 0
    for i in range(1001):
      curPass += passChange[i]
      if curPass > capacity:
        return False
    return True