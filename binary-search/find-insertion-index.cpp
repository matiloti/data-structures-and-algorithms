using namespace std;

#include <iostream>
#include <vector>
#include <cmath>

int binarySearch(vector<int> v, int target) {
    int left = 0, right = v.size() - 1;
    int mid = -1;
    
    while(left < right) {
        mid = floor(left + (right - left) / 2);
        if(target > v[mid]) left = mid + 1;
        else right = mid;
    }
    
    return left;
}

int main()
{
    vector<int> v1 = {0,1,3,4};
    std::cout<< binarySearch(v1, 2) << endl; // 2
    std::cout<< binarySearch(v1, 3) << endl; // 2
    std::cout<< binarySearch(v1, 0) << endl; // 0
    std::cout<< binarySearch(v1, 4) << endl; // 3
    std::cout<< binarySearch(v1, 1) << endl; // 1
    std::cout<< binarySearch(v1, 5) << endl; // 4

    return 0;
}