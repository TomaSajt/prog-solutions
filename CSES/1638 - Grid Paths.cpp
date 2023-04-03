#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    speed;
    int n;
    char c;
    cin >> n;
    vector<vector<bool>> board(n + 1, vector<bool>(n + 1, false));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> c;
            board[i][j] = c == '.';
        }
    }
    if (!board[1][1] || !board[n][n]) {
        cout << "0\n";
        return 0;
    }
    dp[1][1] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (board[i][j] && !(i == 1 && j == 1)) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n][n] << endl;
}