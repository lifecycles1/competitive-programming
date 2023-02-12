def solution(t1, t2):
    # base case: if t2 is empty, it is always a subtree of t1
    if t2 is None:
        return True
    # base case: if t1 is empty, t2 cannot be a subtree of t1
    if t1 is None:
        return False

    # check if the subtree rooted at t1 is identical to t2
    if (t1.value == t2.value) and isIdentical(t1, t2):
        return True

    # if the subtree rooted at t1 is not identical to t2, check if t2 is a
    # subtree of either the left or right subtree of t1
    return solution(t1.left, t2) or solution(t1.right, t2)

def isIdentical(t1, t2):
    # base case: if both trees are empty, they are identical
    if t1 is None and t2 is None:
        return True
    # base case: if one tree is empty and the other is not, they are not identical
    if t1 is None or t2 is None:
        return False
    # if the values of the nodes are not the same, the trees are not identical
    if t1.value != t2.value:
        return False
    # if the values of the nodes are the same, check the subtrees recursively
    return isIdentical(t1.left, t2.left) and isIdentical(t1.right, t2.right)


# JavaScript solution 1

# function solution(t1, t2) {
#     if (!t2) return true;
#     if (!t1) return false;
#     if (t1.val === t2.val && isSameTree(t1, t2)) return true;
#     return solution(t1.left, t2) || solution(t1.right, t2);
# }

# function isSameTree(t1, t2) {
#     if (!t1 && !t2) return true;
#     if (!t1 || !t2) return false;
#     if (t1.val !== t2.val) return false;
#     return isSameTree(t1.left, t2.left) && isSameTree(t1.right, t2.right);
# }


# JavaScript solution 2

# function solution(t1, t2) {
#     return JSON.stringify(t1).indexOf(JSON.stringify(t2)) !== -1
# }