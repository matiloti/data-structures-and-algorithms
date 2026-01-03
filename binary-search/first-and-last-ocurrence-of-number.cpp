using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

int binarySearch(vector<int> v, int target, bool lowerBound) {
    int left = 0, right = v.size() - 1;
    int mid;
    while(left < right) {
        if(lowerBound) {
            mid = (left + right) / 2; // 0
            if(target <= v[mid]) right = mid; // 2 <= 1?
            else left = mid + 1; // left = 1
        } else {
            mid = (left + right + 1) / 2; // 1
            if(target >= v[mid]) left = mid; // 2 >= 1?
            else right = mid - 1;
        }
    }
    
    if(v[left] != target) return -1;
    return left;
}

int main()
{
    vector<int> v = {1,2,3,4,4,4,5,6,7,8,9,10,11};
    std::cout<< "[" << binarySearch(v, 4, true) << ", " << binarySearch(v, 4, false) << "]" << endl;

    // [1, 3], 2 -> 0, 1
    // 1) l = 0, r = 1, m = 0, l = 1, r = 1
    
    // 1) l = 0, r = 1, m = 1, l = 2, r = 1
    v = {1,3, 3,3,3,3};
    std::cout<< "[" << binarySearch(v, 3, true) << ", " << binarySearch(v, 3, false) << "]" << endl;


    return 0;
}