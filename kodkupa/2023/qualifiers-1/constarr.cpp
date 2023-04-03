// 35/100
#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main() {
    speed;
    int n, l, r, m, k;
    cin >> n >> m >> l >> r >> k;
    vector<vector<long long>> DP(n + 1, vector<long long>(m, 0));
    vector<long long> R(m);
    for (int i = 0; i < m; i++) {
        R[i] = (r + m - i) / m - (l - 1 + m - i) / m;
    }
    DP[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                DP[i][j] += DP[i - 1][k] * R[(j - k + m) % m];
            }
            DP[i][j] %= 1000000007;
        }
    }
    cout << DP[n][k] << endl;
}