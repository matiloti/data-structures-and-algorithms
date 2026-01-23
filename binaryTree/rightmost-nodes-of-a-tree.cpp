using namespace std;
#include <iostream>
#include <vector>

struct Node {
  int value;
  Node* left;
  Node* right;
  Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

void dfsRightMostNode(Node* root, vector<int>& res, int depth) {
    if(root == nullptr) return;
    
    if(res.size() < depth) res.push_back(root->value);
    
    dfsRightMostNode(root->right, res, depth + 1);
    dfsRightMostNode(root->left, res, depth + 1);
}

vector<int> rightmostNodes(Node* root) {
    vector<int> res;
    dfsRightMostNode(root, res, 1);
    return res;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->right = new Node(11);
    root->right = new Node(3);
    root->right->left = new Node(6);
    vector<int> res = rightmostNodes(root);
    for(int num : res) {
        cout<<num<<", ";
    }
    cout<<endl;

    return 0;
}