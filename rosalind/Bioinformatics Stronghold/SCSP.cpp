#include "../_helpers.hpp"

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = a[i - 1] == b[j - 1] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    stack<char> s;
    for (int i = n, j = m; i != 0 || j != 0;) {
        if (i == 0) j--, s.push(b[j]);
        else if (j == 0) i--, s.push(a[i]);
        else if (a[i - 1] == b[j - 1]) i--, j--, s.push(a[i]);
        else if (dp[i][j] == dp[i - 1][j]) i--, s.push(a[i]);
        else j--, s.push(b[j]);
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}