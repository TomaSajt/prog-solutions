#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
long long DP[2002][2001];
int main() {
    speed;
    int n, m, k;
    cin >> n >> m >> k;
    DP[1][0] = m;
    for (int j = 0; j <= k; j++) {
        for (int i = 2; i <= n; i++) {
            DP[i][j] = DP[i - 1][j];
            if (j != 0) DP[i][j] += DP[i - 1][j - 1] * (m - 1);
            DP[i][j] %= 998244353;
        }
    }
    cout << DP[n][k];
}