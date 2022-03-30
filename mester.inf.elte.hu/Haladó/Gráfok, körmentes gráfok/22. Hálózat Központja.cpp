#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> dist(n + 1, -1);
    for (int i = 1;i <= n - 1;i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    queue<int> q;
    for (int i = 1;i <= n;i++) {
        if (g[i].size() <= 1) {
            q.push(i);
            dist[i] = 0;
            break;
        }
    }
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int nei : g[curr]) {
            if (dist[nei] != -1) continue;
            dist[nei] = dist[curr] + 1;
            q.push(nei);
        }
    }
    int res = max_element(dist.begin(), dist.end()) - dist.begin();
    q.push(res);
    dist.assign(n + 1, -1);
    dist[res] = 0;
    vector<int> parent(n + 1, -1);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int nei : g[curr]) {
            if (dist[nei] != -1) continue;
            dist[nei] = dist[curr] + 1;
            q.push(nei);
            parent[nei] = curr;
        }
    }
    int other = max_element(dist.begin(), dist.end()) - dist.begin();
    int curr = other;
    for (int i = 0;i < dist[other] / 2;i++) curr = parent[curr];
    if (dist[other] % 2 != 0 && curr > parent[curr]) curr = parent[curr];
    cout << curr << endl;
}