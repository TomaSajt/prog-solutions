#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;

int main() {
    speed;
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1), cv(n);
    for (auto& c : cv) cin >> c;
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int c : cv) {
            if (c <= i) dp[i] = (dp[i] + dp[i - c]) % mod;
        }
    }
    cout << dp[x];
}