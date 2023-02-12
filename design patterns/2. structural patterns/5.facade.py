# Python arrays are dynamic by default, but this is an example of resizing.
class Array:
  def __init__(self):
    self.capacity = 2
    self.length = 0
    self.arr = [0] * 2 # Array of capacity = 2
  
  # Insert n in the last position of the array
  def pushBack(self, n):
    if self.length == self.capacity:
      self.resize()
    
    # insert at next empty position
    self.arr[self.length] = n
    self.length += 1
  
  def resize(self):
    # create new array of double capacity
    self.capacity = 2 * self.capacity
    newArr = [0] * self.capacity

    # copy elements to new array
    for i in range(self.length):
      newArr[i] = self.arr[i]

    # set new array as the array
    self.arr = newArr

