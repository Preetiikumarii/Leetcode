#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1, right = num; // Initialize right to num
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            if (square == num)
                return true;
            else if (square < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

int main() {
    Solution sol;
    int num = 16;

    if (sol.isPerfectSquare(num))
        cout << num << " is a perfect square." << endl;
    else
        cout << num << " is NOT a perfect square." << endl;

    return 0;
}
