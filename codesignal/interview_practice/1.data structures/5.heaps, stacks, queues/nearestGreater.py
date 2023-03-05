# Given an array of integers a, return a new array b using the following guidelines:

# For each index i in b, the value of bi is the index of the aj nearest to ai and is also greater than ai.
# If there are two options for bi, put the leftmost one in bi.
# If there are no options for bi, put -1 in bi.

# Python solution

def prevGreater(a):
    """
    The complexity of this solution is (though not obvious) O(n), because
    the inner loop won't pass a same index `j` more than once.

    Actually, the principle is the same as solutions using stack, whose
    complexity is more obvious.
    """
    prev = list(range(-1, len(a)-1))
    for i in range(1, len(a)):
        j = prev[i]
        while j != -1 and a[j] <= a[i]:
            j = prev[j]
        prev[i] = j
    return prev

def nextGreater(a):
    ans = prevGreater(a[::-1])[::-1]
    for i in range(len(ans)):
        if ans[i] >= 0: ans[i] = len(a) - 1 - ans[i]
    return ans

def solution(a):
    pre = prevGreater(a)
    nxt = nextGreater(a)
    ans = []
    for i in range(len(a)):
        if pre[i] == -1 or nxt[i] == -1:
            ans.append(pre[i] + nxt[i] + 1)
        elif i - pre[i] <= nxt[i] - i:
            ans.append(pre[i])
        else:
            ans.append(nxt[i])
    return ans



# JavaScript solution

# function solution (a) {
#   return a.map((v, i) => {
#     let i1 = i - 1
#     let i2 = i + 1
#     while(i1 >= 0 || i2 < a.length) {
#       if (i1 >= 0 && a[i1] > v) return i1
#       if (i2 < a.length && a[i2] > v) return i2
#       i1--
#       i2++
#     }
#     return -1
#   })
# }