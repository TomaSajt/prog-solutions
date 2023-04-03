#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<bool> isodd;
queue<int> q;

int main() {
    speed;
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        g.assign(n + 1, {});
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        vis.assign(n + 1, 0);
        isodd.assign(n + 1, 0);
        vis[1] = 1;
        q.push(1);
        int odds = 0;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            odds += isodd[curr];
            for (int nei : g[curr]) {
                if (vis[nei]) continue;
                vis[nei] = 1;
                isodd[nei] = !isodd[curr];
                q.push(nei);
            }
        }
        bool r = odds <= n / 2;
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (isodd[i] == r) c++;
        }
        cout << c << endl;
        for (int i = 1; i <= n; i++) {
            if (isodd[i] == r) cout << i << ' ';
        }
        cout << endl;
    }
}