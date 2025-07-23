#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num))
                return num;
            seen.insert(num);
        }
        return -1; // This line is theoretically never reached
    }
};

int main() {
    vector<int> nums = {5, 1, 5, 2, 5, 3, 5, 4};
    Solution sol;
    cout << sol.repeatedNTimes(nums) << endl;  // Output: 5
    return 0;
}
