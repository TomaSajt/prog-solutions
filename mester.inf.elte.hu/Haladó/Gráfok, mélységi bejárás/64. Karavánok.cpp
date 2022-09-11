#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g, gt;
vector<int> ord, sol;
vector<bool> vis;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : g[u]) dfs(v);
    ord.push_back(u);
}

void dfs2(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : g[u]) dfs2(v);
}

void dfs3(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    sol.push_back(u);
    for (int v : gt[u]) dfs3(v);
}

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    gt.resize(n + 1);
    vis.resize(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) dfs(i);
    vis.assign(n + 1, 0);
    dfs2(ord.back());
    if(count(vis.begin(), vis.end(), 1) != n) {
        cout << "-1\n";
        return 0;
    }
    vis.assign(n + 1, 0);
    dfs3(ord.back());
    sort(sol.begin(), sol.end());
    for (int u : sol) cout << u << ' ';
    cout << '\n';
}