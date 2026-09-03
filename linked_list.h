
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {

public:
  LinkedList() : head(NULL) {} 

  /**
   * @brief Destroy the Linked List object
   *  Deletes each node one by one until the list is empty, freeing the memory allocated for each node.
   */
  ~LinkedList(){
  ListNode* current = head;
    while (current != NULL) {
    ListNode* nextNode = current->next;
    delete current;
    current = nextNode;
    }
  }

  /**
   * @brief Adds a new node with the specified data to the front of the list.
   * 
   * @param data The data to be added to the list.
   */
  void push_front(const T data){
    ListNode* newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
  }

  /**
   * @brief Removes the node at the front of the list, if it exists.
   * 
   */
  void pop_front(){
    if (head != NULL) {
      ListNode* temp = head;
      head = head->next;
      delete temp;
    }
  }
  
  /**
   * @brief Reverses the order of the nodes in the linked list without using any additional data structures.
   */
  void reverse(){
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next = NULL;

    /**
     * If the list is empty or has only one node, no action is needed. The loop will not execute in these cases, and the head will remain unchanged.
     * 
     * In the standard case, the loop iterates through the list, reversing the direction of the links between nodes. 
     * After the loop, the head pointer is updated to point to the new front of the list (the last node processed).
     */
    while (current != NULL) {
      next = current->next; // Store the next node
      current->next = prev; // Reverse the link
      prev = current;       // Move prev to current
      current = next;       // Move to the next node
    }
    head = prev; // Update head to the new front of the list
  }

  /**
   * @brief Print each node's data in the list, separated by a space. If the list is empty, prints "Empty\n".
   */
  void print() const{
    
    ListNode* current = head;
    if (current == NULL) {
      cout << "Empty" << endl;
      return;
    }

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
