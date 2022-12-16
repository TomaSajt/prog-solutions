#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g;
vector<int> supply;
vector<bool> marked;
vector<long long> tot;
vector<int> res;

void dfs1(int u) {
    if (g[u].empty()) {
        marked[u] = 1;
        tot[u] = supply[u];
        return;
    }
    tot[u] = 0;
    for (auto v : g[u]) {
        dfs1(v);
        tot[u] += tot[v];
    }
    if (tot[u] < supply[u]) {
        marked[u] = 1;
        tot[u] = supply[u];
    }
}

void dfs2(int u) {
    if (marked[u]) {
        res.push_back(u);
        return;
    }
    for (auto v : g[u]) dfs2(v);
}

int main() {
    speed;
    int n;
    cin >> n;
    g.resize(n + 1);
    marked.resize(n + 1);
    tot.resize(n + 1);
    supply.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> supply[i];
    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        g[a].push_back(i);
    }
    dfs1(1);
    dfs2(1);
    cout << tot[1] << '\n' << res.size() << '\n';
    for (auto u : res) cout << u << ' ';

}