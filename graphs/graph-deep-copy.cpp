using namespace std;
#include <iostream>
#include <vector>
#include <map>

struct Node {
    int value;
    vector<Node*> neighbours;
    Node(int v) : value(v) {}
};

Node* dfs(Node* root, map<int, Node*> explored) {
    if(explored.find(root->value) != explored.end()) 
        return explored[root->value];
    
    Node* newNode = new Node(root->value);
    explored.insert({root->value, newNode});
    for(Node* neighbour : root->neighbours) {
        Node* newNeighbour = dfs(neighbour, explored);
        newNode->neighbours.push_back(newNeighbour);
    }
    
    return newNode;
}

Node* deepCopy(Node* root) {
    map<int, Node*> explored;
    return dfs(root, explored);
}

int main()
{
    Node* zero = new Node(0);
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    zero->neighbours.push_back(one);
    zero->neighbours.push_back(two);
    one->neighbours.push_back(zero);
    one->neighbours.push_back(two);
    two->neighbours.push_back(zero);
    two->neighbours.push_back(one);
    two->neighbours.push_back(three);
    deepCopy(zero);

    return 0;
}