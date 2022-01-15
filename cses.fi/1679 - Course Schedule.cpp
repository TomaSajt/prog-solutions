#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
int n, m, a, b, c = 0;
vector<int> v, e, t;
vector<vector<int>> g;
void dfs(int u) {
    v[u] = 1;
    for (int w : g[u])
        if (!v[w]) dfs(w);
        else if (!e[w]) c = 1;
    e[u] = 1;
    t.pb(u);
}
int main() {
    speed;
    cin >> n >> m;
    g.resize(n + 1), v.resize(n + 1), e.resize(n + 1);
    while (m--) {
        cin >> a >> b;
        g[a].pb(b);
    }
    for (int i = 1; i <= n; i++) if (!v[i]) dfs(i);
    if (c) cout << "IMPOSSIBLE" << endl;
    else {
        reverse(t.begin(), t.end());
        for (int i : t) cout << i << " ";
        cout << endl;
    }
}