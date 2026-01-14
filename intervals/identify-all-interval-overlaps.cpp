using namespace std;
#include <iostream>
#include <utility>
#include <vector>

using Interval = pair<int,int>;
using IntervalList = vector<Interval>;

IntervalList findOverlaps(IntervalList il1, IntervalList il2) {
    int i1_idx = 0, i2_idx = 0;
    
    IntervalList result = {};
    
    while(i1_idx <= il1.size() && i2_idx <= il2.size()) {
        Interval i1 = il1[i1_idx];
        Interval i2 = il2[i2_idx];
        
        if(i2.second < i1.first) {
            i2_idx++; // skip i2
            continue;
        }
        if(i2.first > i1.second) {
            i1_idx++; // skip i1
            continue;
        }
        
        Interval o = Interval(-1,-1);
        if(i2.first >= i1.first) o.first = i2.first;
        else o.first = i1.first;
        
        if(i2.second <= i1.second) o.second = i2.second;
        else o.second = i1.second;
        
        result.push_back(o);
        
        if(i1.second == i2.second) {
            i1_idx++; 
            i2_idx++;
        } else if(i1.second <= i2.second) i1_idx++;
        else i2_idx++;
    }
        return result;
}

int main()
{
    IntervalList il1 = {
      {1,4},
      {5,6},
      {9,10}
    };
    IntervalList il2 = {
      {2,7},
      {8,9}
    };
    
    IntervalList result = findOverlaps(il1, il2);
    
    cout << "[";
    for(Interval i : result) {
        cout << "[" << i.first << ", " << i.second << "], ";
    }
    cout << "]" << endl;

    return 0;
}