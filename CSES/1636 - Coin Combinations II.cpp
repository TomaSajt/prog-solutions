#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;

int main() {
    speed;
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1);
    vector<int> cv(n + 1);
    for (int j = 1; j <= n; j++) cin >> cv[j];
    dp[0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i <= x; i++) {
            if (i >= cv[j]) dp[i] = (dp[i] + dp[i - cv[j]]) % mod;
        }
    }
    cout << dp[x];
}

/*
#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;

int main() {
    speed;
    int n, x;
    cin >> n >> x;
    vector<vector<int>> dp(x + 1, vector<int>(n + 1));
    vector<int> cv(n + 1);
    for (int j = 1; j <= n; j++) cin >> cv[j];
    dp[0][0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i <= x; i++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= cv[j]) dp[i][j] = (dp[i][j] + dp[i - cv[j]][j]) % mod;
        }
    }
    cout << dp[x][n];
}
*/