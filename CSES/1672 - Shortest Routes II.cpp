#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;
#define BIG (LLONG_MAX / 2)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q, u, v;
    ll w;
    cin >> n >> m >> q;
    vector<vector<ll>> g(n + 1, vector<ll>(n + 1, BIG));
    while (m--) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    for (int i = 1; i <= n;i++) {
        g[i][i] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n;j++) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    while (cin >> u >> v) {
        cout << (g[u][v] == BIG ? -1ll : g[u][v]) << endl;
    }
}