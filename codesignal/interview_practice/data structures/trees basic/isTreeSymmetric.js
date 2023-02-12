// Given a binary tree t, determine whether it is symmetric around its center, i.e. each side mirrors the other.

//
// Definition for binary tree:
// function Tree(x) {
//   this.value = x;
//   this.left = null;
//   this.right = null;
// }

function check(t1, t2) {
  if (t1 == null && t2 == null) {
    return true;
  }
  if (t1 == null || t2 == null || t1.value != t2.value) {
    return false;
  }
  return check(t1.left, t2.right) && check(t1.right, t2.left);
}

function solution(t) {
  return check(t, t);
}

// JavaScript solution 2

//
// Binary trees are already defined with this interface:
// function Tree(x) {
//   this.value = x;
//   this.left = null;
//   this.right = null;
// }
function solution(t) {
  return new SymmetricTree().isSymmetric(t);
}

class SymmetricTree {
  isSymmetric(root) {
    if (!root) return true;
    return this.checkSymmetry(root.left, root.right);
  }
  checkSymmetry(left, right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    return left.value == right.value && this.checkSymmetry(left.left, right.right) && this.checkSymmetry(left.right, right.left);
  }
}
