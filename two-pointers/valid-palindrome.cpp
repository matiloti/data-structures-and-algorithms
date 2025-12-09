using namespace std;

#include <iostream>
#include <string>

char toLower(char c) {
    return std::tolower(static_cast<unsigned char>(c));
}

bool isPalindrome(std::string text) {
    if(&text == nullptr) return false;

    int left = 0, right = text.length() - 1;
    while(left <= right) {
        while(left <= right && !std::isalnum(text[left])) left++;
        while(left <= right && !std::isalnum(text[right])) right--;
        if(left <= right && toLower(text[left]) != toLower(text[right])) return false;
        left++; right--;
    }
    return true;
}

int main() {
    std::string test1 = "a dog! a panic in a pagoda."; // true
    std::string test2 = "abc123"; // false
    std::string test3 = ""; // true
    // std::string test4 = nullptr; // false
    std::string test5 = ".a@a_   "; // true
    std::string test6 = "b #2  .a@a_  b 2  "; // false
    std::string test7 = "b #2  .a@a_  2  .b   "; // true
    std::string test8 = "a"; // true
    std::string test9 = "?"; // true
    std::string test10 = "ab"; // false

    cout << isPalindrome(test1) << endl;
    cout << isPalindrome(test2) << endl;
    cout << isPalindrome(test3) << endl;
    // cout << isPalindrome(test4) << endl;
    cout << isPalindrome(test5) << endl;
    cout << isPalindrome(test6) << endl;
    cout << isPalindrome(test7) << endl;
    cout << isPalindrome(test8) << endl;
    cout << isPalindrome(test9) << endl;
    cout << isPalindrome(test10) << endl;

    return 0;
}