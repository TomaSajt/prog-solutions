#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

vector<int> parent, depth, cnt;
int max_cnt = 1;

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (depth[u] < depth[v]) swap(u, v);
    parent[v] = u;
    if (depth[u] == depth[v]) depth[u]++;
    cnt[u] += cnt[v];
    max_cnt = max(max_cnt, cnt[u]);
}

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);
    depth.resize(n + 1, 1);
    cnt.resize(n + 1, 1);
    int c = n;
    while (m--) {
        int u, v;
        cin >> u >> v;
        if (find(u) != find(v)) merge(u, v), c--;
        cout << c << ' ' << max_cnt << '\n';
    }
}