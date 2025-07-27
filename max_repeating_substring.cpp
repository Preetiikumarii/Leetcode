#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        string repeated = word;

        while (sequence.find(repeated) != string::npos) {
            k++;
            repeated += word;
        }

        return k;
    }
};

int main() {
    Solution sol;
    
    string sequence = "ababcababcababc";
    string word = "ababc";

    cout << "Maximum Repeating Count: " << sol.maxRepeating(sequence, word) << endl;

    return 0;
}
