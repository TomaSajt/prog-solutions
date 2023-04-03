#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

vector<int> parent, depth;

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (depth[u] < depth[v]) swap(u, v);
    parent[v] = u;
    if (depth[u] == depth[v]) depth[u]++;
}

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);
    depth.resize(n + 1, 1);
    vector<pair<int, pair<int, int>>> edges(m);
    for (auto& [w, p] : edges) cin >> p.first >> p.second >> w;
    sort(edges.begin(), edges.end());
    ll cost = 0;
    int c = 0;
    for (auto& [w, p] : edges) {
        auto& [u, v] = p;
        if (find(u) != find(v)) {
            merge(u, v);
            cost += w;
            c++;
        }
    }
    if (c != n - 1) cout << "IMPOSSIBLE";
    else cout << cost;
}