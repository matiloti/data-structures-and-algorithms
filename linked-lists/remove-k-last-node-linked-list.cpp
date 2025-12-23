using namespace std;

#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int d, Node* n = nullptr) : value(d), next(n) {}
};

void removeKLastNode(Node*& first, int k) {
    Node* dummy = new Node(-1, first);

    Node* trailer = dummy;
    Node* leader = dummy;

    // d -> 1 -> 2 -> 3
    for(int i = 0; i < k; i++) {
        leader = leader->next;
        if(leader->next == nullptr) break;
    }

    while(leader->next != nullptr) {
        trailer = trailer->next;
        leader = leader->next;
    }

    trailer->next = trailer->next->next;
    first = dummy->next;
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
    printLinkedList(first);
    removeKLastNode(first, 2);
    printLinkedList(first);
    freeMemory(first);

    cout << endl;

    first = new Node{1, nullptr};
    printLinkedList(first);
    removeKLastNode(first, 2);
    printLinkedList(first);
    freeMemory(first);

    cout << endl;

    first = new Node{1, nullptr};
    insertAtTheEnd(first, 2);
    insertAtTheEnd(first, 4);
    insertAtTheEnd(first, 7);
    insertAtTheEnd(first, 3);
    printLinkedList(first);
    removeKLastNode(first, 7);
    printLinkedList(first);
    freeMemory(first);

    cout << endl;

    first = new Node{1, nullptr};
    insertAtTheEnd(first, 2);
    insertAtTheEnd(first, 4);
    insertAtTheEnd(first, 7);
    insertAtTheEnd(first, 3);
    printLinkedList(first);
    removeKLastNode(first, 5);
    printLinkedList(first);
    freeMemory(first);

    cout << endl;

    first = new Node{1, nullptr};
    insertAtTheEnd(first, 2);
    insertAtTheEnd(first, 4);
    insertAtTheEnd(first, 7);
    insertAtTheEnd(first, 3);
    printLinkedList(first);
    removeKLastNode(first, 1);
    printLinkedList(first);
    freeMemory(first);

    cout << endl;

    first = new Node{1, nullptr};
    insertAtTheEnd(first, 2);
    insertAtTheEnd(first, 4);
    insertAtTheEnd(first, 7);
    insertAtTheEnd(first, 3);
    printLinkedList(first);
    removeKLastNode(first, 4);
    printLinkedList(first);
    freeMemory(first);

    return 0;
}