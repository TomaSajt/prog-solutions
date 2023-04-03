#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g;
vector<bool> vis;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : g[u]) dfs(v);
}

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << (count(vis.begin() + 1, vis.end(), 1) == n && m == n - 1 ? "YES" : "NO");
}