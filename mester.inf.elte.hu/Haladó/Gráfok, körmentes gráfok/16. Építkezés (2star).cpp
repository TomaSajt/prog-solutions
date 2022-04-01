#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;
int n, m, a, b;

vector<vector<int>> g;
vector<int> befok;
vector<bool> vis;
vector<int> order;
int ac = 0;

void dfs(int u) {
    vis[u] = true;
    order.pb(u);
    bool fa = false;
    bool fb = false;
    for (int v : g[u]) {
        befok[v]--;
        if (v == a) fa = true;
        else if (v == b) fb = true;
    }
    if (fa)ac++;
    if (fb && befok[b] == 0 && !vis[b]) {
        dfs(b);
    }
    for (int v : g[u]) {
        if (befok[v] != 0 || vis[v] || v == a || v == b) continue;
        dfs(v);
    }
    if (fa && ac == 1 && befok[a] == 0 && !vis[a]) {
        dfs(a);
    }
    if (fa)ac--;
}

int main() {
    speed;
    cin >> n >> m >> a >> b;
    g.resize(n + 1);
    vis.resize(n + 1);
    befok.resize(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        befok[v]++;
    }
    for (int i = 1;i <= n;i++) {
        if (!vis[i] && befok[i] == 0) {
            dfs(i);
        }
    }
    //for (auto& i : order) cout << i << " ";
    cout << find(order.begin(), order.end(), b) - find(order.begin(), order.end(), a) - 1 << endl;



}