#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int n, m;
vector<int> c;
vector<vector<int>> g;
vector<int> vis;

void dfs(int u, int& best) {
    vis[u] = true;
    if (c[u] < best) best = c[u];

    for (auto nei : g[u]) {
        if (!vis[nei]) dfs(nei, best);
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
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll sum = 0;
    for (int i = 1; i <= n;i++) {
        if (vis[i]) continue;
        int best = INT_MAX;
        dfs(i, best);
        sum += best;
    }
    cout << sum;

}