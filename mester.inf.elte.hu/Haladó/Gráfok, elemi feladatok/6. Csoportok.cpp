// 65/100 - Probably something stupid

#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

vector<vector<int>> groups;
vector<vector<int>> g;
vector<bool> vis;

void dfs(int vertex) {
    vis[vertex] = 1;
    groups.back().pb(vertex);
    for (int nei : g[vertex]) {
        if (vis[nei]) continue;
        dfs(nei);
    }
}

int main() {
    speed;
    int n;
    cin >> n;
    g.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int m = 0;
        int jm = 0;
        for (int j = 1; j <= n; j++) {
            int v;
            cin >> v;
            if (v > m) {
                m = v;
                jm = j;
            }
        }
        if (jm > 0) {
            g[i].pb(jm);
            g[jm].pb(i);
        }
    }
    vis.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        groups.pb({});
        dfs(i);
    }
    cout << groups.size() << '\n';
    for (auto& group : groups) {
        for (int i : group) cout << i << " ";
        cout << '\n';
    }
}