#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g;
vector<int> dist;
int m = INT_MAX;
void dfs(int u) {
    if (g[u].empty()) {
        m = min(m, dist[u]);
    }
    for (auto v : g[u]) {
        dist[v] = dist[u] + 1;
        dfs(v);
    }
}

int main() {
    speed;
    int n;
    cin >> n;
    g.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        int u; cin >> u;
        g[u].push_back(i);
    }
    dist[1] = 1;
    dfs(1);
    cout << m << '\n';
    for (int i = 1; i <= n; i++) {
        cout << min(m, dist[i]) << ' ';
    }
}