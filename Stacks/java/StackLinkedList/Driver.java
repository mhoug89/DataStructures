package stacklinkedlist;

import stacklinkedlist.MStackLinkedList;

public class Driver {
  public static void main(String[] args) {
    MStackLinkedList<String> myStack = new MStackLinkedList<String>();
    myStack.push("This");
    myStack.push("is");
    myStack.push("a");
    myStack.push("test");
    while (!myStack.isEmpty()) {
      System.out.println("Top item: " + myStack.pop());
    }
  }
}
