#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;

int main() {
    speed;
    int n; cin >> n;
    vector<vector<int>> canPair(n, vector<int>(n));
    for (auto& row : canPair) for (auto& a : row) cin >> a;
    vector<vector<int>> dp(n + 1, vector<int>(1 << n));
    dp[0][0] = 1;
    for (int currentMan = 0; currentMan < n; currentMan++) {
        for (int currentWoman = 0; currentWoman < n; currentWoman++) {
            if (!canPair[currentMan][currentWoman]) continue;
            for (int womanSet = 0; womanSet < (1 << n); womanSet++) {
                if (!(womanSet & (1 << currentWoman))) continue;
                dp[currentMan + 1][womanSet] += dp[currentMan][womanSet ^ (1 << currentWoman)];
                dp[currentMan + 1][womanSet] %= mod;
            }
        }
    }
    cout << dp[n].back();
}