#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g;
vector<int> d, l;
vector<pair<int, int>> res;
int t = 0;
void dfs(int u, int prev) {
    d[u] = l[u] = ++t;
    for (int v : g[u]) {
        if (v == prev) continue;
        if (d[v]) {
            l[u] = min(l[u], d[v]);
        }
        else {
            dfs(v, u);
            l[u] = min(l[u], l[v]);
            if (l[v] > d[u]) {
                res.push_back(minmax(u, v));
            }
        }
    }
}

int main() {
    speed;
    int n, m, i = 1;
    for (cin >> n; cin >> n >> m; i++) {
        t = 0;
        res.clear();
        g.assign(n + 1, {});
        d.assign(n + 1, 0);
        l.assign(n + 1, 0);
        while (m--) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, -1);
        cout << "Caso #" << i << '\n';
        if (res.empty()) {
            cout << "Sin bloqueos\n";
            continue;
        }
        cout << res.size() << '\n';
        sort(res.begin(), res.end());
        for (auto [u, v] : res) cout << u << ' ' << v << '\n';
    }
}