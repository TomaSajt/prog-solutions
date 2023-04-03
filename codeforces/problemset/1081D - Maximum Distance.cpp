#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
vector<int> par, dep, cnt;

int find(int u) {
    return u == par[u] ? u : par[u] = find(par[u]);
}

bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return 0;
    if (dep[u] < dep[v]) swap(u, v);
    if (dep[u] == dep[v]) dep[u]++;
    par[v] = u;
    cnt[u] += cnt[v];
    return 1;
}

int main() {
    speed;
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(k);
    vector<pair<int, pair<int, int>>> edges(m);
    for (auto& a : x) cin >> a;
    for (auto& [w, e] : edges) cin >> e.first >> e.second >> w;
    par.resize(n + 1);
    dep.resize(n + 1, 1);
    cnt.resize(n + 1, 0);
    sort(edges.begin(), edges.end());
    iota(par.begin(), par.end(), 0);
    for (auto& a : x) cnt[a] = 1;
    for (auto& [w, e] : edges) {
        auto& [u, v] = e;
        if (merge(u, v) && cnt[find(u)] == k) {
            while (k--) cout << w << ' ';
            return 0;
        }
    }
}