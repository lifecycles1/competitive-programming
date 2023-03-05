# Given a sequence of numbers in an array, find the length of its longest increasing subsequence (LIS).
# The longest increasing subsequence is a subsequence of a given sequence in which the subsequence's 
# elements are in strictly increasing order, and in which the subsequence is as long as possible. 
# This subsequence is not necessarily contiguous or unique.

# Example

# For sequence = [1, 231, 2, 4, 89, 32, 12, 234, 33, 90, 34, 100], the output should be
# solution(sequence) = 7.

# The LIS itself is [1, 2, 4, 32, 33, 34, 100].


# Python solution 1

# def solution(sequence):
#     n = len(sequence)
#     res = [0] * (n + 1)
#     for i in range(1, n + 1):
#         res[i] = 1
#         for j in range(1, i):
#             if sequence[j - 1] < sequence[i - 1]:
#                 res[i] = max(res[i], res[j] + 1)
#     return max(res)


# Python solution 2
    
def solution(sequence):
    c = []
    for i in range(len(sequence)):
        best = 1
        for j in range(i):
            if sequence[j] < sequence[i] and c[j] >= best:
                best = c[j] + 1
        c.append(best)
    return max(c)