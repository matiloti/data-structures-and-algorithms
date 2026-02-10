/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
using namespace std;
#include <iostream>
#include <utility>
#include <algorithm>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v): value(v) {}
};

pair<int,int> maxPathSearch(Node* root) {
    if(root == nullptr) return {0,0};
    
    pair<int,int> left = maxPathSearch(root->left);
    pair<int,int> right = maxPathSearch(root->right);
    
    int sumLeft = root->value + left.second;
    int sumRight = root->value + right.second;
    int sumOfPaths = root->value + left.second + right.second;
    
    int maxContinuousPath = max(sumLeft, sumRight);
    int maxPath = max(
        max(sumOfPaths, maxContinuousPath), 
        max(left.first, right.first)
    );
    
    return {maxPath, maxContinuousPath};
}

int maxPath(Node*root) {
    return maxPathSearch(root).first;
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(-10);
    root->left->left = new Node(1);
    root->left->right = new Node(-7);
    root->left->left->left = new Node(11);
    root->left->right->left = new Node(-1);
    root->right = new Node(8);
    root->right->left = new Node(9);
    root->right->right = new Node(7);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(-3);
    cout<<maxPath(root);

    return 0;
}