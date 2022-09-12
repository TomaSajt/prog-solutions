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
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> c_mems;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        c_mems.push_back(i);
        dfs(i);
    }
    cout << c_mems.size() - 1 << '\n';
    for (int i = 1; i < c_mems.size(); i++) {
        cout << c_mems[0] << ' ' << c_mems[i] << '\n';
    }

}