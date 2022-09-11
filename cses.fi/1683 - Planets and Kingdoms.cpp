#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g, gt;
vector<int> ord;
vector<bool> vis;
vector<int> ids;

int curr_id = 0;
void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : g[u]) dfs(v);
    ord.push_back(u);
}
void dfs2(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    ids[u] = curr_id;
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
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) dfs(i);
    reverse(ord.begin(), ord.end());
    vis.assign(n + 1, 0);
    for (int u : ord) {
        if (!vis[u]) {
            curr_id++;
            dfs2(u);
        }
    }
    cout << curr_id << '\n';
    for (int i = 1; i <= n; i++) cout << ids[i] << ' ';
    cout << '\n';

}