using namespace std;
#include <iostream>
#include <string>

int longest(string s, int k) {
    if(s.length() == 0) return 0;
    if(s.length() == 1) return 1;
    
    int max = 0;
    int left = 0, right = 0;
    int currK = k;
    
    while(right < s.length()) {
        char c_right = s[right];
        char c_left = s[left];
        int currWindowSize = right - left + 1;
        
        if(c_right == c_left) right++;
        else if(currK > 0) {
            currK--;
            right++;
        } else if(currWindowSize - 1 > max) {
            max = currWindowSize - 1;
        }
        
        if(s.length() - left + 1 <= max) break;
    
        
        while(s[left] == c_left) left++;
        currK = k;
        right = left + 1;
    }
}

int main()
{
    std::cout<<"Hello World";

    return 0;
}