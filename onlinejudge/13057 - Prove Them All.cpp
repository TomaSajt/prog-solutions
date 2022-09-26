#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<int> vis;
vector<vector<int>> g, gt;
vector<int> ord;
vector<int> ids;
vector<bool> cnd_0deg;

int id = 0;
void dfs1(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : g[u]) dfs1(v);
    ord.push_back(u);
}

void dfs2(int u) {
    if (vis[u]) {
        if (ids[u] != id) cnd_0deg[id] = 0;
        return;
    }
    ids[u] = id;
    vis[u] = 1;
    for (int v : gt[u]) dfs2(v);
}

int main() {
    speed;
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        int n, m;
        cin >> n >> m;
        id = 0;
        vis.assign(n + 1, 0);
        ids.assign(n + 1, -1);
        g.assign(n + 1, {});
        gt.assign(n + 1, {});
        ord.clear();
        cnd_0deg.clear();
        while (m--) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            gt[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) dfs1(i);
        reverse(ord.begin(), ord.end());
        vis.assign(n + 1, 0);
        for (int u : ord) {
            if (vis[u]) continue;
            cnd_0deg.push_back(1);
            dfs2(u);
            id++;
        }
        int c = 0;
        for (int i = 0; i < id; i++) {
            if (cnd_0deg[i]) c++;
        }
        cout << "Case " << k << ": " << c << '\n';
    }
}