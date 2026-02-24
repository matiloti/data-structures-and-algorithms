using namespace std;
#include <iostream>
#include <vector>
#include <set>
#include <utility>

using Matrix = vector<vector<int>>;
using Coord = pair<int,int>;

bool outOfBoundaries(Matrix& m, Coord& coord) {
    return coord.first < 0 || coord.first > m.size() - 1 || coord.second < 0 || coord.second > m[0].size() - 1;
}

bool isExplored(set<Coord>& explored, Coord& curr) {
    return explored.count(curr) > 0;
}

void exploreIsland(Matrix& m, set<Coord>& explored, Coord& curr) {
    if(outOfBoundaries(m, curr) || isExplored(explored, curr)) return;
    explored.insert(curr);
    if(m[curr.first][curr.second] == 0) return;
    vector<Coord> points = {{0,-1},{1,0},{0,1},{-1,0}};
    for(Coord point : points) {
        Coord coord = {
            curr.first + point.first, 
            curr.second + point.second
        };
        exploreIsland(
            m, 
            explored, 
            coord
        );
    }
}

int numberOfIslands(Matrix& m) {
    set<Coord> explored;
    int nIslands = 0;
    for(int x = 0; x < m.size(); x++) {
        for(int y = 0; y < m[x].size(); y++) {
            Coord coord = {x,y};
            if(!isExplored(explored, coord) && m[coord.first][coord.second] == 1) {
                exploreIsland(m, explored, coord);
                nIslands++;
            }
        }
    }
    return nIslands;
}

int main()
{
    Matrix m = {
        {1,1,0,0},
        {1,1,0,0},
        {0,0,1,1},
        {0,0,0,1}
    };
    
    cout<<numberOfIslands(m)<<endl;

    return 0;
}