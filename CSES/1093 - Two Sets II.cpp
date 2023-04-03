#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;

int main() {
    speed;
    int n;
    cin >> n;
    int s = n * (n + 1) / 2;
    if (s % 2 == 1) {
        cout << '0';
        return 0;
    }
    int h = s / 2;
    vector<vector<int>> dp(h + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int c = 1; c <= n; c++) {
        for (int i = 0; i <= h; i++) {
            dp[i][c] = dp[i][c - 1];
            if (i >= c) dp[i][c] = (dp[i][c] + dp[i - c][c - 1]) % mod;
        }
    }
    cout << dp[h][n - 1];
    // I don't exatly know why we need n-1 instead of n
    // My theory is that only one of the two sets can have n as its element, so this essentially halves the number of solutions
    // The reason we can't have dp[h][n]/2 is because we're in mod 1e9+7 and division is not easy in modular arithmetic
}