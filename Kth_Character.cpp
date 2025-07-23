#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            string t = "";
            for (int i = 0; i < s.size(); i++) {
                t += char(s[i] + 1);  // Increment character
            }
            s += t;
        }
        return s[k - 1];
    }
};

int main() {
    Solution sol;
    int k = 5;
    cout << "The " << k << "-th character is: " << sol.kthCharacter(k) << endl;
    return 0;
}
