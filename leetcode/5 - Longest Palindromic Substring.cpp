#include <bits/stdc++.h>
using namespace std;

class Solution {
    int bestL;
    int bestR;
    void expand(string& s, int l, int r) {
        while (r < s.size() && l >= 0 && s[r] == s[l]) r++, l--;
        r--, l++;
        if (r - l > bestR - bestL) {
            bestR = r;
            bestL = l;
        }
    }
public:
    string longestPalindrome(string s) {
        bestL = bestR = 0;
        for (int i = 0; i < s.size(); i++) {
            expand(s, i - 1, i + 1);
            if (i < s.size() - 1 && s[i] == s[i + 1]) expand(s, i - 1, i + 2);
        }
        return s.substr(bestL, bestR - bestL + 1);
    }
};

int main() {
    string str;
    Solution s;
    while (cin >> str) {
        cout << s.longestPalindrome(str) << endl;
    }
}