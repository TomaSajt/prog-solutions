#include<bits/stdc++.h>
using namespace std;


int DP[501][501];

int cuts(int a, int b) {
    if (a == b) return 0;
    if (a > b) swap(a, b);
    if (DP[a][b]) return DP[a][b];

    DP[a][b] = INT_MAX;

    for (int i = 1;i <= a / 2;i++) {
        DP[a][b] = min(DP[a][b], cuts(i, b) + cuts(a - i, b));
    }
    for (int j = 1;j <= b / 2;j++) {
        DP[a][b] = min(DP[a][b], cuts(a, j) + cuts(a, b - j));
    }

    return ++DP[a][b];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    cout << cuts(n, m) << endl;
}
