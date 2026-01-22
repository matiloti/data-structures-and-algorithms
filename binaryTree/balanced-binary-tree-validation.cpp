using namespace std;
#include <iostream>
#include <cmath>
#include <algorithm>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

int isBalancedTree(const Node* root) {
    if(root == nullptr) return 0;
    int leftHeight = isBalancedTree(root->left);
    if(leftHeight == -1) return -1;
    int rightHeight = isBalancedTree(root->right);
    if(rightHeight == -1) return -1;
    if(abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right = new Node(7);
    root->right->right = new Node(9);
    root->right->right->left = new Node(6);
    std::cout<<isBalancedTree(root);
    
    root = new Node(5);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right = new Node(7);
    root->right->right = new Node(9);
    std::cout<<isBalancedTree(root);

    return 0;
}