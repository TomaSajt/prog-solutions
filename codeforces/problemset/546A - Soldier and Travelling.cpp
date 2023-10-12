#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(2 * n + 2);
  vector<vector<int>> capacity(2 * n + 2, vector<int>(2 * n + 2, 0));

  int sum1 = 0, sum2 = 0;

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    sum1 += a;

    g[0].push_back(i);
    g[i].push_back(0);
    capacity[0][i] = a;
  }

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    sum2 += a;

    capacity[i + n][2 * n + 1] = a;
    g[i + n].push_back(2 * n + 1);
    g[2 * n + 1].push_back(i + n);

    g[i].push_back(i + n);
    g[i + n].push_back(i);
    capacity[i][i + n] = INF;
  }

  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;

    g[a].push_back(b + n);
    g[b + n].push_back(a);
    capacity[a][b + n] = INF;

    g[b].push_back(a + n);
    g[a + n].push_back(b);
    capacity[b][a + n] = INF;
  }

  if (sum1 != sum2) {
    cout << "NO";
    return 0;
  }

  int maxflow = 0;

  while (true) {
    queue<pair<int, int>> q;
    vector<int> vis(2 * n + 2, -1);
    q.push({0, INF});
    vis[0] = 0;
    while (!q.empty()) {
      auto [u, w] = q.front();
      q.pop();

      if (u == 2 * n + 1) {
        int p = u;
        while (p != 0) {
          capacity[p][vis[p]] += w;
          capacity[vis[p]][p] -= w;
          p = vis[p];
        }
        maxflow += w;
        break;
      }

      for (int v : g[u]) {
        if (vis[v] != -1 || capacity[u][v] == 0) continue;
        vis[v] = u;
        q.push({v, min(w, capacity[u][v])});
      }
    }

    if (vis[2 * n + 1] == -1) break;
  }

  if (maxflow != sum1) {
    cout << "NO";
    return 0;
  }

  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << capacity[j + n][i] << " ";
    }
    cout << '\n';
  }
}
