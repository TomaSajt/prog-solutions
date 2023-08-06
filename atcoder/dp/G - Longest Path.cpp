#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<int> DP;

void dfs(int u) {
    vis[u] = 1;
    for (int& v : g[u]) {
        if (!vis[v]) dfs(v);
        DP[u] = max(DP[u], DP[v] + 1);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1);
    DP.resize(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    cout << *max_element(DP.begin(), DP.end()) << endl;
    return 0;
}
