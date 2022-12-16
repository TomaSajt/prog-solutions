

 // This code doesn't work yet


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
    vector<bool> used(m);
    for (auto& [w, p] : edges) cin >> p.first >> p.second >> w;
    sort(edges.rbegin(), edges.rend());
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        auto& [w, p] = edges[i];
        auto& [u, v] = p;
        if (find(u) != find(v)) {
            merge(u, v);
            sum += w;
            used[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) cout << parent[i] << ' ';
    cout << endl;
    vector<bool> extra(n + 1);
    for (int i = 0; i < m; i++) {
        if (used[i]) continue;
        auto& [w, p] = edges[i];
        auto& [u, v] = p;
        if (extra[find(u)]) continue;
        sum += w;
        extra[find(u)] = 1;
    }
    cout << sum;
}