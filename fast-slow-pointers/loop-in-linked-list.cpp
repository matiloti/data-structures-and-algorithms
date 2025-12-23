using namespace std;

#include <iostream>

struct Node {
    int value;
    Node* next;
    Node(int d, Node* n = nullptr) : value(d), next(n) {}
};

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

bool loopInLinkedList(Node*& first) {
    Node* leader = first->next;
    Node* trailer = first;

    // 0 | l = null t = 0
    // 0 1 | l = 1 l = nullptr t = 1
    // 0 1 2 | l = 1 l = 2 t = 1
    // 0 1 2 | l = nullptr
    // 0 1 2 3 | l = 1 l = 2 t = 1
    // 0 1 2 3 | l = 3 l = nullptr (break!)
    // 0 1 2 3 1 2 3 ... | l = 1 l = 2 t = 1
    // 0 1 2 3 1 2 3 ... | l = 3 l = 1 t = 2
    // 0 1 2 3 1 2 3 ... | l = 2 l = 3 t = 3 !!!
    while(leader != nullptr && leader->next != nullptr) {
        leader = leader->next;
        if(leader->next == nullptr) break;
        leader = leader->next;
        trailer = trailer->next;
        if(leader->value == trailer->value) break;
    }

    if(leader != nullptr && leader->value == trailer->value) return true;
    return false;
}

int main() {
    Node* first = new Node(1, nullptr);
    cout << loopInLinkedList(first) << endl;

    first = new Node(1, nullptr);
    insertAtTheEnd(first, 2);
    cout << loopInLinkedList(first) << endl;

    first = new Node(1, nullptr);
    insertAtTheEnd(first, 2);
    insertAtTheEnd(first, 3);
    cout << loopInLinkedList(first) << endl;

    // 1 2 3 2 3 2 3 ...
    first = new Node(1, nullptr);
    first->next = new Node(2, nullptr);
    first->next->next = new Node(3, nullptr);
    first->next->next->next = first->next;
    cout << loopInLinkedList(first) << endl;

    // 0 0 0 0 ...
    first = new Node(0, nullptr);
    first->next = first;
    cout << loopInLinkedList(first) << endl;

    return 0;
}