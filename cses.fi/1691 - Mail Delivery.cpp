#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<set<int>> g;
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
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (g[i].size() % 2 == 1 || (!vis[i] && !g[i].empty())) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    stack<int> s;
    vector<int> path;
    s.push(1);
    while (!s.empty()) {
        int cur = s.top(); s.pop();
        while (!g[cur].empty()) {
            int nei = *g[cur].begin();
            g[cur].erase(nei);
            g[nei].erase(cur);
            s.push(cur);
            cur = nei;
        }
        path.push_back(cur);
    }
    for (auto u : path) cout << u << ' ';
}