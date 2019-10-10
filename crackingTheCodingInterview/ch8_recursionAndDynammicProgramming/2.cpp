/*
  Chapter 8 (Recursion and Dynamyic Programming) Problem 2
*/
#include <iostream>
#include <vector>
#include <utility>


typedef std::pair<int, int> positionType;
typedef std::vector<std::vector<int>> gridType;


// --method that returns true if the iPos passed, is inside the grid
bool checkInsideGrid (const gridType& grid, const positionType iPos) {
    if ((iPos.first  >= 0) &&
        (iPos.first < grid.size()) &&
        (iPos.second >= 0) &&
        (iPos.second < grid[0].size()))
        return true;
    return false;
}

// --method that that returns true if there's a sol1 from top left corner to bottom right
bool sol1 (gridType& grid, const positionType iPos) {
    bool reached = false;

    //if we are already in the bottom right position, marked by a 2, we reached destination
    if (grid[iPos.first][iPos.second] == 2) reached = true;
    //if the current position is an obstacle or we already visited
    else if (grid[iPos.first][iPos.second] != 0) return false; //we can't go from this sol1 (there's an obstacle or we already visited)

    //we mark the current position as visited
    if (!reached)  //we don't want to change the de
        grid[iPos.first][iPos.second] = 3;

    //we will try to go to all directions
    if (!reached && checkInsideGrid(grid, std::make_pair(iPos.first, iPos.second + 1)))       // Go right
        reached = sol1(grid, std::make_pair(iPos.first, iPos.second + 1));

    if (!reached && checkInsideGrid(grid, std::make_pair(iPos.first - 1, iPos.second)))       //Go down
        reached = sol1(grid, std::make_pair(iPos.first - 1, iPos.second));

    if (!reached && checkInsideGrid(grid, std::make_pair(iPos.first + 1, iPos.second)))       // Go up
        reached = sol1(grid, std::make_pair(iPos.first + 1, iPos.second));

    if (!reached && checkInsideGrid(grid, std::make_pair(iPos.first, iPos.second - 1)))       // Go left
        reached = sol1(grid, std::make_pair(iPos.first, iPos.second - 1));

    //we print the path that made us reach bottom right
    if (reached) {
        std::cout << "(" << iPos.first << "," << iPos.second << ")  ";
    }
    //we unmark the visit of the current node in the grid to keep it 'clean'
    grid[iPos.first][iPos.second] = 0;

    return reached;
}

int main() {
    gridType grid = {{0, 0, 0, 0, 0, 0},
                     {0, 1, 1, 0, 1, 1},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 1, 0, 1, 0},
                     {1, 1, 0, 0, 1, 1},
                     {0, 0, 0, 0, 0, 2}};
    std::cout << "we are able to find the goal ? " << sol1(grid, std::make_pair(0, 0)) << std::endl;
}
