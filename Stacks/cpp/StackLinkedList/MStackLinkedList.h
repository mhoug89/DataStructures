#ifndef __MSTACK_H__
#define __MSTACK_H__
#include <cstddef>

template <class Type>
class MStackLinkedList {
  public:
    // Constructor/destructor
    MStackLinkedList();       // Create and initialize your stack.
    ~MStackLinkedList();      // Destroy ALL the things.
    // Methods
    bool IsEmpty(); // Tells whether or not the stack is empty.
    // Top() exists because Pop() can't both delete the element and return
    // a reference to the element's value.
    Type& Top();    // Returns the top element of the stack.
    void Pop();     // Pops the top element off of the stack and deletes it.
    void Push(const Type &A);   // Pushes a copy of the element to the stack.

  private:
    // Internal struct used for the linked list.
    typedef struct Node {
      struct Node *next;
      Type data;
    } Node;
    // Used to keep track of the top_item_ of the stack/list.
    Node *top_item_;
};

template <class Type>
MStackLinkedList<Type>::MStackLinkedList() : top_item_(NULL) { }

template <class Type>
MStackLinkedList<Type>::~MStackLinkedList() {
  Node* holder;
  // Delete every item in the stack.
  while (top_item_) {
    holder = top_item_->next;
    delete top_item_;
    top_item_ = holder;
  }
}

template <class Type>
bool MStackLinkedList<Type>::IsEmpty() {
  return !top_item_;
}

template <class Type>
Type& MStackLinkedList<Type>::Top() {
  if (!top_item_) {
    throw "StackEmptyException";
  }

  // Otherwise, pop the top_item_ of the list and set the top_item_ pointer
  // equal to the next element in the list.
  return top_item_->data;
}

template <class Type>
void MStackLinkedList<Type>::Pop() {
  Node* oldTop = top_item_;
  top_item_ = top_item_->next;
  delete oldTop;
}

template <class Type>
void MStackLinkedList<Type>::Push(const Type &A) {
  Node* new_top = new Node();
  new_top->data = A;
  new_top->next = top_item_;
  top_item_ = new_top;
}

#endif
