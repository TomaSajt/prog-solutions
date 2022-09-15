#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].size() % 2 == 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    stack<int> s;
    vector<int> path;
    s.push(1);
    while (!s.empty()) {
        int cur = s.top(); s.pop();
        while (!g[cur].empty()) {
            int nei = *g[cur].begin();
            g[cur].erase(nei);
            g[nei].erase(cur);
            s.push(cur);
            cur = nei;
        }
        path.push_back(cur);
    }
    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (auto u : path) cout << u << ' ';
}