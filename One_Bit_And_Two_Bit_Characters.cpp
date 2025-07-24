#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size() - 1) {
            if (bits[i] == 1)
                i += 2;
            else
                i += 1;
        }
        return i == bits.size() - 1;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> bits = {1, 0, 0};

    // Function call
    bool result = sol.isOneBitCharacter(bits);

    // Output result
    cout << (result ? "True" : "False") << endl;

    return 0;
}
