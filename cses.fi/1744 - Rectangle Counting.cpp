#include<bits/stdc++.h>
using namespace std;

int DP[501][501];

int cuts(int a, int b) {
    if (a == b || DP[a][b])
        return DP[a][b];

    DP[a][b] = INT_MAX;
    for (int i = 1;i <= a / 2;i++) {
        int res = cuts(i, b) + cuts(a - i, b);
        DP[a][b] = min(res, DP[a][b]);
    }

    for (int j = 1;j <= b / 2;j++) {
        int res = cuts(a, j) + cuts(a, b - j);
        DP[a][b] = min(res, DP[a][b]);
    }
    return ++DP[a][b];
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << cuts(n, m) << endl;
}


