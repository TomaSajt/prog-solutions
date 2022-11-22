#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n; cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i >= 2) dp[i] += 2 * dp[i - 2];
        if (i >= 3) dp[i] += 2 * dp[i - 3];
        dp[i] %= 20210108;
    }
    cout << dp[n];
}