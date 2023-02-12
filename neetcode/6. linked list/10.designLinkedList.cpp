// Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
// A node in a singly linked list should have two attributes: val and next. val is the value 
// of the current node, and next is a pointer/reference to the next node.
// If you want to use the doubly linked list, you will need one more attribute prev to indicate the 
// previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

// Implement the MyLinkedList class:

// MyLinkedList() Initializes the MyLinkedList object.
// int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, 
// return -1.
// void addAtHead(int val) Add a node of value val before the first element of the linked list. 
// After the insertion, the new node will be the first node of the linked list.
// void addAtTail(int val) Append a node of value val as the last element of the linked list.
// void addAtIndex(int index, int val) Add a node of value val before the indexth node in the 
// linked list. If index equals the length of the linked list, the node will be appended to the 
// end of the linked list. If index is greater than the length, the node will not be inserted.
// void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

#include <limits.h>

class Node {
  public:
    int val;
    Node* next;
    // Constructor of Node
    Node(int x): val(x), next(nullptr) {}
	// Above code is equivalent to the below code
	// Node(int x) { val=x; next=nullptr;}
};

class MyLinkedList {
public:
    Node* head;
    int size;
    // Constructor
    MyLinkedList(): head(nullptr), size(0) {}
	// Above code is equivalent to the below code
	// MyLinkedList() { head=nullptr; size=0;}
	
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        // Return -1 for invalid index
        if(index>=size || index < 0) {
            return -1;
        }
        Node* current=head;
        for(int i=0;i<index;++i) {
            current= current->next;
        }
        return current->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        addAtIndex(size, val);       
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        // Return if invalid index
        if (index>size || index < 0) {
            return;
        }
        Node* current= head;
        Node* new_node = new Node(val);
        // index == 0 implies insert at head
        // Considered separately as we need to update head
        if (index == 0) {
            new_node->next = current;
            // Update head
            head = new_node;
        }
        else {
            // Run loop till index-1 as we need to insert node at index
            for(int i=0;i<index-1;++i) {
                current= current->next;
            }
            /* 
                current --> current->next
                            /
                        new_node
                        
                current    current->next
                      \      /
                        new_node           
            
            */            
            new_node->next = current->next;
            current->next = new_node;
        }
        // Increase size whenever we insert node
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        // Return if invalid index
        if(index>=size || index < 0) {
            return;
        }
        // index==0 implies delete at head
        // Considered separately as we need to update head
        if (index == 0) {
            Node* nextNode = head->next;
            // Always remember to free memory to prevent memory leak
            delete head;
            head = nextNode;            
        }
        else {
            Node* current= head;
            // Run loop till index-1 as we need to insert node at index
            for(int i=0;i<index-1;++i) {
                current= current->next;
            }
            /* 
                current --> current->next --> current->next->next
                                                (next_node)
                        
                current --> DELETED --> current->next->next
                
                current --> next_node
            
            */  
            Node* nextNode = current->next->next;
            // Always remember to free memory to prevent memory leak
            delete current->next;
            current->next = nextNode;
        }
        // Decrease size whenever we delete node
            size--;
    }
    /*
        Default destructor only deletes head and size (allocated by constructor)
        We need destructor to free the memory used by all individual nodes
    */
    // Destructor
    ~MyLinkedList()
    {
        Node *p = head;
        // Delete node at head while head is not null
        while (head!=nullptr)
        {
            head= head->next;
            delete p;
            p=head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

////////////////////////////////////////////////////////////////////////////
////////////// version 2////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val=val;
        next=NULL;
    }
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    int size=0;
    Node* head=new Node(0);
    MyLinkedList() {

    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index>=size) return -1;
        Node* temp=head->next;
        for(int i=0;i<index;i++) temp=temp->next;
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* temp=head->next;
        head->next=new Node(val);
        head->next->next=temp;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* temp=head;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new Node(val);
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>size) return;
        Node* temp=head;
        for(int i=0;i<index;i++) temp=temp->next;
        Node* temp1=temp->next;
        temp->next=new Node(val);
        temp->next->next=temp1;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=size) return;
        Node* temp=head;
        for(int i=0;i<index;i++) temp=temp->next;
        Node* temp1=temp->next;
        temp->next=temp1->next;
        temp1->next=NULL;
        size--;
        delete temp1;
    }
};