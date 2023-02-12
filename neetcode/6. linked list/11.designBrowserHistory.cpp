// You have a browser of one tab where you start on the homepage and you can visit another url, 
// get back in the history number of steps or move forward in the history number of steps.

// Implement the BrowserHistory class:

// BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
// void visit(string url) Visits url from the current page. It clears up all the forward history.
// string back(int steps) Move steps back in history. If you can only return x steps in the history 
// and steps > x, you will return only x steps. Return the current url after moving back in history 
// at most steps.
// string forward(int steps) Move steps forward in history. If you can only forward x steps in the 
// history and steps > x, you will forward only x steps. Return the current url after forwarding 
// in history at most steps.

#include <string>
#include <stack>
using namespace std;

// solution using 2 stacks
class BrowserHistory {
public:
  stack<string> history;
  stack<string> future;
  
  BrowserHistory(string homepage) {
    history.push(homepage);
    future = stack<string>(); //resets stack
  }
  
  void visit(string url) {
    history.push(url);
    future = stack<string>();
  }
  
  string back(int steps) {
    while(steps>0 && history.size() > 1){
      future.push(history.top());
      history.pop();
      steps--;
    }
    return history.top();
  }
  
  string forward(int steps) {
    while(steps>0 && future.size()>0){
      history.push(future.top());
      future.pop();
      steps--;
    }
    return history.top();
  }
};

// solution using doubly linked list (more efficient)
class BrowserHistory {
public:
  class Node{
    public:
    string url;
    Node* next;
    Node* prev;
    
    Node(string url){
      this->url =url;
      next = NULL;
      prev = NULL;
    }
  };
  Node* curr;
  BrowserHistory(string homepage) {
    curr = new Node(homepage);
  }
  
  void visit(string url) {
    Node* temp = new Node(url);
    curr->next = temp;
    temp->prev = curr;
    curr = curr->next;
  }
  
  string back(int steps) {
    while(curr->prev!=nullptr && steps-- >0){
      curr = curr->prev;
    }
    return curr->url;
  }
  
  string forward(int steps) {
    while(curr->next!=nullptr && steps-- >0){
      curr = curr->next;
    }
    return curr->url;
  }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */