using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using Interval = pair<int,int>;
using IntervalList = vector<Interval>;

bool overlaps(const Interval &a, const Interval &b) {
    return (a.first < b.second) && (a.second > b.first);
}

int maxOverlap(IntervalList &list) {
    
    // first, sort list
    sort(list.begin(), list.end(),
              [](const Interval& a, const Interval& b) {
                  if (a.first != b.first)
                      return a.first < b.first;
                  return a.second < b.second;
              });
              
    int firstOverlapping_idx = 0;
    int maxOverlapCount = 1;
    for(int i = 1; i < list.size(); i++) {
        Interval curr = list[i];
        Interval firstOverlapping = list[firstOverlapping_idx];
        
        // If overlaps, set max and continue
        if(overlaps(curr, firstOverlapping)) {
            int currOverlapCount = i - firstOverlapping_idx + 1;
            maxOverlapCount = max(currOverlapCount, maxOverlapCount);
            continue;
        }
        
        // Otherwise find first overlapping interval and set it as first
        int aux = firstOverlapping_idx;
        while(!overlaps(list[aux], curr)) aux++;
        firstOverlapping_idx = aux;
    }
    
    return maxOverlapCount;
}

int main()
{
    IntervalList list = {
        {1,3},
        {2,6},
        {4,8},
        {6,7},
        {5,7}
    };
    cout<<maxOverlap(list)<<endl;
    
    list = {
        {1,2},
        {2,3},
        {3,4}
    };
    cout<<maxOverlap(list)<<endl;
    
    list = {
        {1,2}
    };
    cout<<maxOverlap(list)<<endl;
    
    list = {
        {6,7},
        {1,3},
        {4,8},
        {2,6},
        {5,7}
    };
    cout<<maxOverlap(list)<<endl;
    
    list = {
        {1,3},
        {2,4},
        {3,5},
        {4,6},
        {5,7}
    };
    cout<<maxOverlap(list)<<endl;

    return 0;
}