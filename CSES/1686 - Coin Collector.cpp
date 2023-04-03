#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

vector<vector<int>> g, gt, scc_g, scc_gt;
vector<int> ord, ids;
vector<ll> coins, scc_coins, scc_coins_acc;
vector<bool> vis;

int curr_id = -1;
void dfs(vector<vector<int>>& gr, int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : gr[u]) dfs(gr, v);
    ord.push_back(u);
}
void dfs2(int u) {
    if (vis[u]) {
        if (ids[u] != curr_id) {
            scc_g[ids[u]].push_back(curr_id);
            scc_gt[curr_id].push_back(ids[u]);
        }
        return;
    }
    vis[u] = 1;
    ids[u] = curr_id;
    scc_coins[curr_id] += coins[u];
    for (int v : gt[u]) dfs2(v);
}
int main() {
    speed;
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    gt.resize(n + 1);
    vis.resize(n + 1);
    ids.resize(n + 1);
    coins.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> coins[i];
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) dfs(g, i);
    reverse(ord.begin(), ord.end());
    vis.assign(n + 1, 0);
    for (int u : ord) {
        if (vis[u]) continue;
        scc_g.emplace_back();
        scc_gt.emplace_back();
        scc_coins.push_back(0);
        curr_id++;
        dfs2(u);
    }
    int l = curr_id + 1;
    scc_coins_acc.resize(l, 0);
    vis.assign(l, 0);
    ord.clear();
    for (int i = 0; i < l; i++) dfs(scc_gt, i);
    reverse(ord.begin(), ord.end());
    for (int u : ord) {
        for (int v : scc_g[u]) scc_coins_acc[u] = max(scc_coins_acc[u], scc_coins_acc[v]);
        scc_coins_acc[u] += scc_coins[u];
    }
    cout << *max_element(scc_coins_acc.begin(), scc_coins_acc.end());
}