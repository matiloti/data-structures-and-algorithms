using namespace std;

#include <iostream>
#include <vector>
#include <set>

void zeroStripping(vector<vector<int>>& matrix) {
    set<int> rows = set<int>();
    set<int> cols = set<int>();

    for(int currRow = 0; currRow < matrix.size(); currRow++) {
        for(int currCol = 0; currCol < matrix[currRow].size(); currCol++) {
            int currElement = matrix[currRow][currCol];
            if(currElement == 0) {
                rows.insert(currRow);
                cols.insert(currCol);
            }
        }
    }

    for(int currRow = 0; currRow < matrix.size(); currRow++) {
        for(int currCol = 0; currCol < matrix[currRow].size(); currCol++) {
            int currElement = matrix[currRow][currCol];
            if(currElement != 0 && (rows.count(currRow) + cols.count(currCol)) > 0) {
                matrix[currRow][currCol] = 0;
            } else {
                matrix[currRow][currCol] = currElement;
            }
        }
    }
}

void printResult(vector<vector<int>>& result) {
    for(int currRow = 0; currRow < result.size(); currRow++) {
        for(int currCol = 0; currCol < result[currRow].size(); currCol++) {
            int currElement = result[currRow][currCol];
            cout << currElement << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> test = {
        {1, 1, 0, 2},
        {3, 2, 4, 5},
        {0, 3, 6, 7},
        {1, 3, 6, 7},
        {1, 3, 6, 7},
    };

    zeroStripping(test);
    
    printResult(test);

    return 0;
}