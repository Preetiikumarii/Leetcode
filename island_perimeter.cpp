#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    if (i + 1 < rows && grid[i + 1][j] == 1) perimeter -= 2; // bottom neighbor
                    if (j + 1 < cols && grid[i][j + 1] == 1) perimeter -= 2; // right neighbor
                }
            }
        }
        return perimeter;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    cout << "Island Perimeter: " << sol.islandPerimeter(grid) << endl;

    return 0;
}
