#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(5000, vector<int>(5000, -1));
int solve(const string& a, const string& b, int i, int j) {
    if (i == a.size()) return b.size() - j;
    if (j == b.size()) return a.size() - i;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i] == b[j]) return dp[i][j] = solve(a, b, i + 1, j + 1);
    return dp[i][j] = min({ solve(a, b, i + 1, j), solve(a, b, i, j + 1),solve(a, b, i + 1, j + 1) }) + 1;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << solve(a, b, 0, 0);
}