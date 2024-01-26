#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  int s = 1, t = n;

  vector<vector<int>> capacity(n + 1, vector<int>(n + 1));
  vector<int> par(n + 1);

  while (m--) {
    int u, v;
    cin >> u >> v;
    capacity[u][v]++;
  }

  vector<vector<int>> orig_capacity = capacity;

  auto augment = [&]() {
    queue<int> q;
    q.push(s);
    par.assign(n + 1, -1);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == t) return 1;
      for (int v = 1; v <= n; v++) {
        if (par[v] != -1 || capacity[u][v] == 0) continue;
        par[v] = u;
        q.push(v);
      }
    }
    return 0;
  };

  int path_cnt = 0;
  while (augment()) {
    path_cnt++;
    int v = t;
    while (v != s) {
      int u = par[v];
      capacity[u][v]--;
      capacity[v][u]++;
      v = u;
    }
  }

  cout << path_cnt << '\n';
  while (path_cnt--) {
    vector<int> path = {s};
    int u = s;
    while (u != t) {
      bool sanity_check = false;
      for (int v = 1; v <= n; v++) {
        if (capacity[u][v] == 0 && capacity[u][v] != orig_capacity[u][v]) {
          capacity[u][v] = 1; // prevent other paths from using this edge
          u = v;
          path.push_back(v);
          sanity_check = true;
          break;
        }
      }
      if (!sanity_check) cout << "HELL NAW" << 1 / 0;
    }

    cout << path.size() << '\n';
    for (int u : path) cout << u << ' ';
    cout << '\n';
  }
}
