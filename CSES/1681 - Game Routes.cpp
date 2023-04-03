#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;
vector<vector<int>> g, gt;
vector<bool> vis;
vector<int> ord;
void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : g[u]) dfs(v);
    ord.push_back(u);
}

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<int> ways(n + 1);
    ways[1] = 1;
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
    reverse(ord.begin(), ord.end());
    for (int u : ord) {
        for (int v : gt[u]) ways[u] = (ways[u] + ways[v]) % mod;
    }
    cout << ways[n];
}