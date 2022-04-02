#include <bits/stdc++.h>

long long DP[100001];
using namespace std;
int main() {
    int N, W;
    cin >> N >> W;
    vector<long long> w(N + 1), v(N + 1);
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];
    for (int j = 1; j <= N; j++) {
        for (int i = W; i >= 0; i--) {
            if (i >= w[j]) {
                DP[i] = max(DP[i], DP[i - w[j]] + v[j]);
            }
        }
    }
    cout << DP[W] << endl;
    return 0;
}