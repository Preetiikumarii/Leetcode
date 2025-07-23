#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            for (char &c : s) {
                if (c == 'a') c = 'b';
                else if (c == 'b') c = 'a';
            }
        }

        int score = 0;
        stack<char> st;

        // First pass: remove "ab"
        for (char c : s) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                score += x;
            } else {
                st.push(c);
            }
        }

        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        // Second pass: remove "ba"
        for (char c : remaining) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                score += y;
            } else {
                st.push(c);
            }
        }

        return score;
    }
};

int main() {
    Solution sol;

    string s = "cdbcbbaaabab";
    int x = 4, y = 5;

    int result = sol.maximumGain(s, x, y);
    cout << "Maximum Score: " << result << endl;

    return 0;
}
