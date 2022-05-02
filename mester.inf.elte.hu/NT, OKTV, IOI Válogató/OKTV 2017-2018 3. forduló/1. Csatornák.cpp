#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> dist;
int n, m, a, b, d;


bool test(int k) {
    dist.assign(n + 1, -1);
    dist[a] = 0;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& [v, w] : g[u]) {
            if (w < k || dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    return dist[b] != -1;
}


int main() {
    speed;
    cin >> n >> m >> a >> b;
    g.resize(n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v,w });
        g[v].push_back({ u,w });
    }
    int l = 0, r = 1e9;
    int dd;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (test(mid)) {
            l = mid;
            dd = dist[b];
        }
        else {
            r = mid;
        }
    }
    cout << l << endl << dd << endl;


}