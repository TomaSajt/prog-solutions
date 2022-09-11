#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

vector<int> costs, ord;
vector<bool> vis;
vector<vector<int>> g, gt, comps;

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
    }
    ord.push_back(u);
}

void dfs2(int u) {
    vis[u] = 1;
    comps.back().push_back(u);
    for (int v : gt[u]) {
        if (!vis[v]) dfs2(v);
    }
}

int main() {
    speed;
    int n, m;
    cin >> n;

    g.resize(n + 1);
    gt.resize(n + 1);
    costs.resize(n + 1);
    vis.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> costs[i];
    cin >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    
    reverse(ord.begin(), ord.end());
    vis.assign(n + 1, 0);

    for (int i : ord) {
        if (!vis[i]) {
            comps.emplace_back();
            dfs2(i);
        }
    }

    ll sum = 0;
    ll res = 1;
    for (auto& comp : comps) {
        ll val = costs[*min_element(comp.begin(), comp.end(), [&](int a, int b) {return costs[a] < costs[b]; })];
        ll c = count_if(comp.begin(), comp.end(), [&](int a) {return costs[a] == val; });
        sum += val;
        res *= c;
        res %= MOD;
    }

    cout << sum << ' ' << res << endl;
}