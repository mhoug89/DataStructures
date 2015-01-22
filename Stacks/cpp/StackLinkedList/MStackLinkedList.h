#ifndef __MSTACK_H__
#define __MSTACK_H__
#include <cstddef>

#define DEFAULT_MSTACK_SIZE 16

template <class Type>
class MStackLinkedList {
  protected:
    // Internal struct used for the linked list.
    typedef struct Node {
      struct Node *next;
      Type data;
    } Node;
    // Used to keep track of the topItem of the stack/list.
    Node *topItem;

  public:
    MStackLinkedList();       // Create and initialize your stack.
    ~MStackLinkedList();      // Destroy ALL the things.
    bool isEmpty(); // Tells whether or not the stack is empty.
    // top() exists because pop() can't both delete the element and return
    // a reference to the element's value.
    Type& top();    // Returns the top element of the stack.
    void pop();     // Pops the top element off of the stack and deletes it.
    void push(const Type &A);   // Pushes a copy of the element to the stack.
};

template <class Type>
MStackLinkedList<Type>::MStackLinkedList() {
  topItem = NULL;     // When topItem is NULL, the stack is empty.
}

template <class Type>
MStackLinkedList<Type>::~MStackLinkedList() {
  Node* holder;
  // Delete every item in the stack.
  while (topItem) {
    holder = topItem->next;
    delete topItem;
    topItem = holder;
  }
}

template <class Type>
bool MStackLinkedList<Type>::isEmpty() {
  return !topItem;
}

template <class Type>
Type& MStackLinkedList<Type>::top() {
  if (!topItem) {
    throw "StackEmptyException";
  }

  // Otherwise, pop the topItem of the list and set the topItem pointer
  // equal to the next element in the list.
  return topItem->data;
}

template <class Type>
void MStackLinkedList<Type>::pop() {
  Node* oldTop = topItem;
  topItem = topItem->next;
  delete oldTop;
}

template <class Type>
void MStackLinkedList<Type>::push(const Type &A) {
  Node* newTop = new Node();
  newTop->data = A;
  newTop->next = topItem;
  topItem = newTop;
}

#endif
