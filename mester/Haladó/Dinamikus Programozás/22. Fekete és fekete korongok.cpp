#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<int> v;
vector<vector<int>> dp;

int solve(int l, int r, bool first) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    if (first) {
        return dp[l][r] = max(solve(l, r - 1, 0) + v[r], solve(l + 1, r, 0) + v[l]);
    }
    return dp[l][r] = min(solve(l, r - 1, 1), solve(l + 1, r, 1));
}

int main() {
    speed;
    int n;
    cin >> n;
    v.resize(n);
    dp.resize(n, vector<int>(n, -1));
    for (auto& a : v) cin >> a;
    cout << solve(0, n - 1, 1) << endl;
}