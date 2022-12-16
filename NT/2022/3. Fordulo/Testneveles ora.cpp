#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    vector<int> deps(n + 1);
    while (k--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        deps[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deps[i] == 0) g[0].push_back(i), deps[i]++;
    }
    q.push(0);
    int a = -1, b = -1;
    vector<int> ord;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u != 0) ord.push_back(u);
        vector<int> nexts;
        for (auto v : g[u]) {
            if (--deps[v] == 0) nexts.push_back(v);
        }
        if (a == -1 && nexts.size() > 1) a = nexts[0], b = nexts[1];
        for (auto v : nexts) q.push(v);

    }
    if (count(deps.begin() + 1, deps.end(), 0) != n) {
        cout << '0';
        return 0;
    }
    cout << (b == -1 ? 1 : 2) << '\n';
    for (auto e : ord) cout << e << ' ';
    cout << '\n';
    if (b != -1) {
        for (auto e : ord) cout << (e == a ? b : e == b ? a : e) << ' ';
        cout << '\n';
    }
}