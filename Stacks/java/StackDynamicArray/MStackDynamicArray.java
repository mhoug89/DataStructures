package stackdynamicarray;

public class MStackDynamicArray<Item> {
  public static int DEFAULT_STACK_SIZE = 16;
  private final static int GROWTH_FACTOR = 2;
  private final static int SHRINK_THRESHOLD = 4;

  private int size = 0;
  private Item[] arr;

  public MStackDynamicArray() {
    arr = (Item[]) new Object[DEFAULT_STACK_SIZE];
  }

  public boolean isEmpty() {
    return size == 0;
  }

  public Item pop() {
    if (this.isEmpty()) {
      return null;
    }
    Item temp = arr[--size];
    arr[size] = null;
    if (size == arr.length / SHRINK_THRESHOLD) {
      resizeArray(arr.length / GROWTH_FACTOR);
    }
    return temp;
  }

  public void push(Item item) {
    // When the array is at full capacity, grow it.
    if (size == arr.length) {
      resizeArray(arr.length * GROWTH_FACTOR);
    }
    arr[size++] = item;
  }

  private void resizeArray(int newSize) {
    Item[] newArr = (Item[]) new Object[newSize];
    for (int i = 0; i < size; i++) {
      newArr[i] = arr[i];
    }
    arr = newArr;
  }
}
