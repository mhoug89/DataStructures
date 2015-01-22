/**
 * Compile with --std=c++11 to allow use of vector initializer lists.
 */

#include <stdio.h>
#include <string>
#include <vector>
#include "MStackDynamicArray.h"

int main(int argc, char** argv) {
  MStackDynamicArray<std::string> myStack(2);
  printf("Pushing these values to the stack:");
  std::vector<std::string> v {"I", "am", "on", "the", "stack"};
  for (std::vector<std::string>::iterator it = v.begin();
       it != v.end(); it++) {
    printf(" \"%s\"", it->c_str());
    myStack.Push(*it); 
  }
  printf("\nAFTER PUSHES: Stack size: %d, with top value: \"%s\"\n",
         myStack.size(), myStack.Top().c_str());

  printf("\nPopping stack until empty.\n");
  while (!myStack.IsEmpty()) {
    // DON'T DO THIS - order of argument evaluation is not defined by the
    // standard, thus Pop() could be called before Top(), resulting in
    // different entries being printed.
    // printf("Popped entry: \"%s\" \"%s\"",
    //        myStack.Top().c_str(), myStack.Pop().c_str());

    // Correct way to print val from Top() first, then Pop()... two statements.
    // printf("Top: \"%s\", ", myStack.Top().c_str());
    printf("Popped entry: \"%s\", ", myStack.Pop().c_str());

    // Print stack size too, just to for extra debug info.
    printf("stack size: %d\n", myStack.size());
  }
  return 0;
}
