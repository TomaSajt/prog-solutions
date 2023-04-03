#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g;
vector<int> col;

void dfs(int u) {
    for (int v : g[u]) {
        if (col[v]) {
            if (col[v] == col[u]) {
                cout << "IMPOSSIBLE";
                exit(0);
            }
            continue;
        }
        col[v] = 3 - col[u];
        dfs(v);
    }
}

int main() {
    speed;
    int n, u, v;
    cin >> n >> u;
    g.resize(n + 1);
    col.resize(n + 1);
    while (cin >> u >> v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (col[i]) continue;
        col[i] = 1;
        dfs(i);
    }
    for (int i = 1; i <= n; i++) cout << col[i] << ' ';
}