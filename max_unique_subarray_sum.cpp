#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, right = 0, currSum = 0, maxSum = 0;

        while (right < nums.size()) {
            
            if (seen.find(nums[right]) == seen.end()) {
                currSum += nums[right];
                seen.insert(nums[right]);
                maxSum = max(maxSum, currSum);
                right++;
            } else {
               
                currSum -= nums[left];
                seen.erase(nums[left]);
                left++;
            }
        }
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 2, 4, 5, 6};
    cout << "Maximum Unique Subarray Sum: " << sol.maximumUniqueSubarray(nums) << endl;
    return 0;
}
