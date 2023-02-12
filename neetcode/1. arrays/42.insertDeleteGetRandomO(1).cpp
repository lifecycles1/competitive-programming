// Implement the RandomizedSet class:

// RandomizedSet() Initializes the RandomizedSet object.
// bool insert(int val) Inserts an item val into the set if not present. Returns true if the item 
// was not present, false otherwise.
// bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, 
// false otherwise.
// int getRandom() Returns a random element from the current set of elements (it's guaranteed that at 
// least one element exists when this method is called). Each element must have the same probability 
// of being returned.
// You must implement the functions of the class such that each function works in average O(1) time 
// complexity.

# include < string >
# include < vector >
# include <unordered_map>
using namespace std;

class RandomizedSet {
public:
  RandomizedSet() {};

  bool insert(int val) {
    if (indices.find(val) == indices.end()) {
      values.emplace_back(val);
      // store the index of that value
      indices[val] = values.size() - 1;
      return true;
    }
    return false;
  }

  bool remove(int val) {
    if (indices.find(val) == indices.end()) {
      return false;
    }
    int last = values.back();
    indices[last] = indices[val];
    values[indices[val]] = last;
    values.pop_back();
    // also erase it from the hash map
    indices.erase(val);
    return true;
  }

  int getRandom() {
    return values[rand() % values.size()];
  }
private:
  vector<int> values;
  unordered_map<int, int> indices;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */