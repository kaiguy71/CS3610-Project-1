
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {

public:
  LinkedList() : head(NULL) {} 

  ~LinkedList(){
  ListNode* current = head;
    while (current != NULL) {
    ListNode* nextNode = current->next;
    delete current;
    current = nextNode;
    }
  }

  void push_front(const T data){
    ListNode* newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
  }

  void pop_front(){
    if (head != NULL) {
      ListNode* temp = head;
      head = head->next;
      delete temp;
    }
  }
  
  void reverse(){
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next = NULL;

    while (current != NULL) {
      next = current->next; // Store the next node
      current->next = prev; // Reverse the link
      prev = current;       // Move prev to current
      current = next;       // Move to the next node
    }
    head = prev; // Update head to the new front of the list
  }

  void print() const{
    
    ListNode* current = head;
    while (current != NULL) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }

private:
  
  struct ListNode {
    ListNode(const T data) : data(data), next(NULL) {}
    
    T data;
    ListNode* next;
  };

  ListNode* head;
};
