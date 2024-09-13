#include <iostream>

class Node {
   public:
    int key;
    Node* next;

    Node(int key) : key(key), next(nullptr) {}
};

class LinkedList {
   private:
    Node* head;

    Node* getNodeAt(int index) {
        Node* temp = head;

        for (int i = 0; i < index && temp->next != nullptr; i++) {
            temp = temp->next;
        }

        return temp;
    }

   public:
    LinkedList() : head(nullptr) {}

    void push(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int pop() {
        if (head == nullptr) {
            return -1;  // Lista vazia
        }

        if (head->next == nullptr) {  // Apenas um elemento
            int data = head->key;
            delete head;
            head = nullptr;
            return data;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        int data = temp->next->key;
        delete temp->next;
        temp->next = nullptr;
        return data;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->key << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    int getSize() {
        if (head == nullptr) {
            return -1;
        } else {
            Node* temp = head;
            int size = 0;

            while (temp->next != nullptr) {
                size++;
                temp = temp->next;
            }

            return size + 1;
        }
    }

    void shellSort() {
        int size = getSize();
        int gap = 1;

        while (gap < size / 3) {
            gap = 3 * gap + 1;
        }

        while (gap > 0) {
            for (int i = gap; i < size; i++) {
                int actualKey = getNodeAt(i)->key;
                int j = i;

                while (j >= gap && actualKey < getNodeAt(j - gap)->key) {
                    getNodeAt(j)->key = getNodeAt(j - gap)->key;
                    j -= gap;
                }

                getNodeAt(j)->key = actualKey;
            }

            gap = (gap - 1) / 3;
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
