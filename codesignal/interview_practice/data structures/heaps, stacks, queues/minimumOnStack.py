# Implement a modified stack that, in addition to using push and pop operations, allows you to find the 
# current minimum element in the stack by using a min operation.

# Example

# For operations = ["push 10", "min", "push 5", "min", "push 8", "min", "pop", "min", "pop", "min"], the 
# output should be
# solution(operations) = [10, 5, 5, 5, 10].

# The operations array contains 5 instances of the min operation. The results array contains 5 numbers, 
# each representing the minimum element in the stack at the moment when min was called



# Python solution

class ModifiedStack():
    def __init__(self):
        self.stack = []
        self.min_id = -1

    def push(self, val):
        self.stack.append((val, self.min_id))
        if self.min_id == -1 or val < self.stack[self.min_id][0]:
            self.min_id = len(self.stack) - 1

    def pop(self):
        self.min_id = self.stack.pop()[1]

    def min(self):
        return self.stack[self.min_id][0]

def solution(operations):
    stack = ModifiedStack()
    ans = []
    for op in operations:
        if op.startswith("push"):
            stack.push(int(op[5:]))
        elif op == "pop":
            stack.pop()
        elif op == "min":
            ans.append(stack.min())
    return ans


# JavaScript solution 


# class Stack {
#   constructor() {
#       this.arr = []
#       this._min = []
#   }
  
#   push(n) {
#       console.log('pushing!', n)
#       this.arr.push(n) 
#       if ( this._min.length < 1 || this.min >= n ) {
#           this._min.push(n)
#       }
#   }
  
#   pop(n) {
#       const last = this.arr.pop()
#       if ( last === this.min ) {
#           this._min.pop()
#       }
#   }
  
#   get min() {
#       return this._min[this._min.length-1]
#   }
# }

# function solution(operations) {
#   const mins = []
#   const stack = new Stack()

#   for ( const op of operations ) {
#       const parts = op.split(" ")
      
#       switch (parts[0]) {
#       case "min":
#           mins.push(stack.min)
#           break
#       case "push":
#           stack.push( parseInt(parts[1]) )
#           break
#       case "pop":
#           stack.pop()
#           break
#       }

#   }
  
#   return mins
# }
