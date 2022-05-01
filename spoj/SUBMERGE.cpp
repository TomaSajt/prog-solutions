#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
#define int long long


vector<vector<int>> g;
vector<int> d, l;
set<int> elvagok;
int t = 0;
int c = 0;



void dfs(int curr, int p) {
    d[curr] = l[curr] = ++t;
    for (auto child : g[curr]) {
        if (child == p) continue;
        if (d[child]) {
            l[curr] = min(l[curr], d[child]);
        }
        else {
            if (curr == 1) c++;
            //fa-él
            dfs(child, curr);
            l[curr] = min(l[curr], l[child]);

            if (curr != 1 && d[curr] <= l[child]) {
                elvagok.insert(curr);
            }
        }
    }

}




#undef int
int main() {
#define int long long
    speed;
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        t = 0;
        c = 0;
        g.assign(n + 1, {});
        d.assign(n + 1, 0);
        l.assign(n + 1, 0);
        elvagok.clear();
        while (m--) {
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(1, -1);
        cout << elvagok.size() + (c > 1) << endl;
    }

}