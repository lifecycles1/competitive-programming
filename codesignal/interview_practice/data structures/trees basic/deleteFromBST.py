#
# Definition for binary tree:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None

# python solution 1

def solution(t, queries): 

  def remove (n , k ) : 
    if n : 
      if   n.value > k : n.left  = remove(n.left ,k)
      elif n.value < k : n.right = remove(n.right,k)
      else : ## == 
        if   not n.left  : return n.right
        # elif not n.right : return n.left 

        ### not a recursive remove to avoid straightening
        ##  which elif would have avoided...
        if n.left.right is None : 
          n.value = n.left.value
          n.left  = n.left.left
        else : 
          tmp = n.left
          while tmp.right.right : 
            tmp = tmp.right
          n.value = tmp.right.value
          tmp.right = tmp.right.left
      return n

  for q in queries : 
    t = remove(t,q) 
  return t

# python solution 2

def rightmost(t):
  if t.right == None:
    return t.left,t.value
  t.right,v = rightmost(t.right)
  return t,v

def delete(t, v):
  if t == None:
    return None
  
  if t.value > v:
    t.left = delete(t.left,v)
  elif t.value < v:
    t.right = delete(t.right,v)
  else:
    if t.left == None:
      t = t.right
    else:
      t.left,t.value = rightmost(t.left)
          
  return t

def solution(t, queries):
  for q in queries:
    t = delete(t, q)
  return t
        
# python solution 3

def solution(t, queries):
    
  def max_of_tree(t):
    if t is None: return(None)
    while t.right is not None:
      t = t.right
    return(t.value)

  def remove_right(t):
    if t.right is None:
      return(t.left)
    else:
      t.right = remove_right(t.right)
    return(t)

  def f1(t, q):
    if t is None: return(None)
    if q == t.value:
      if t.left:
        t.value = max_of_tree(t.left)
        t.left = remove_right(t.left)
      else:
        t = t.right
    elif q < t.value:
      t.left = f1(t.left, q)
    elif q > t.value:
      t.right = f1(t.right, q)
    return(t)

  for q in queries:
    t = f1(t, q)

  return(t)

# JavaScript solution 

# function solution(t, queries) {
#   const rightmost = (node) => (node.right ? rightmost(node.right) : node);
#   const noRightmost = (node) => {
#     if (!node.right) return node.left;
#     node.right = noRightmost(node.right);
#     return node;
#   };
#   const trim = (node, value) => {
#     if (node === null) return null;
#     if (node.value === value) {
#       if (node.left === null) return node.right;
#       let next = rightmost(node.left);
#       next.left = noRightmost(node.left);
#       next.right = node.right;
#       return next;
#     }
#     node.left = trim(node.left, value);
#     node.right = trim(node.right, value);
#     return node;
#   };

#   return queries.reduce((acc, query) => trim(acc, query), t);
# }


# JavaScript solution 2

# //
# // Definition for binary tree:
# // function Tree(x) {
# //   this.value = x;
# //   this.left = null;
# //   this.right = null;
# // }
# function solution(t, queries) {
#     for (let i = 0; i < queries.length; i++) {
#         t = deleteNode(t, queries[i]);
#     }
#     return t;
# }

# function deleteNode(t, node) {
#     if (t == null) return null;
#     if (t.value == node) {
#         if (t.left == null && t.right == null) t = null;
#         else if (t.left == null) {
#             t = t.right;
#         } else {
#             let x = max(t.left);
#             x.left = deleteMax(t.left);
#             x.right = t.right;
#             return x;
#         }
#     } else {
#         t.left = deleteNode(t.left, node);
#         t.right = deleteNode(t.right, node);
#     }
#     return t;
# }

# function deleteMax(x) {
#     if (x.right == null) return x.left;
#     x.right = deleteMax(x.right);
#     return x;
# }

# function max(x) {
#     while (x.right != null) x = x.right;
#     return x;
# }
