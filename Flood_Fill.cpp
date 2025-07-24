#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int original) {
        int m = image.size(), n = image[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != original)
            return;

        image[r][c] = color;

        dfs(image, r + 1, c, color, original);
        dfs(image, r - 1, c, color, original);
        dfs(image, r, c + 1, color, original);
        dfs(image, r, c - 1, color, original);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if (original != color)
            dfs(image, sr, sc, color, original);
        return image;
    }
};

int main() {
    Solution sol;

    // Sample input image
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    cout << "Flood filled image:\n";
    for (const auto& row : result) {
        for (int pixel : row)
            cout << pixel << " ";
        cout << endl;
    }

    return 0;
}
