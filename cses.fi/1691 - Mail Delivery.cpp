#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int n, m;
vector<set<int>> g;
vector<bool> vis;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : g[u]) dfs(v);
}

int main() {
    speed;
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
        if (g[i].size() % 2 == 1 || (!vis[i] && g[i].size() > 0)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    stack<int> s;
    vector<int> path;
    int cur = 1;
    while (!s.empty() || g[cur].size() > 0) {
        if (g[cur].size() == 0) {
            path.push_back(cur);
            cur = s.top();
            s.pop();
        }
        else {
            s.push(cur);
            int v = *g[cur].begin();
            g[cur].erase(v);
            g[v].erase(cur);
            cur = v;
        }
    }
    for (auto u : path) cout << u << ' ';
    cout << cur << endl;
}