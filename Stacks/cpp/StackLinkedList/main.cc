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
  myStack.Push("I");
  myStack.Push("am");
  myStack.Push("on");
  myStack.Push("the");
  myStack.Push("stack");

  //  MStackLinkedList<string> myStack;
  //  string I = "I";
  //  string am = "am";
  //  myStack.Push(I);
  //  myStack.Push(am);
  //
  //  MStackLinkedList<int> myStack;
  //  myStack.Push(1);
  //  myStack.Push(2);
  //  myStack.Push(3);
  //
  //  MStackLinkedList<NumberClass> myStack;
  //  myStack.Push(NumberClass(1));
  //  myStack.Push(NumberClass(2));

  while (!myStack.IsEmpty()) {
    cout << "From main(): " << myStack.Top() << "\n";
    myStack.Pop();
  }

  cout << "\nPress any key to exit.";
  cout << endl;

  cin.get();

  return 0;
}
