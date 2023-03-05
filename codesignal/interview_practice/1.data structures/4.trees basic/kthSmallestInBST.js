//
// Definition for binary tree:
// function Tree(x) {
//   this.value = x;
//   this.left = null;
//   this.right = null;
// }
function solution(t, k) {
  let count = 0;
  let result;

  // in-order traversal (left-root-right)
  const inOrder = (tree) => {
    if (tree.left) inOrder(tree.left);
    count++;
    if (count === k) result = tree.value;
    if (tree.right) inOrder(tree.right);
  };
  inOrder(t);
  return result;
}

// function solution(t, k) {
//   let dfs = t => {
//     let val = null;
//     if (t.left) val = dfs(t.left);
//     if (val) return val;
//     k--;
//     if (k === 0) return t.value;
//     if (t.right) val = dfs(t.right);
//     return val;
//   }
//   return dfs(t);
// }

// Python solution

// def solution(t, k):
//   count = 0
//   result = 0

//   def inOrder(tree):
//     nonlocal count
//     nonlocal result
//     if tree.left: inOrder(tree.left)
//     count = count + 1
//     if count == k: result = tree.value
//     if tree.right: inOrder(tree.right)

//   inOrder(t)
//   return result
