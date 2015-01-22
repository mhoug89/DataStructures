#ifndef __MSTACKDYNAMICARRAY_H__
#define __MSTACKDYNAMICARRAY_H__
#include <stdio.h>
#include <climits>

#define DEFAULT_MSTACK_SIZE 16

template <class SomeType>
class MStackDynamicArray {
  public:
    // Constructors/Destructor
    MStackDynamicArray();
    MStackDynamicArray(int);    // Set an initial maximum size for the stack.
    ~MStackDynamicArray();
    // Methods
    bool IsEmpty();
    SomeType& Pop();
    void Push(const SomeType &A);
    int size();
    SomeType Top();

  private:
    // Methods
    void ResizeArray(int);
    // Data members
    int max_size_;  // Max capacity of the backing array.
    int size_;  // Number of items currently in the backing array.
    SomeType *start_;  // The backing array.
};

template <class SomeType>
MStackDynamicArray<SomeType>::MStackDynamicArray()
    : max_size_(DEFAULT_MSTACK_SIZE),
      size_(0) {
  start_ = new SomeType[DEFAULT_MSTACK_SIZE];
}

// Allow initialization with a specified max stack size.
template <class SomeType>
MStackDynamicArray<SomeType>::MStackDynamicArray(int max_size)
    : max_size_(max_size),
      size_(0) {
  start_ = new SomeType[max_size_];
}

template <class SomeType>
MStackDynamicArray<SomeType>::~MStackDynamicArray() {
  // Avoid memory leaks! Delete the array pointed to by start_.
  delete[] start_;
}

template <class SomeType>
bool MStackDynamicArray<SomeType>::IsEmpty() {
  return (size_ == 0 ? true : false);
}

template <class SomeType>
SomeType& MStackDynamicArray<SomeType>::Pop() {
  if (size_ > 0) {
    // Shrink the array by 1/2 if a Pop() causes it to be < 1/4 full.
    if (size_ - 1 < max_size_ / 4) {
      MStackDynamicArray<SomeType>::ResizeArray(max_size_ / 2);
    }
    return start_[--size_];
  }
  else {
    throw "Stack is empty!";
  }
}

// Create a new array of size new_size, copy all the items from the start_
// array into it, set max_size_ = new_size, and make start_ point to the
// new array.
template <class SomeType>
void MStackDynamicArray<SomeType>::ResizeArray(int new_size) {
  SomeType *new_start = new SomeType[new_size];
  // Copy existing stack items to the new array.
  for (int i = 0; i < size_; i++) {
    new_start[i] = start_[i];
  }
  delete[] start_;  // Delete the old array.
  start_ = new_start;  // Make start_ point to the new array.
  max_size_ = new_size;
}

template <class SomeType>
SomeType MStackDynamicArray<SomeType>::Top() {
  return (size_ > 0 ? start_[size_ - 1] : NULL);
}

template <class SomeType>
void MStackDynamicArray<SomeType>::Push(const SomeType &A) {
  if (size_ == max_size_) {
    if ( (max_size_*2) > LONG_MAX ) {
      throw "Stack size limit exceeded";
    }
    else {
      // Double the size of the array.
      MStackDynamicArray<SomeType>::ResizeArray(max_size_ * 2);
    }
  }
  // Insert the item into the array.
  start_[size_] = A;
  size_++;
}

template <class SomeType>
int MStackDynamicArray<SomeType>::size() {
  return size_;
}

#endif
