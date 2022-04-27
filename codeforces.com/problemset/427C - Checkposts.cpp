#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int n;
vector<int> prices, order;
vector<bool> visited;
vector<vector<int>> g, gt, comps;


void dfs1(int u) {
    visited[u] = 1;
    for (int nei : g[u]) if (!visited[nei]) dfs1(nei);
    order.pb(u);
}

void dfs2(int u) {
    visited[u] = 1;
    comps.back().pb(u);
    for (int nei : gt[u]) if (!visited[nei]) dfs2(nei);
}


int main() {
    speed;
    cin >> n;

    g.resize(n + 1);
    gt.resize(n + 1);
    prices.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 1;i <= n;i++) cin >> prices[i];

    int m; cin >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        gt[v].pb(u);
    }

    for (int i = 1;i <= n;i++) if (!visited[i]) dfs1(i);

    reverse(order.begin(), order.end());
    visited.assign(n + 1, 0);

    for (int i : order) if (!visited[i]) comps.pb({}), dfs2(i);

    ll sum = 0;
    ll res = 1;
    for (auto& comp : comps) {
        ll val = prices[*min_element(comp.begin(), comp.end(), [&](int a, int b) {return prices[a] < prices[b];})];
        ll c = count_if(comp.begin(), comp.end(), [&](int a) {return prices[a] == val;});
        sum += val;
        res *= c;
        res %= MOD;
    }

    cout << sum << ' ' << res << endl;
}