
#include <bits/stdc++.h>

long long DP[100001];
using namespace std;
int main() {
    int N, W;
    cin >> N >> W;
    vector<long long> w(N + 1), v(N + 1);
    vector<long long> DP(100001, LLONG_MAX / 2);
    DP[0] = 0;
    for (int i = 1; i <= N; i++) cin >> w[i] >> v[i];
    for (int j = 1; j <= N; j++) {
        for (int i = 100000; i >= 0; i--) {
            if (i >= v[j]) {
                DP[i] = min(DP[i], DP[i - v[j]] + w[j]);
            }
        }
    }
    long long a = -1;
    for (int i = 100000;i >= 0;i--) {
        if (DP[i] <= W) {
            a = i;
        }
    }
    for (int i = 0;i <= 140;i++) {
        cout << DP[i] << ' ';
    }
    cout << endl;
    cout << a << endl;
    return 0;
}
