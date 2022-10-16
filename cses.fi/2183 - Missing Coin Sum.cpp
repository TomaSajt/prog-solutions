#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    vector<long long> v(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v.begin() + 1, v.end());
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[i - 1] < v[i]) {
            cout << dp[i - 1];
            return 0;
        }
        dp[i] = dp[i - 1] + v[i];
    }
    cout << dp[n];
}