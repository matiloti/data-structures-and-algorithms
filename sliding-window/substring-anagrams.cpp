using namespace std;

#include <iostream>
#include <string>
#include <map>

int substringAnagrams(string s, string t) {
    map<char, int> charCounters;
    
    for(int i = 0; i < t.length(); i++) charCounters[t[i]]++;
    
    int left = 0, right = 0;
    int numberOfAnagrams = 0;
    
    while(right < s.length()) {
        char newChar = s[right];
        int windowLength = right - left + 1;
        bool rightCharIsAvailable = charCounters[newChar] >= 1;
        bool rightCharExists = charCounters.count(newChar) >= 1;
        if(rightCharExists) {
            if(rightCharIsAvailable) {
                charCounters[newChar]--;
                if(windowLength == t.length()) {
                    numberOfAnagrams++;
                    charCounters[s[left++]]++;
                }
            } else {
                charCounters[s[left++]]++;
            }
            right++;
        } else {
            right++;
            while(left < right) charCounters[s[left++]]++;
        }
    }
    
    return numberOfAnagrams;
}

int main()
{
    cout<< substringAnagrams("caabaa", "aba") << endl; // 3
    cout<< substringAnagrams("caabab", "aba") << endl; // 2
    cout<< substringAnagrams("a", "b") << endl; // 0
    cout<< substringAnagrams("a", "a") << endl; // 1
    cout<< substringAnagrams("aa", "a") << endl; // 2
    cout<< substringAnagrams("pacapac", "pac") << endl; // 3

    return 0;
}