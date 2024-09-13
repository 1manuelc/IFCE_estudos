public class Main {
    public static void main(String[] args) {
        DoubleLinkedList list = new DoubleLinkedList();
        list.push(1);
        list.push(2);
        list.push(4);

        list.showLinkedList();

        System.out.println(list.linearSearch(1));
        System.out.println(list.binarySearch(4));
    }
}