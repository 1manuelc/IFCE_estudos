#include <iostream>

#include "linked-list.cpp"

int main() {
    LinkedList list;
    list.push(30);
    list.push(20);
    list.push(5);
    list.push(42);
    list.push(43);
    list.push(40);
    list.pop();

    list.printList();
    std::cout << "list length: " << list.getSize() << '\n';

    list.shellSort();
    list.printList();
    return 0;
}