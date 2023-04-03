#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll, int> edge;

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(2 * n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ w, v });
        g[u + n].push_back({ w, v + n });
        g[u].push_back({ w / 2, v + n });
    }
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    vector<ll> dist(2 * n + 1, LLONG_MAX / 2);
    dist[1] = 0;
    pq.push({ 0,1 });
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (u == 2 * n) break;
        if (d != dist[u]) continue;
        for (auto& [w, v] : g[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v],v });
            }
        }
    }
    cout << dist[2 * n];
}