#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> kinds;
        for (int candy : candyType) {
            kinds.insert(candy);
        }
        return min((int)kinds.size(), (int)candyType.size() / 2);
    }
};

int main() {
    vector<int> candyType = {1, 1, 2, 2, 3, 3};
    Solution sol;
    cout << sol.distributeCandies(candyType) << endl; // Output: 3
    return 0;
}
