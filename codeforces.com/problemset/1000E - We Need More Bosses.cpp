#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<set<int>> g, gg;
vector<int> d, l, cid, dist;
vector<pair<int, int>> bridges;
vector<bool> vis;
int t = 0;
void dfs(int u, int p) {
    d[u] = l[u] = ++t;
    for (int v : g[u]) {
        if (v == p) continue;
        if (d[v]) {
            l[u] = min(l[u], d[v]);
        }
        else {
            dfs(v, u);
            l[u] = min(l[u], l[v]);
            if (l[v] > d[u]) {
                bridges.push_back({ u,v });
            }
        }
    }
}

void dfs2(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    cid[u] = t;
    for (int v : g[u]) dfs2(v);
}
void dfs3(int u) {
    for (int v : gg[u]) {
        if (vis[v]) continue;
        dist[v] = dist[u] + 1;
        vis[u] = 1;
        dfs3(v);
    }
}

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    g.resize(n + 1), d.resize(n + 1), l.resize(n + 1), cid.resize(n + 1), vis.resize(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v), g[v].insert(u);
    }
    dfs(1, -1);
    for (auto [u, v] : bridges) {
        g[u].erase(v), g[v].erase(u);
    }
    t = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs2(i);
        t++;
    }
    gg.resize(t), vis.assign(t, 0), dist.assign(t, 0);
    for (auto [u, v] : bridges) {
        u = cid[u], v = cid[v];
        gg[u].insert(v), gg[v].insert(u);
    }
    dfs3(0);
    int ind = max_element(dist.begin(), dist.end()) - dist.begin();
    vis.assign(t, 0), dist.assign(t, 0);
    dfs3(ind);
    cout << *max_element(dist.begin(), dist.end());
}