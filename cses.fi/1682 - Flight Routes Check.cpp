#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g, gt;
vector<bool> vis;
int last;

void dfs1(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : g[u]) dfs1(v);
    last = u;
}

void dfs2(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : gt[u]) dfs2(v);
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
    for (int i = 1; i <= n; i++) dfs1(i);
    vis.assign(n + 1, 0);
    dfs2(last);
    int a = find(vis.begin() + 1, vis.end(), 0) - vis.begin();
    if (a == n + 1) cout << "YES";
    else cout << "NO\n" << a << ' ' << last;
}