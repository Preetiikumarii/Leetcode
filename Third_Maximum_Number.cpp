#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());  // Remove duplicates
        vector<int> unique(s.begin(), s.end()); 
        sort(unique.begin(), unique.end(), greater<int>());  // Sort descending
        return unique.size() >= 3 ? unique[2] : unique[0];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 1};

    int result = sol.thirdMax(nums);
    cout << "Third Maximum Number: " << result << endl;

    return 0;
}
