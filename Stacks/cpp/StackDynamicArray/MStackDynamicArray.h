#ifndef __MSTACKDYNAMICARRAY_H__
#define __MSTACKDYNAMICARRAY_H__
#include <stdio.h>
#include <climits>

#define DEFAULT_MSTACK_SIZE 16

template <class SomeType>
class MStackDynamicArray {
  private:
    int stackSize;
    int maxStackSize;
    SomeType *start;

  public:
    MStackDynamicArray();
    MStackDynamicArray(int);    // Initialize a maximum size for the stack.
    ~MStackDynamicArray();
    bool isEmpty();
    SomeType& pop();
    void push(const SomeType &A);
    int size();
    SomeType top();
};

template <class SomeType>
MStackDynamicArray<SomeType>::MStackDynamicArray() {
  stackSize = 0;
  maxStackSize = DEFAULT_MSTACK_SIZE;
  start = new SomeType[DEFAULT_MSTACK_SIZE];
}

// Allow initialization with a specified max stack size.
template <class SomeType>
MStackDynamicArray<SomeType>::MStackDynamicArray(int maxStackSize) {
  stackSize = 0;
  this->maxStackSize = maxStackSize;
  start = new SomeType[maxStackSize];
}

template <class SomeType>
MStackDynamicArray<SomeType>::~MStackDynamicArray() {
  // Avoid memory leaks! Delete the array pointed to by start.
  delete[] start;
}

template <class SomeType>
bool MStackDynamicArray<SomeType>::isEmpty() {
  return (stackSize == 0 ? true : false);
}

template <class SomeType>
SomeType& MStackDynamicArray<SomeType>::pop() {
  if (stackSize > 0) {
    stackSize--;
    // Shrink the array by 1/2 if a pop() causes it to be <= 1/4 full.
    if (stackSize <= maxStackSize / 4) {
      // Create a new (smaller) array, copy the items over, then delete the
      // larger old one.
      SomeType *newStart = new SomeType[maxStackSize / 2];
      // Loop until stackSize + 1, as we already decremented stackSize.
      for (int i = 0; i < stackSize + 1; i++) {
        newStart[i] = start[i];
      }
      delete[] start;  // Delete the old array.
      start = newStart;  // Make start point to the new array.
    }
    return start[stackSize];
  }
  else {
    throw "Stack is empty!";
  }
}

template <class SomeType>
SomeType MStackDynamicArray<SomeType>::top() {
  return (stackSize > 0 ? start[(int) stackSize - 1] : NULL);
}

template <class SomeType>
void MStackDynamicArray<SomeType>::push(const SomeType &A) {
  if (stackSize == maxStackSize) {
    // We'll set the limit at (2^31)-1 items.
    if ( (maxStackSize*2) > LONG_MAX ) {
      printf("Stack size limit exceeded\n");
      throw "Stack size limit exceeded";
    }
    else {
      // Double the size of the array.
      maxStackSize *= 2;
      // If not enough memory, "new" will throw an exception.
      SomeType *newStart = new SomeType[maxStackSize];
      // Copy old array contents to new array.
      for (int i = 0; i < stackSize; i++) {
        newStart[i] = start[i];
      }
      delete[] start;  // Delete the old array.
      start = newStart;  // Make start point to the new array.
    }
  }

  start[stackSize] = A;
  stackSize++;
}

template <class SomeType>
int MStackDynamicArray<SomeType>::size() {
  return stackSize;
}

#endif
