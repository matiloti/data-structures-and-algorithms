using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
};

vector<Interval> mergeIntervals(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(),
              [](const Interval& a, const Interval& b) {
                  if (a.start != b.start)
                      return a.start < b.start;
                  return a.end < b.end;
              });
    vector<Interval> result;
    Interval mergedInterval = intervals[0];
    for(Interval currInterval : intervals) {
        if(currInterval.end == mergedInterval.end) continue;
        
        if(currInterval.start < mergedInterval.end) mergedInterval.end = currInterval.end;
        else if(currInterval.start > mergedInterval.end) {
            result.push_back(mergedInterval);
            mergedInterval.start = currInterval.start;
            mergedInterval.end = currInterval.end;
        }
    }
    result.push_back(mergedInterval);
    return result;
}

int main()
{
    vector<Interval> intervals = {
        {0, 3},
        {2, 3},
        {3, 5}
    };
    
    vector<Interval> result = mergeIntervals(intervals);

    cout << "[";
    for(Interval interval : result) {
        cout << "[" << interval.start << ", " << interval.end << "]";
    }
    cout << "]" << endl;
    
    intervals = {
        {0, 3},
        {2, 3},
        {3, 5},
        {7, 10},
        {9, 12}
    };
    
    result = mergeIntervals(intervals);

    cout << "[";
    for(Interval interval : result) {
        cout << "[" << interval.start << ", " << interval.end << "]";
    }
    cout << "]" << endl;

    return 0;
}