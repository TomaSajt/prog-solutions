#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;

int main() {
    speed;
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && j <= i; j++) {
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    cout << dp[n];
}