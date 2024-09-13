public class DoubleLinkedList {
    public Node head;
    public Node tail;

    public DoubleLinkedList() {
        head = null;
        tail = null;
    }

    void push(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }

    int pop() {
        if (tail == null) {
            return -1;  // Lista vazia
        }

        int data = tail.key;
        if (tail.prev != null) {
            tail = tail.prev;
            tail.next = null;
        } else {
            head = tail = null; // Caso em que há apenas um elemento na lista
        }
        return data;
    }

    int linearSearch(int elt) {
        Node temp = head;
        int i = 0;

        while (temp != null && temp.key != elt) {
            temp = temp.next;
            i++;
        }

        return (temp != null && temp.key == elt) ? i : -1;
    }

    int at(int index) {
        Node temp = head;
        int i = 0;
        while (i != index && temp != null) {
            temp = temp.next;
            i++;
        }

        return (temp != null) ? temp.key : -1;
    }

    int length() {
        Node temp = head;
        int nodeCount = 0;

        while (temp != null) {
            temp = temp.next;
            nodeCount++;
        }

        return nodeCount;
    }

    int binarySearch(int elt) {
        int leftLimit = 0, rightLimit = this.length() - 1, middle;

        while (leftLimit <= rightLimit) {
            middle = (leftLimit + rightLimit) / 2;
            int middleValue = this.at(middle);

            if (middleValue == elt) return middle;

            if (middleValue < elt) leftLimit = middle + 1;
            else rightLimit = middle;
        }

        return -1;
    }

    void showLinkedList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.key + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}
