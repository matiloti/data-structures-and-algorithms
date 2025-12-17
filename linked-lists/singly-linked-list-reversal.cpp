using namespace std;

#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int d, Node* n = nullptr) : value(d), next(n) {}
};

void reverseSinglyLinkedList(Node*& first) {
    Node* prev = nullptr;
    Node* curr = first;

    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    first = prev;
}


void freeMemory(Node* first) {
    while (first) {
        Node* tmp = first;
        first = first->next;
        delete tmp;
    }
}

void insertAtTheEnd(Node*& first, int valueToInsert) {
    Node* nodeToInsert = new Node{valueToInsert, nullptr};
    if(first == nullptr) { 
        first = nodeToInsert; 
    } else {
        Node* node = first;
        while(node->next != nullptr) node = node->next;
        node->next = nodeToInsert;
    }
}

void printLinkedList(Node* first) {
    if (first == nullptr) return;

    cout << "[";
    Node* curr = first;

    while (curr->next != nullptr) {
        cout << curr->value << ", ";
        curr = curr->next;
    }

    cout << curr->value << "]" << endl;
}


int main() {
    Node* first = new Node{1, nullptr};
    insertAtTheEnd(first, 2);
    insertAtTheEnd(first, 4);
    insertAtTheEnd(first, 7);
    insertAtTheEnd(first, 3);

    reverseSinglyLinkedList(first);
    printLinkedList(first);

    freeMemory(first);

    return 0;
}