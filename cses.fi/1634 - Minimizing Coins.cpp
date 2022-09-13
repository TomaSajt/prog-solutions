#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
#define BIG (INT_MAX / 2)


int main() {
    speed;
    int n, x;
    cin >> n >> x;
    vector<int> dp(x + 1, BIG), cv(n);
    for (auto& c : cv) cin >> c;
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int c : cv) {
            if (c <= i) dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    cout << (dp[x] < BIG ? dp[x] : -1);
}