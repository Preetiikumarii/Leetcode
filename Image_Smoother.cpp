#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int sum = 0, count = 0;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        int x = i + dx, y = j + dy;
                        if (x >= 0 && x < m && y >= 0 && y < n) {
                            sum += img[x][y];
                            count++;
                        }
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> img = {
        {100, 200, 100},
        {200, 50, 200},
        {100, 200, 100}
    };

    Solution sol;
    vector<vector<int>> result = sol.imageSmoother(img);

    for (auto row : result) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}
