#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(2 * n);
    vector<int> deps(2 * n), pos(2 * n);
    auto makeEdge = [&](int u, int v) { g[u].push_back(v); deps[v]++; };
    for (int i = 0; i < n; i++) makeEdge(2 * i, 2 * i + 1);
    while (m--) {
        int t, a, b;
        cin >> t >> a >> b; --a, --b;
        if (t == 1) makeEdge(2 * b, 2 * a + 1), makeEdge(2 * a, 2 * b + 1);
        else makeEdge(2 * a + 1, 2 * b);
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deps[2 * i] == 0) q.push(2 * i);
    }
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        pos[u] = ++cnt;
        for (int v : g[u]) {
            if (--deps[v] == 0) q.push(v);
        }
    }
    if (cnt == 2 * n) {
        cout << "IGEN";
        for (int i = 0; i < n; i++) cout << '\n' << pos[2 * i] << ' ' << pos[2 * i + 1];
    }
    else cout << "NEM";
}