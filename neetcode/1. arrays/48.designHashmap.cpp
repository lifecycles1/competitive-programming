// Design a HashMap without using any built-in hash table libraries.

// Implement the MyHashMap class:

// MyHashMap() initializes the object with an empty map.
// void put(int key, int value) inserts a (key, value) pair into the HashMap. 
// If the key already exists in the map, update the corresponding value.
// int get(int key) returns the value to which the specified key is mapped, 
// or -1 if this map contains no mapping for the key.
// void remove(key) removes the key and its corresponding value if the map contains 
// the mapping for the key.

#include <limits>
#include <vector>

struct Node {
public:
  int key, val;
  Node* next;
  Node(int k, int v, Node* n) {
    key = k;
    val = v;
    next = n;
  }
};

// class with Hash
class MyHashMap {
public:
  const static int size = 19997;
  const static int mult = 12582917;
  Node* data[size] = {};
  
  int hash(int key) {
    return (int)((long)key * mult  % size);
  }

  void put(int key, int val) {
    remove(key);
    int h = hash(key);
    Node* node = new Node(key, val, data[h]);
    data[h] = node;
  }

  int get(int key) {
    int h = hash(key);
    Node* node = data[h];
    for (; node != NULL; node = node->next) {
      if (node->key == key) {
        return node->val;
      }
    }
    return -1;
  }

  void remove(int key) {
    int h = hash(key);
    Node* node = data[h];
    if (node == NULL) return;
    if (node->key == key) {
      data[h] = node->next;
      delete node;
    } else for (; node->next != NULL; node = node->next) {
      if (node->next->key == key) {
        Node* temp = node->next;
        node->next = temp->next;
        delete temp;
        return;
      }
    }
  }
};

// class with vector
class MyHashMap {
public:
  int data[1000001];
  MyHashMap() {
    std::fill(data, data + 1000000, -1);
  }
  void put(int key, int val) {
    data[key] = val;
  }
  int get(int key) {
    return data[key];
  }
  void remove(int key) {
    data[key] = -1;
  }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */