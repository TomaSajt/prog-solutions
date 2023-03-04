#include <bits/stdc++.h>
using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)

set<int> sol;
vector<int> vis;
vector<vector<int>> g;
int t = 1;

void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v == p || vis[v] == t) continue;
        sol.insert(v);
        if (g[v].size() > 2) continue;
        dfs(v, u);
    }
}

int main() {
    speed;
    int n, m; cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1);
    while (m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            dfs(i, 0);
        }
        t++;
    }
    cout << sol.size() << '\n';
    for (auto i : sol) cout << i << ' ';
    return 0;
}
