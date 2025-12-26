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

Node* findMidpoint(Node*& first) {
    Node* fast = first;
    Node* slow = first;

    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main() {

    Node* first = new Node(1, nullptr);
    first->next = new Node(2, nullptr);
    first->next->next = new Node(3, nullptr);
    first->next->next->next = new Node(4, nullptr);
    first->next->next->next->next = new Node(5, nullptr);
    cout << findMidpoint(first)->value << endl; // 3

    freeMemory(first);

    first = new Node(1, nullptr);
    first->next = new Node(2, nullptr);
    first->next->next = new Node(3, nullptr);
    first->next->next->next = new Node(4, nullptr);
    first->next->next->next->next = new Node(5, nullptr);
    first->next->next->next->next->next = new Node(6, nullptr);
    cout << findMidpoint(first)->value << endl; // 4

    freeMemory(first);

    first = new Node(1, nullptr);
    cout << findMidpoint(first)->value << endl; // 1

    freeMemory(first);

    return 0;
}