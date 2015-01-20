#ifndef __MSTACK_H__
#define __MSTACK_H__
#include <cstddef>

#define DEFAULT_MSTACK_SIZE 16

template <class Type>
class MStackLinkedList {
  protected:
    // internal struct used for the linked list
    typedef struct Node {
      struct Node *next;
      Type data;
    } Node;
    // used to keep track of the topItem of the stack/list
    Node *topItem;

  public:
    MStackLinkedList();       // create and initialize your stack
    ~MStackLinkedList();      // destroy ALL the things
    bool isEmpty(); // tells whether or not the stack is empty
    // top() exists because pop() can't both delete the element and return
    // a reference to the element's value
    Type& top();    // returns the top element of the stack
    void pop();     // pops the top element off of the stack and deletes it
    void push(const Type &A);   // pushes a copy of the element to the stack
};

template <class Type>
MStackLinkedList<Type>::MStackLinkedList() {
  topItem = NULL;     // when topItem is NULL, the stack is empty
}

template <class Type>
MStackLinkedList<Type>::~MStackLinkedList() {
  Node* holder;
  // delete every item in the stack
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

  /* Debug
     std::cout << "\nTop->next's address is: " << topItem->next << std::endl;
     std::cout << "Popping topItem with address: " << topItem;
     std::cout << " and data address: "<< &(topItem->data);
     std::cout<< " which should have value: ";
     fflush(stdout);
     std::cout << topItem->data << std::endl;
     */

  // otherwise, pop the topItem of the list and set the topItem pointer
  // equal to the next element in the list
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
  /* Debug
     std::cout << "topItem address is now: " << topItem << std::endl;
     std::cout << "topItem data is now: \"" << (topItem->data) << "\" with address " << &(topItem->data) << std::endl;
     */
}

#endif
// Driver  *******************************************************************
/*
#include <iostream>
#include <string>
#include <string.h>
#include "MStackLinkedList.h"

using namespace std;

class NumberClass {
public:
int i;
NumberClass(int x) {
i = x;
}
// "friend" - allow the output stream to read private & protected members
friend ostream& operator<<(ostream& os, const NumberClass& nc);
};

ostream& operator<<(ostream& os, const NumberClass& nc) {
os << nc.i;
return os;
}

int main()
{
//  MStackLinkedList<const char*> myStack;

MStackLinkedList<string> myStack;
myStack.push("I");
myStack.push("am");
myStack.push("on");
myStack.push("the");
myStack.push("stack");

//  MStackLinkedList<string> myStack;
//  string I = "I";
//  string am = "am";
//  myStack.push(I);
//  myStack.push(am);
//
//  MStackLinkedList<int> myStack;
//  myStack.push(1);
//  myStack.push(2);
//  myStack.push(3);
//
//  MStackLinkedList<NumberClass> myStack;
//  myStack.push(NumberClass(1));
//  myStack.push(NumberClass(2));

while (!myStack.isEmpty()) {
cout << "From main(): " << myStack.top() << "\n";
myStack.pop();
}

cout << "\nPress any key to exit.";
cout << endl;

cin.get();

return 0;
}
*/
