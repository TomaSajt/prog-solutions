#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll DP[101][2];

int main() {
    int n, m;
    cin >> n >> m;
    DP[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        DP[i][0] = DP[i - 1][1];
        DP[i][1] = DP[i - 1][1] + DP[i - 1][0];
        if (i > m) DP[i][1] -= DP[i - m][0];
    }
    cout << DP[n][0] + DP[n][1] << endl;
}