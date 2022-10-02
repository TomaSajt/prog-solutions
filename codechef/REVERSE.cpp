#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int big = 1e6;
int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1), gt(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }
    deque<int> dq;
    vector<int> dist(n + 1, big);
    dist[1] = 0;
    dq.push_back(1);
    while (!dq.empty()) {
        int u = dq.back(); dq.pop_back();
        if (u == n) {
            cout << dist[u];
            return 0;
        }
        for (int v : g[u]) {
            int d = dist[u];
            if (dist[v] > d) {
                dist[v] = d;
                dq.push_back(v);
            }
        }
        for (int v : gt[u]) {
            int d = dist[u] + 1;
            if (dist[v] > d) {
                dist[v] = d;
                dq.push_front(v);
            }
        }
    }
    cout << "-1";
}