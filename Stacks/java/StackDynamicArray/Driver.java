package stackdynamicarray;

import stackdynamicarray.MStackDynamicArray;

public class Driver {
  public static void main(String[] args) {
    MStackDynamicArray<String> myStack = new MStackDynamicArray<String>();
    myStack.push("This");
    myStack.push("is");
    myStack.push("a");
    myStack.push("test");
    while (!myStack.isEmpty()) {
      System.out.println("Top item: " + myStack.pop());
    }
  }
}
