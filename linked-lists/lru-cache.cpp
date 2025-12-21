using namespace std;

#include <iostream>

struct Node {
    Node* next;
    int key;
    int value;
    Node(int key, int value, Node* next) : key(key), value(value), next(next) {}
};

class LRUCache {
    private:
        const int maxCapacity;
        int currCapacity;
        Node* head;

        bool cacheIsFull() { return maxCapacity == currCapacity; }
        bool cacheIsEmpty() { return 0 == currCapacity; }

        Node* removeNode(int key, bool removeTailIfNotFound) {

            if(head == nullptr) return nullptr;

            Node* prev = nullptr;
            Node* curr = head;
            Node* result = nullptr;

            if(curr->key == key) {
                head = curr->next;
                result = new Node(key, curr->value, nullptr);
                delete curr;
            }

            if(result == nullptr) {
                while(curr->next != nullptr) {
                    if(curr->key == key) break;
                    prev = curr;
                    curr = curr->next;
                }

                if(curr->key == key || (cacheIsFull() && removeTailIfNotFound)) {
                    prev->next = curr->next;
                    result = new Node(key, curr->value, nullptr);
                    delete curr;
                }
            }

            if(result != nullptr) currCapacity--;
            if(cacheIsEmpty()) head = nullptr;

            return result;
        }

        void insertAtFront(int key, int value) {
            Node* newNode = new Node(key, value, head);
            head = newNode;
            if(!cacheIsFull()) currCapacity++;
        }

        void freeMemory() {
            Node* curr = head;
            while (curr) {
                Node* tmp = curr;
                curr = curr->next;
                delete tmp;
            }
        }


    public:
        LRUCache(int maxCapacity) : maxCapacity(maxCapacity), currCapacity(0), head(nullptr) {}

        ~LRUCache() { freeMemory(); }

        void put(int key, int value) {
            removeNode(key, true);
            insertAtFront(key, value);
        }

        int get(int key) {
            int result = -1;
            Node* node = removeNode(key, false);
            if(node != nullptr && node->key == key) {
                insertAtFront(key, node->value);
                result = node->value;
            }
            return result;
        }
};

int main() {
    LRUCache cache = LRUCache(3);

    cout << cache.get(1) << endl; // -1

    cache.put(1, 10);

    cout << cache.get(1) << endl; // 10

    cache.put(2, 20);
    cache.put(3, 30);
    cache.put(4, 40);

    cout << cache.get(2) << endl; // 20
    cout << cache.get(3) << endl; // 30
    cout << cache.get(1) << endl; // -1

    cache.put(5, 50);

    cout << cache.get(4) << endl; // -1
    
    cache.put(4, 40);

    cout << cache.get(4) << endl; // 40

    cache.put(4, 44);

    cout << cache.get(4) << endl; // 44
    cout << cache.get(1) << endl; // -1

    cache.put(1, 11);

    cout << cache.get(1) << endl; // 11
    cout << cache.get(5) << endl; // 50

    cache.put(6, 60);

    cout << cache.get(4) << endl; // -1

    cout << cache.get(1) << endl; // 11
    cout << cache.get(5) << endl; // 50
    cout << cache.get(6) << endl; // 60

    cout << cache.get(2) << endl; // -1
    cout << cache.get(3) << endl; // -1
    cout << cache.get(4) << endl; // -1

    return 0;
}