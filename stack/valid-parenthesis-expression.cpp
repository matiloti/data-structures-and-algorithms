using namespace std;
#include <iostream>
#include <string>
#include <map>
#include <stack>

bool isValidString(string s) {
    map<char, char> openToCloseParenthesisMap = {{'(', ')'},{'[', ']'},{'{', '}'}}; // ( -> ) , [ -> ], { -> }
    stack<char> parenthesisStack;
    for(int i = 0; i < s.length(); i++) {
        if(openToCloseParenthesisMap.count(s[i]) > 0) { // is open parenthesis
            parenthesisStack.push(s[i]);
        } else if(!parenthesisStack.empty() && openToCloseParenthesisMap[parenthesisStack.top()] == s[i]) { // is valid closing parenthesis
            parenthesisStack.pop();
        } else return false; // is invalid closing parenthesis
    }
    return parenthesisStack.empty(); // checking if there are open parenthesis left in the stack
}

int main()
{
    cout<<isValidString("()[]{}")<<endl; // true
    cout<<isValidString("()[]{")<<endl; // false
    cout<<isValidString("([{}])")<<endl; // true
    cout<<isValidString("([{]})")<<endl; // false
    cout<<isValidString("")<<endl; // true
    cout<<isValidString("([{}]")<<endl; // false
    cout<<isValidString("(")<<endl; // false
    cout<<isValidString(")")<<endl; // false

    return 0;
}