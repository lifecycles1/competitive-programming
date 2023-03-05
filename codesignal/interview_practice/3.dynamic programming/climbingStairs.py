

def solution(n):
  # Create an array to store the number of ways to reach each step
  # creates a new list num_ways of length n+1 with all elements initialized to 0. 
  # It does not multiply the list [0] by n+1.
  # For example, if n is 3, this line of code creates the following list: num_ways = [0, 0, 0, 0].
  num_ways = [0] * (n + 1)
  
  # Set the base cases
  # The base cases num_ways[0] = 1 and num_ways[1] = 1 are then used to initialize the first two elements 
  # of the num_ways list. The rest of the elements in the list are then calculated in the loop using the 
  # values of the previous elements.
  num_ways[0] = 1
  num_ways[1] = 1
  
  # Calculate the number of ways to reach each step starting from the base cases
  for i in range(2, n+1):
    num_ways[i] = num_ways[i-1] + num_ways[i-2]
  
  # Return the number of ways to reach the top of the staircase
  return num_ways[n]