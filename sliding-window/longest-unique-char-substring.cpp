using namespace std;
#include <iostream>
#include <string>
#include <set>

//longestUniqueCharacterSubstringLength
int longest(string s) {
    int left = 0, right = 0, maxWindowSize = 0;
    set<char> windowCharacters;
    
    while(right < s.length()) {
        char c_left = s[left], c_right = s[right];
        if(windowCharacters.find(c_right) != windowCharacters.end()) {
            do {
                windowCharacters.erase(c_left);
                c_left = s[left++];
            } while(c_left != c_right);
        } else {
            maxWindowSize = right - left + 1;
        }
        windowCharacters.insert(c_right);
        right++;
    }
    
    return maxWindowSize;
}

int main()
{
    std::cout<< longest("abcab") << endl; // 3
    std::cout<< longest("aaa") << endl; // 1
    std::cout<< longest("ababbbcabc") << endl; // 3
    std::cout<< longest("abcabcdacjab") << endl; // 4
    std::cout<< longest("a") << endl; // 1
    std::cout<< longest("") << endl; // 0

    return 0;
}