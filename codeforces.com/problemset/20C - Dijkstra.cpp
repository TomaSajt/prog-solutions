#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

int main() {
    speed;
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n + 1);
    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].pb({ w, v });
        g[v].pb({ w, u });
    }
    priority_queue<pair<ll, ll>> pq;
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<ll> parent(n + 1, -1);
    pq.push({ 0, 1 });
    dist[1] = 0;
    while (!pq.empty()) {
        auto [a, u] = pq.top();
        pq.pop();
        if (u == n) break;
        if (a != -dist[u]) continue;
        for (auto& [w, v] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({ -dist[v], v });
            }
        }
    }
    if (dist[n] == LLONG_MAX) {
        cout << -1 << endl;
        return 0;
    }
    stack<ll> path;
    while (n != -1) {
        path.push(n);
        n = parent[n];
    }
    while (!path.empty()) {
        cout << path.top() << ' '; path.pop();
    }
    return 0;

}
