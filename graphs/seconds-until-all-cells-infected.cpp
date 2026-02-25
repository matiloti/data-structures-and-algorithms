using namespace std;
#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using Matrix = vector<vector<int>>;
using Coord = pair<int,int>;

bool outOfBoundaries(Matrix& m, Coord& coord) {
    return coord.first < 0 || coord.first > m.size() - 1 || coord.second < 0 || coord.second > m[0].size() - 1;
}

bool isExplored(set<Coord>& explored, Coord& curr) {
    return explored.count(curr) > 0;
}

int countInfections(Matrix& m, Coord& curr, set<Coord>& explored) {
    // only can be 2 when it comes from parent
    if(outOfBoundaries(m, curr) || isExplored(explored, curr)) return 0;
    if(m[curr.first][curr.second] == 0) {
        explored.insert(curr); // explored
        return 0;
    }
    vector<Coord> points = {{0,-1},{1,0},{0,1},{-1,0}};
    int infectedCells = 1;
    for(Coord point : points) {
        Coord coord = {
            curr.first + point.first, 
            curr.second + point.second
        };
        if(m[coord.first][coord.second] == 2) continue; // count each infected cell propagation separately
        infectedCells += countInfections(
            m,  
            coord,
            explored
        );
    }
    m[curr.first][curr.second] = 2; // infected!
    explored.insert(curr); // explored
    return infectedCells;
}

// Each second an uninfected cell (1) becomes infected by its adjacent infected cells (2)
// if imposible return -1
int numberOfSecondsUntilAllCellsInfected(Matrix& m) {
    set<Coord> explored;
    int maxSeconds = 0;
    for(int x = 0; x < m.size(); x++) {
        for(int y = 0; y < m[x].size(); y++) {
            Coord coord = {x,y};
            if(!isExplored(explored, coord) && m[coord.first][coord.second] == 2) {
                maxSeconds = max(countInfections(m, coord, explored), maxSeconds);
            }
        }
    }
    
    for(int x = 0; x < m.size(); x++) {
        for(int y = 0; y < m[x].size(); y++) {
            Coord coord = {x,y};
            if(m[coord.first][coord.second] == 1) {
                return -1;
            }
        }
    }
    
    return maxSeconds;
}

int main()
{
    Matrix m = {
        {1,1,0,0},
        {1,1,0,0},
        {0,0,1,1},
        {0,0,0,2}
    };
    
    cout<<numberOfSecondsUntilAllCellsInfected(m)<<endl;

    return 0;
}