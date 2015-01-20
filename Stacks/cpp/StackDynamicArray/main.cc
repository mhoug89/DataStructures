/**
 * Compile with --std=c++11 to allow use of vector initializer lists.
 */

#include <stdio.h>
#include <string>
#include <vector>
#include "MStackDynamicArray.h"

int main(int argc, char** argv) {
  MStackDynamicArray<std::string> myStack(4);
  printf("Pushing these values to the stack:");
  std::vector<std::string> v {"I", "am", "on", "the", "stack"};
  for (std::vector<std::string>::iterator it = v.begin();
       it != v.end(); it++) {
    printf(" \"%s\"", it->c_str());
    myStack.push(*it);  // 5th push should double underlying array size to 8.
  }
  printf("\nAFTER PUSHES: Stack size: %d, with top value: \"%s\"\n",
         myStack.size(), myStack.top().c_str());

  printf("\nPopping stack until empty.\n");
  while (!myStack.isEmpty()) {
    // DON'T DO THIS - order of argument evaluation is not defined by the
    // standard, thus pop() could be called before top(), resulting in
    // different entries being printed.
    // printf("Popped entry: \"%s\" \"%s\"",
    //        myStack.top().c_str(), myStack.pop().c_str());

    // Correct way to print val from top() first, then pop()... two statements.
    // printf("Top: \"%s\", ", myStack.top().c_str());
    printf("Popped entry: \"%s\", ", myStack.pop().c_str());

    // Print stack size too, just to for extra debug info.
    printf("stack size: %d\n", myStack.size());
  }

  return 0;
}
