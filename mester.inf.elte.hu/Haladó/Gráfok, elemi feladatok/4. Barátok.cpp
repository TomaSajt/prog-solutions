// 100/100

#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

vector<vector<int>> g;
vector<vector<int>> groups;
vector<bool> vis;

void dfs(int vertex) {
    vis[vertex] = 1;
    groups.back().pb(vertex);
    for (int nei : g[vertex]) {
        if (vis[nei]) continue;
        dfs(nei);
    }
}

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vis.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        groups.pb({});
        dfs(i);
    }
    cout << groups.size() << '\n';
    for (auto& group : groups) {
        sort(group.begin(), group.end());
        for (int i : group) cout << i << " ";
        cout << '\n';
    }
}