/*
25/100
*/
#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    ll n, m, k, si;
    cin >> n >> m >> k;
    for (int i = 0;i < k;i++) {
        cin >> si;
    }
    vector<vector<pair<ll, ll>>> g(n);
    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].pb({ w, v });
        g[v].pb({ w, u });
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(n, LLONG_MAX);
    vector<ll> parent(n, -1);
    pq.push({ 0, 0 });
    dist[0] = 0;
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        if (u == n) break;
        for (auto& e : g[u]) {
            ll v = e.second;
            ll w = e.first;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({ dist[v], v });
            }
        }
    }
    cout << dist[n - 1] << endl;
    return 0;
}