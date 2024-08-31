#include <bits/stdc++.h>
#define speed              \
  ios::sync_with_stdio(0); \
  cin.tie(0)
using namespace std;

vector<vector<int>> g, gt;
vector<int> ord, cid;
vector<bool> vis;
int t = 0;

void dfs1(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  for (int v : g[u]) dfs1(v);
  ord.push_back(u);
}

void dfs2(int u) {
  if (vis[u]) return;
  vis[u] = 1;
  cid[u] = t;
  for (int v : gt[u]) dfs2(v);
}

int main() {
  speed;
  int n, m;
  cin >> m >> n;
  g.resize(2 * n);
  gt.resize(2 * n);
  vis.resize(2 * n);
  cid.resize(2 * n);
  while (m--) {
    char su, sv;
    int u, v;
    cin >> su >> u >> sv >> v;
    u = 2 * u + (su == '-') - 2;
    v = 2 * v + (sv == '-') - 2;
    g[u ^ 1].push_back(v);
    g[v ^ 1].push_back(u);
    gt[v].push_back(u ^ 1);
    gt[u].push_back(v ^ 1);
  }
  for (int i = 0; i < 2 * n; i++) dfs1(i);
  reverse(ord.begin(), ord.end());
  vis.assign(2 * n, 0);
  for (int u : ord) {
    if (vis[u]) continue;
    dfs2(u);
    t++;
  }
  for (int i = 0; i < 2 * n; i += 2) {
    if (cid[i] != cid[i + 1]) continue;
    cout << "IMPOSSIBLE";
    return 0;
  }
  for (int i = 0; i < 2 * n; i += 2) cout << "+-"[cid[i] < cid[i + 1]] << ' ';
}
