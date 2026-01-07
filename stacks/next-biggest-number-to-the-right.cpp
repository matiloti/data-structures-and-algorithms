using namespace std;
#include <iostream>
#include <vector>
#include <stack>

vector<int> nextLargestNumberToTheRight(vector<int> v) {
    vector<int> res(v.size());
    stack<int> stack;
    for(int i = v.size() - 1; i >= 0; i--) {
        while(!stack.empty() && stack.top() <= v[i]) stack.pop();
        if(!stack.empty()) res[i] = stack.top();
        else res[i] = -1;
        stack.push(v[i]);
    }
    return res;
}


int main()
{
    vector<int> v = {5,2,4,6,1};
    vector<int> res = nextLargestNumberToTheRight(v);
    
    for(int num : res) {
        cout << num << endl; 
    }
    
    cout << "---" << endl;
    
    v = {1};
    res = nextLargestNumberToTheRight(v);
    
    for(int num : res) {
        cout << num << endl; 
    }
    
    cout << "---" << endl;
    
    v = {1,1};
    res = nextLargestNumberToTheRight(v);
    
    for(int num : res) {
        cout << num << endl; 
    }
    
    cout << "---" << endl;
    
    v = {1,2,3,4,5,1};
    res = nextLargestNumberToTheRight(v);
    
    for(int num : res) {
        cout << num << endl; 
    }

    return 0;
}