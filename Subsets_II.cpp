#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue; // Skip duplicates
            current.push_back(nums[i]);
            backtrack(i + 1, nums, current, result);
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> subsets = sol.subsetsWithDup(nums);

    cout << "Subsets with duplicates removed:" << endl;
    for (auto& subset : subsets) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]" << endl;
    }

    return 0;
}
