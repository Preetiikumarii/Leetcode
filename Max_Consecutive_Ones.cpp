#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxCount = 0;

        for (int num : nums) {
            if (num == 1) {
                count++;
                maxCount = max(maxCount, count);
            } else {
                count = 0;
            }
        }
        return maxCount;
    }
};

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    Solution sol;
    cout << sol.findMaxConsecutiveOnes(nums) << endl;  // Output: 3
    return 0;
}
