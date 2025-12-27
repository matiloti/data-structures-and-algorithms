using namespace std;

#include <iostream>
#include <string>
#include <cmath>

int calculateNextNumber(int number) {
    string s = to_string(number);
    int result = 0;
    for(int i = 0; i < s.length(); i++) {
        int c = s[i] - '0';
        result += pow(c, 2);
    }
    return result;
}

bool isHappyNumber(int number) {
    int slow = number, fast = number;

    while(fast != 1) {
        fast = calculateNextNumber(calculateNextNumber(fast));
        slow = calculateNextNumber(slow);
        if(fast == slow) return false;
    }

    return true;
}

int main() {

    cout << "--- Happy numbers ---" << endl;
    cout << isHappyNumber(23) << endl;
    cout << isHappyNumber(86) << endl;
    cout << isHappyNumber(68) << endl;
    cout << isHappyNumber(13) << endl;
    cout << isHappyNumber(31) << endl;
    cout << isHappyNumber(1) << endl << endl;

    cout << "--- Unhappy numbers ---" << endl;
    cout << isHappyNumber(22) << endl;
    cout << isHappyNumber(42) << endl;
    cout << isHappyNumber(53) << endl;
    cout << isHappyNumber(99) << endl;
    cout << isHappyNumber(0) << endl;

    return 0;
}