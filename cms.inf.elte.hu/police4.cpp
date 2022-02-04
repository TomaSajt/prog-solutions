#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;

int DP[10002][10002];

int getwait(int x, int t) {
    x %= (2 * t);
    return x >= t ? 2 * t - x : 0;
}
int main() {
    speed;
    int n, r, t, l;
    cin >> n >> r >> t >> l;
    vector<int> x(n + 2);
    x[0] = 0;
    for (int i = 1;i <= n;i++) {
        cin >> x[i];
    }
    x[n + 1] = l;
    for (int j = 0; j <= r; j++) {
        for (int i = 1; i <= n + 1; i++) {
            int d = x[i] - x[i - 1];
            DP[i][j] = DP[i - 1][j] + d + getwait(DP[i - 1][j], t);
            if (j > 0) {
                DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + d);
            }
        }
    }
    cout << DP[n + 1][r];
}