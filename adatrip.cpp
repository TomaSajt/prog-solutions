#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF (INT_MAX / 2)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> g(n + 1);
    vector<pair<int, int>> qmem(n + 1, { -1,-1 });
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({ w,v });
        g[v].pb({ w,u });
    }
    vector<int> dist;
    vector<int> vis;

    while (q--) {
        dist.assign(n + 1, INF);
        vis.assign(n + 1, false);
        int c;
        cin >> c;
        if (qmem[c].first != -1) {
            cout << qmem[c].first << " " << qmem[c].second << endl;
            continue;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>>>> q;
        q.push({ 0,c });
        dist[c] = 0;
        while (!q.empty()) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (auto& e : g[u]) {
                int v = e.second;
                if (dist[v] > dist[u] + e.first) {
                    dist[v] = dist[u] + e.first;
                    q.push({ dist[v],v });
                }
            }
        }
        int max_dist = 0;
        int max_count = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) continue;
            if (dist[i] > max_dist) {
                max_dist = dist[i];
                max_count = 1;
            }
            else if (dist[i] == max_dist) {
                max_count++;
            }
        }
        qmem[c] = { max_dist, max_count };
        cout << max_dist << " " << max_count << endl;
    }

}