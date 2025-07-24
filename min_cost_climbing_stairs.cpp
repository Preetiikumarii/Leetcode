#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0], prev1 = cost[1];

        for (int i = 2; i < n; ++i) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};

int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    cout << "Minimum cost to reach the top: " << sol.minCostClimbingStairs(cost) << endl;
    return 0;
}
