using namespace std;

#include <iostream>
#include <utility>
#include <cstddef>
#include <unordered_map>
#include <set>
#include <vector>
#include <string>

bool validSudoku(vector<vector<int>>& matrix) {
    unordered_map<int, set<int>> rows = unordered_map<int, set<int>>();
    unordered_map<int, set<int>> cols = unordered_map<int, set<int>>();

    for(int row = 0; row < 9; row += 3) {
        for(int col = 0; col < 9; col += 3) { // O(n)
            set<int> visited = set<int>();
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    int currRow = row + i;
                    int currCol = col + j;
                    int element = matrix[currRow][currCol];

                    if(element == 0) continue;
                    
                    if(visited.count(element) > 0) return false; // O(1)
                    if(rows[currRow].count(element) + cols[currCol].count(element) > 0) { // O(1)
                        return false; // repeated element in col/row
                    }

                    visited.insert(element);
                    rows[currRow].insert(element); // row
                    cols[currCol].insert(element); // col
                }
            }
            cout << endl;
        }
    }
    return true;
}


int main() {
    vector<vector<int>> matrix = {
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 0},
        {4, 0, 0, 0, 0, 0, 0, 0, 0},
        {5, 0, 0, 0, 0, 0, 0, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {9, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    cout << validSudoku(matrix) << endl;
    return 0;
}