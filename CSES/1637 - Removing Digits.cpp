#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX / 2);
    dp[n] = 0;
    for (int i = n; i > 0; i--) {
        int j = i;
        while (j > 0) {
            int d = j % 10;
            dp[i - d] = min(dp[i - d], dp[i] + 1);
            j /= 10;
        }
    }
    cout << dp[0];
}