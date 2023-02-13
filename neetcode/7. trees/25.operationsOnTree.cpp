# include <vector>
# include <deque>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class LockingTree {
public:
  LockingTree(std::vector<int>& parent) {
    this->parent = parent;
    locked.resize(parent.size());
    child.resize(parent.size());
    for (int i = 1; i < parent.size(); i++) {
      child[parent[i]].push_back(i);
    }
  }

  bool lock(int num, int user) {
    if (locked[num]) return false;
    locked[num] = user;
    return true;
  }

  bool unlock(int num, int user) {
    if (locked[num] != user) return false;
    locked[num] = 0;
    return true;
  }

  bool upgrade(int num, int user) {
    int i = num;
    while (i != -1) {
      if (locked[i]) return false;
      i = parent[i];
    }

    int lockedCount = 0;
    std::deque<int> q;
    q.push_back(num);
    while (!q.empty()) {
      int n = q.front();
      q.pop_front();
      if (locked[n]) {
        locked[n] = 0;
        lockedCount++;
      }
      for (int c : child[n]) {
        q.push_back(c);
      }
    }

    if (lockedCount > 0) locked[num] = user;
    return lockedCount > 0;
  }
private:
  std::vector<int> parent;
  std::vector<int> locked;
  std::vector<std::vector<int>> child;
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */