#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++;  // Child i is content
            }
            j++;  // Move to the next cookie
        }
        return i;
    }
};

int main() {
    Solution sol;
    vector<int> g = {1, 2, 3};  // Greed factors
    vector<int> s = {1, 1};     // Cookie sizes

    int result = sol.findContentChildren(g, s);
    cout << "Number of content children: " << result << endl;

    return 0;
}
