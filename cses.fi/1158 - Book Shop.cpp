#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1);
    vector<int> v(n + 1), w(n + 1);
    for (int j = 1; j <= n; j++) cin >> w[j];
    for (int j = 1; j <= n; j++) cin >> v[j];
    for (int j = 1; j <= n; j++) {
        for (int i = x; i >= 0; i--) {
            if (i >= w[j]) dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
        }
    }
    cout << dp[x];
}

/*
#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, x;
    cin >> n >> x;
    vector<vector<int>> dp(x + 1, vector<int>(n + 1));
    vector<int> v(n + 1), w(n + 1);
    for (int j = 1; j <= n; j++) cin >> w[j];
    for (int j = 1; j <= n; j++) cin >> v[j];
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i <= x; i++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= w[j]) dp[i][j] = max(dp[i][j], dp[i - w[j]][j - 1] + v[j]);
        }
    }
    cout << dp[x][n];
}*/