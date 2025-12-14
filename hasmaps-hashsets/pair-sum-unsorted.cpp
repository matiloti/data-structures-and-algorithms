using namespace std;

#include <iostream>
#include <utility>
#include <cstddef>
#include <unordered_map>
#include <vector>
#include <string>

vector<int> pairNumUnsorted(int array[], size_t size, int target) {
    vector<int> res = vector<int>();
    unordered_map<int, int> visitedElements = {};
    for(int currPos = 0; currPos < size; currPos++) {
        int currElement = array[currPos];
        if(visitedElements.count(target - currElement) == 1) {
            res.push_back(visitedElements[target - currElement]);
            res.push_back(currPos);
        }
        visitedElements[currElement] = currPos;
    }
    return res;
}

string vectorToString(const vector<int>& vector) {
    string res = "[";
    for(int i = 1; i < vector.size(); i++) {
        res += to_string(vector.at(i - 1)) + ", ";
    }
    if(vector.size() > 0) res += to_string(vector.back());
    return res + "]";
}


int main() {
    int test1[] = { -1, 3, 4, 2 };
    int test2[] = { };
    int test3[] = { 1 };

    cout << "Expected: [0, 2] ; Actual: " << vectorToString(pairNumUnsorted(test1, 4, 3)) << "\n";

    cout << "Expected: [] ; Actual: " << vectorToString(pairNumUnsorted(test1, 4, 1234)) << "\n";

    cout << "Expected: [0, 3] ; Actual: " << vectorToString(pairNumUnsorted(test1, 4, 1)) << "\n";

    cout << "Expected: [] ; Actual: " << vectorToString(pairNumUnsorted(test2, 0, 1)) << "\n";

    cout << "Expected: [] ; Actual: " << vectorToString(pairNumUnsorted(test3, 1, 1)) << "\n";

    return 0;
}