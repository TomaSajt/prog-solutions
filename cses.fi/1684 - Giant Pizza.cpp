#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g, gt, comps, scc;
vector<int> ord, cid;
vector<bool> vis;
int t = 0;

void dfs1(vector<vector<int>>& gr, int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : gr[u]) dfs1(gr, v);
    ord.push_back(u);
}

void dfs2(int u) {
    if (vis[u]) {
        if (cid[u] != t) scc[cid[u]].push_back(t);
        return;
    }
    vis[u] = 1;
    cid[u] = t;
    comps[t].push_back(u);
    for (int v : gt[u]) dfs2(v);
}

int main() {
    speed;
    int n, m;
    cin >> m >> n;
    g.resize(2 * n);
    gt.resize(2 * n);
    vis.resize(2 * n);
    cid.resize(2 * n);
    while (m--) {
        char su, sv; int u, v;
        cin >> su >> u >> sv >> v;
        u = 2 * u - 2 + (su == '-');
        v = 2 * v - 2 + (sv == '-');
        g[u ^ 1].push_back(v);
        g[v ^ 1].push_back(u);
        gt[v].push_back(u ^ 1);
        gt[u].push_back(v ^ 1);
    }
    for (int i = 0; i < 2 * n; i++) dfs1(g, i);
    reverse(ord.begin(), ord.end());
    vis.assign(2 * n, 0);
    for (int u : ord) {
        if (!vis[u]) {
            comps.emplace_back();
            scc.emplace_back();
            dfs2(u);
            t++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (cid[2 * i] == cid[2 * i + 1]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    ord.clear();
    vis.assign(t, 0);
    for (int i = 0; i < t; i++) dfs1(scc, i);
    vis.assign(n, 0);
    vector<char> res(n);
    for (int a : ord) {
        for (int u : comps[a]) {
            int i = u / 2;
            if (vis[i]) continue;
            res[i] = "+-"[u & 1];
            vis[i] = 1;
        }
    }
    for (char r : res) cout << r << ' ';
}