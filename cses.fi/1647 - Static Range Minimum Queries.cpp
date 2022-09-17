#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, a, b;
    cin >> n >> a;
    int l = log2l(n) + 1;
    vector<vector<int>> st(n, vector<int>(l, 0));
    for (int i = 0; i < n; i++) cin >> st[i][0];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (cin >> a >> b) {
        a--, b--;
        int r = b - a + 1;
        int cl = log2l(r);
        int lr = 1 << cl;
        cout << min(st[a][cl], st[b - lr + 1][cl]) << '\n';
    }
}