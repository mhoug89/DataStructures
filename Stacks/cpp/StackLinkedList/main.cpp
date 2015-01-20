#include <iostream>
#include <string>
#include <string.h>
#include "MStackLinkedList.hpp"

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
