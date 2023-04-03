#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int n, m, best;
vector<int> c;
vector<vector<int>> g;
vector<bool> vis;

void dfs(int u) {
    vis[u] = 1;
    if (c[u] < best) best = c[u];
    for (int nei : g[u]) {
        if (!vis[nei]) dfs(nei);
    }
}

int main() {
    speed;
    cin >> n >> m;
    c.resize(n + 1);
    g.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> c[i];
    while (m--) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll sum = 0;
    for (int i = 1; i <= n;i++) {
        if (vis[i]) continue;
        best = INT_MAX;
        dfs(i);
        sum += best;
    }
    cout << sum;
}