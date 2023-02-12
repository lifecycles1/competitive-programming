# Given an array a composed of distinct elements, find the next larger element for each element of the 
# array, i.e. the first element to the right that is greater than this element, in the order in which 
# they appear in the array, and return the results as a new array of the same length. If an element does 
# not have a larger element to its right, put -1 in the appropriate cell of the result array.

# Example

# For a = [6, 7, 3, 8], the output should be
# solution(a) = [7, 8, 8, -1].

# In this array, the next larger element for 6 is 7, for 7 is 8, for 3 is 8 (7 is not a valid option since 
# elements from a can only be compared to elements to their right), and for 8 there is no such element, 
# so we put -1 in the last cell.


# JavaScript solution 1

# class Node {
#     constructor(value) {
#         this.value = value;
#         this.next = null;
#     }
# }

# class Stack {
#     constructor() {
#         this.root = null;
#     }

#     push(node) {
#         node.next = this.root;
#         this.root = node;
#     }

#     pop() {
#         let result = this.root;
#         this.root = this.root.next;
#         return result;
#     }

#     peek() {
#         return this.root;
#     }

#     isEmpty() {
#         return this.root === null;
#     }
# }

# function solution(arr) {
#     let result = new Array(arr.length);
#     let stack = new Stack();
#     for (let i = 0; i < arr.length; i++) {
#         while (!stack.isEmpty() && arr[i] > arr[stack.peek().value]) {
#             result[stack.pop().value] = arr[i];
#         }
#         stack.push(new Node(i));
#     }
#     while (!stack.isEmpty()) {
#         result[stack.pop().value] = -1;
#     }
#     return result;
# }



# JavaScript solution 2 (the same as above function solution excluding the fancy way of creating a stack)
# this uses a regular array instead of a stack class and is pretty much the same


# function solution(a) {
#     // O(2n) solution, using stack
#     var stack = [],
#         i, n;
    
#     for (i = 0; i < a.length; i++) {
#         n = a[i];
#         // check which previous item less then current element
#         while (stack.length && n > a[ stack[ stack.length - 1 ] ]) {
#             a[ stack.pop() ] = n;
#         }
#         // put current item to the stack
#         stack.push(i);
#     }
#     while (stack.length) a[ stack.pop() ] = -1;
#     return a;
# }



# Python solution

def solution(A):
    stack = []
    ans = []
    for x in A[::-1]:
        while stack and x > stack[-1]:
            stack.pop()
        ans.append(stack[-1] if stack else -1)
        stack.append(x)
    return ans[::-1]


# Python solution 2

def solution(A):
    stack = []
    ans = [None] * len(A)
    for i, x in enumerate(A):
        while stack and stack[-1][1] < x:
            si, sx = stack.pop()
            ans[si] = x
        stack.append((i, x))
    for si, sx in stack:
        ans[si] = -1
    return ans