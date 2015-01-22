package stacklinkedlist;

public class MStackLinkedList<Item> {
  private Node top = null;

  private class Node {
    Item data;
    Node next;

    Node(Item data, Node next) {
      this.data = data;
      this.next = next;
    }
  }

  public boolean isEmpty() {
    return top == null;
  }

  public Item pop() {
    if (this.isEmpty()) {
      return null;
    }
    Node temp = top;
    top = top.next;
    return temp.data;
  }

  public void push(Item item) {
    Node newNode = new Node(item, top);
    top = newNode;
  }
}
