#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g;
vector<int> d, l;
stack<int> s;
vector<bool> ons;
int t = 0, c = 0;
vector<int> cmap;

void dfs(int u) {
    d[u] = l[u] = ++t;
    s.push(u);
    ons[u] = 1;
    for (int v : g[u]) {
        if (!d[v]) {
            dfs(v);
            l[u] = min(l[u], l[v]);
        }
        else if (ons[v]) {
            l[u] = min(l[u], d[v]);
        }
    }
    if (d[u] == l[u]) {
        c++;
        while (1) {
            int v = s.top();
            s.pop();
            ons[v] = 0;
            cmap[v] = c;
            if (v == u) break;
        }
    }
}

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    d.resize(n + 1);
    l.resize(n + 1);
    ons.resize(n + 1);
    cmap.resize(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (d[i]) continue;
        dfs(i);
    }
    cout << c << '\n';
    for (int i = 1; i <= n; i++) cout << cmap[i] << ' ';
}