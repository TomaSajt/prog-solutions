#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> dist(n + 1, -1);
    for (int i = 1;i <= n - 1;i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int nei : g[curr]) {
            if (dist[nei] != -1) continue;
            dist[nei] = dist[curr] + 1;
            q.push(nei);
        }
    }
    //This is one of the farthest points from the root
    int res = max_element(dist.begin(), dist.end()) - dist.begin();
    q.push(res);
    dist.assign(n + 1, -1);
    dist[res] = 0;
    vector<int> parent(n + 1, -1);
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int nei : g[curr]) {
            if (dist[nei] != -1) continue;
            dist[nei] = dist[curr] + 1;
            q.push(nei);
            parent[nei] = curr;
        }
    }
    //Find the farthest point from the pervious farthes point
    //The path from those two points will have the root exactly in the middle
    int other = max_element(dist.begin(), dist.end()) - dist.begin();
    int curr = other;
    for (int i = 0;i < dist[other] / 2;i++) curr = parent[curr];
    //If there are two middle nodes, choose the lower index
    if (dist[other] % 2 != 0 && curr > parent[curr]) curr = parent[curr];
    cout << curr << endl;
}