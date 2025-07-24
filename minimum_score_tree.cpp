#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <functional>

using namespace std;

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> xr(n), in(n), out(n);
        int t = 0;

        function<void(int,int)> dfs = [&](int u, int p){
            in[u] = ++t;
            xr[u] = nums[u];
            for (int v : g[u]) {
                if (v == p) continue;
                dfs(v, u);
                xr[u] ^= xr[v];
            }
            out[u] = t;
        };

        dfs(0, -1);

        auto isAnc = [&](int u, int v){
            return in[u] < in[v] && in[v] <= out[u];
        };

        int ans = INT_MAX;

        for (int i = 1; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int x, y, z;
                if (isAnc(i, j)) {
                    x = xr[j];
                    y = xr[i] ^ xr[j];
                    z = xr[0] ^ xr[i];
                } else if (isAnc(j, i)) {
                    x = xr[i];
                    y = xr[j] ^ xr[i];
                    z = xr[0] ^ xr[j];
                } else {
                    x = xr[i];
                    y = xr[j];
                    z = xr[0] ^ xr[i] ^ xr[j];
                }
                int mx = max({x, y, z});
                int mn = min({x, y, z});
                ans = min(ans, mx - mn);
                if (ans == 0) return 0;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 5, 4, 11};
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {1, 3}, {3, 4}
    };

    int result = sol.minimumScore(nums, edges);
    cout << "Minimum score: " << result << endl;
    return 0;
}
