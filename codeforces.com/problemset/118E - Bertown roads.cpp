#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
#define int long long


vector<vector<pair<int, int>>> g;
vector<int> d, l;
vector<pair<int, int>> edges;
int t = 0;

void dfs(int u, int p) {
    l[u] = d[u] = ++t;
    for (auto& [v, eid] : g[u]) {
        if (v == p) continue;
        if (d[v]) {  //visszaél
            l[u] = min(l[u], d[v]);
        }
        else { //faél
            dfs(v, u);
            l[u] = min(l[u], l[v]);
            if (l[v] > d[u]) { //ha nem tud szülőhöz, vagy annál közelebb jutni a gyökérhez, akkor ott hídél
                cout << "0\n";
                exit(0);
            }
        }
        if (edges[eid].first == -1) edges[eid] = { u,v };
    }
}



#undef int
int main() {
#define int long long
    speed;
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    l.resize(n + 1);
    d.resize(n + 1);
    edges.resize(m, { -1,-1 });
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].pb({ v,m });
        g[v].pb({ u,m });
    }
    dfs(1, -1);

    for (auto& [u, v] : edges) {
        cout << u << ' ' << v << endl;
    }

}