using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int countWood(vector<int> v, int heighToCut, int targetWood) {
    int woodCount = 0;
    for(int i = v.size() - 1; i >=0; i--) {
        woodCount += v[i] - heighToCut;
        if(woodCount >= targetWood) break;
    }
    return woodCount;
}

int getMaxHeight(vector<int> v, int targetWood) {
    sort(v.begin(), v.end());
    
    if(targetWood == 0) return v.back();
    
    int l = 0, r = v.back() - 1;
    int maxHeight = 0;
    
    while(l < r) {
        int mid = (r + l + 1) / 2; //ceil
        int woodCount = countWood(v, mid, targetWood);
        if(woodCount >= targetWood) { 
            l = mid;
            maxHeight = mid;
        } else r = mid - 1;
    }
    
    return maxHeight;
}

int main()
{
    vector<int> v = {2, 6, 3, 8};
    std::cout<<getMaxHeight(v, 7)<<endl;
    
    v = {2, 6, 3, 8};
    std::cout<<getMaxHeight(v, 5)<<endl;
    
    v = {2, 6, 3, 8};
    std::cout<<getMaxHeight(v, 3)<<endl;
    
    v = {2, 6, 3, 8};
    std::cout<<getMaxHeight(v, 15)<<endl;
    
    v = {2, 6, 3, 8};
    std::cout<<getMaxHeight(v, 16)<<endl;
    
    v = {2, 6, 3, 8};
    std::cout<<getMaxHeight(v, 0)<<endl;
    
    v = {8};
    std::cout<<getMaxHeight(v, 7)<<endl;
    
    v = {8};
    std::cout<<getMaxHeight(v, 0)<<endl;
    
    v = {8};
    std::cout<<getMaxHeight(v, 6)<<endl;
    
    return 0;
    
}