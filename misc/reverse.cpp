#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb({ 0, v });
        g[v].pb({ 1, u });
    }
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, 1 });
    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto& e : g[u]) {
            int v = e.second;
            if (dist[u] + e.first < dist[v]) {
                dist[v] = dist[u] + e.first;
                pq.push({ dist[v], v });
            }
        }
    }
    if(dist[n] == INT_MAX) cout << -1 << endl;
    else cout << dist[n] << endl;
}