#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        unsigned int n = x, rev = 0;
        do rev = rev * 10 + n % 10; while (n/=10);
        return rev == x;
    }
};

int main() {
    int n;
    Solution s;
    while (cin >> n) {
        cout << s.isPalindrome(n) << endl;
    }
}