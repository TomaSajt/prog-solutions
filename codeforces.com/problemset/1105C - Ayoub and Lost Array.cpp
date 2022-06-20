#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define M 3
using namespace std;
long long DP[200001][M], R[M];
/*
int f(int n, int t) {
    return (n + M - t) / M;
}
*/
int main() {
    speed;
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < M; i++) {
        R[i] = (r + M - i) / M - (l - 1 + M - i) / M;
    }
    DP[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M;k++) {
                DP[i][j] += DP[i - 1][k] * R[(j - k + M) % M];
            }
            DP[i][j] %= 1000000007;
        }
    }
    cout << DP[n][0] << endl;
}