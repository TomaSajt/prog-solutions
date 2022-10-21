#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<set<int>> g;
vector<int> d, l, cid, dist;
set<pair<int, int>> bridges;
vector<bool> vis;
vector<int> csize;
map<pair<int, int>, int> eimap;
vector<pair<int, int>> sol;
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
                bridges.insert({ u,v });
                bridges.insert({ v,u });
            }
        }
    }
}

void dfs2(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    cid[u] = t;
    csize[t]++;
    for (int v : g[u]) {
        if (bridges.count({ u,v })) continue;
        dfs2(v);
    }
}
void dfs3(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : g[u]) {
        int i = eimap[{u, v}];
        if (sol[i].first == -1) sol[i] = { v,u };
        dfs3(v);
    }
}

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    g.resize(n + 1), d.resize(n + 1), l.resize(n + 1), cid.resize(n + 1), vis.resize(n + 1), sol.resize(m, { -1,-1 });
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        eimap[{u, v}] = i;
        eimap[{v, u}] = i;
        g[u].insert(v), g[v].insert(u);
    }
    dfs(1, -1);
    t = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        csize.emplace_back();
        dfs2(i);
        t++;
    }
    vis.assign(n + 1, 0);
    int bestComp = max_element(csize.begin(), csize.end()) - csize.begin();
    int bestInd = find(cid.begin() + 1, cid.end(), bestComp) - cid.begin();
    dfs3(bestInd);
    cout << csize[bestComp] << '\n';
    for (auto [u, v] : sol) cout << u << ' ' << v << '\n';
}