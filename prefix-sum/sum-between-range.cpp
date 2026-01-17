using namespace std;
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using Sum = pair<int,int>;
using SumList = vector<Sum>;

vector<int> prefixSum(const vector<int> &list) {
    int currSum = list[0];
    vector<int> res = {currSum};
    for(int i = 1; i < list.size(); i++) 
        res.push_back(list[i] + res[i-1]);
    return res;
}

vector<int> computeSums(const vector<int> &list, const SumList &sumList) {
    vector<int> prefixSumList = prefixSum(list);
    for(int num : prefixSumList) cout << num << ", ";
    vector<int> res;
    
    for(Sum sum : sumList) {
        int start;
        if(sum.first - 1 >= 0) start = prefixSumList[sum.first - 1];
        else start = 0;
        int end = prefixSumList[sum.second];
        res.push_back(end - start);
    }
    
    return res;
}

int main()
{
    vector<int> input = {3,-7,6,0,-2,5};
    SumList sumList = {
        {0,3},
        {2,4},
        {2,2}
    };
    
    vector<int> res = computeSums(input, sumList);
    cout << "[";
    for(int num : res) cout << num << ", ";
    cout << "]" << endl;

    return 0;
}