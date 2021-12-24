#include <bits/stdc++.h>
using namespace std;
int DP[11][3000] = { 1 };
int main() {
    int n, s;
    cin >> n >> s;
    vector<int> coins(s);
    for (int& c : coins) cin >> c;
    for (int i = 1;i <= s;i++) {
        for (int j = 0;j <= n;j++) {
            DP[i][j] = DP[i - 1][j];
            if (j - coins[i - 1] >= 0) {
                DP[i][j] += DP[i][j - coins[i - 1]];
            }
        }
    }
    cout << DP[s][n] << endl;
}