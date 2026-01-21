using namespace std;
#include <iostream>
#include <queue>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v, Node* l = nullptr, Node* r = nullptr) : value(v), left(l), right(r) {}
};

void invertBinaryTree(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();
        Node* aux = currNode->left;
        currNode->left = currNode->right;
        currNode->right = aux;
        if(currNode->left != nullptr) q.push(currNode->left);
        if(currNode->right != nullptr) q.push(currNode->right);
    }
}

void printTreeBfs(Node* root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* currNode = q.front();
        q.pop();
        Node* leftNode = currNode->left;
        Node* rightNode = currNode->right;
        
        cout<<currNode->value<<" ";
        if(currNode->left != nullptr) q.push(currNode->left);
        if(currNode->right != nullptr) q.push(currNode->right);
    }
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->right = new Node(4);
    invertBinaryTree(root);
    printTreeBfs(root);
    

    return 0;
}