#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> capacity;
vector<int> parent;

int augment(int s, int t) {
  parent.assign(n + 1, 0);
  queue<pair<int, int>> q;
  q.push({s, INT_MAX});
  parent[s] = s;
  while (!q.empty()) {
    auto [u, flow] = q.front();
    q.pop();
    for (int v = 1; v <= n; v++) {
      if (!capacity[u][v] || parent[v]) continue;
      parent[v] = u;
      int new_flow = min(flow, capacity[u][v]);
      if (v == t) return new_flow;
      q.push({v, new_flow});
    }
  }
  return 0;
}

vector<bool> s_comp;
void explore(int u) {
  if (s_comp[u]) return;
  s_comp[u] = 1;
  for (int v = 1; v <= n; v++) {
    if (capacity[u][v]) explore(v);
  }
}

int main() {
  cin >> n >> m;

  s_comp.resize(n + 1);
  capacity.resize(n + 1, vector<int>(n + 1));
  while (m--) {
    int a, b;
    cin >> a >> b;
    capacity[a][b]++;
    capacity[b][a]++;
  }

  int res = 0;
  while (true) {
    int flow = augment(1, n);
    if (flow == 0) break;
    int u = n;
    res += flow;
    while (u != 1) {
      int v = parent[u];
      capacity[v][u] -= flow;
      capacity[u][v] += flow;
      u = v;
    }
  }

  explore(1);

  cout << res << '\n';
  for (int u = 1; u <= n; u++) {
    for (int v = 1; v <= n; v++) {
      if (s_comp[u] && !s_comp[v] && capacity[v][u] != 0) cout << u << ' ' << v << '\n';
    }
  }
}
