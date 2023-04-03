#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> par(n + 1, -1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    par[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == n) break;
        for (int v : g[u]) {
            if (par[v] == -1) {
                par[v] = u;
                q.push(v);
            }
        }
    }
    if (par[n] == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    stack<int> path;
    for (int curr = n; curr != 0; curr = par[curr]) path.push(curr);
    cout << path.size() << '\n';
    for (; !path.empty(); path.pop()) cout << path.top() << ' ';
}