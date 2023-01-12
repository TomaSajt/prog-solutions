// 28/100
#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<pair<int, int>>> g;
vector<bool> vis;
vector<int> xor_to_root;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto& [v, w] : g[u]) {
        xor_to_root[v] = xor_to_root[u] ^ w;
        dfs(v);
    }
};

int xor_between(int a, int b) {
    return xor_to_root[a] ^ xor_to_root[b];
}

int main() {
    speed;
    int n, q;
    cin >> n >> q;
    g.resize(n + 1);
    vis.resize(n + 1);
    xor_to_root.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v,w });
        g[v].push_back({ u,w });
    }
    dfs(1);
    multiset<int> vals;
    set<int> interesting;
    while (q--) {
        int u; cin >> u;
        if (interesting.count(u)) {
            interesting.erase(u);
            for (int v : interesting) {
                vals.erase(vals.find(xor_between(u, v)));
            }
        }
        else {
            for (int v : interesting) {
                vals.insert(xor_between(u, v));
            }
            interesting.insert(u);
        }
        if (interesting.size() < 2) {
            cout << "0\n";
        }
        else {
            cout << *vals.rbegin() << '\n';
        }
    }
}
